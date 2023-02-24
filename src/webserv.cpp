#include "../src/webserv.hpp"

#include "response/Response.hpp"
#include "request/Prasing_Request.hpp"

/////////////////////////////////////
//      destructor constructor
/////////////////////////////////////
Webserv::Webserv()
{
}
Webserv::Webserv(int prt, int backlg)
{
    this->port = prt;
    this->backlog = backlg;
}
Webserv::~Webserv()
{
}

/////////////////////////////////////
//      getters and setters
/////////////////////////////////////
int Webserv::getport()
{
    return this->port;
}
void Webserv::setport(int prt)
{
    this->port = prt;
}

int Webserv::getsockfd()
{
    return this->sockfd;
}
void Webserv::setsockfd(int sckfd)
{
    this->sockfd = sckfd;
}
int Webserv::getbacklog()
{
    return this->backlog;
}
void Webserv::setbacklog(int backlog)
{
    this->backlog = backlog;
}

//////////////////////////////////////////
//      member function
////////////////////////////////////////
int Webserv::init_server()
{
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int optval = 1;
    // for solve problem (address already in use)
    if ((setsockopt(this->sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int))) == -1)
    {
        perror("socket error\n");
        return -1;
    }
    if (this->sockfd == -1)
        return msg_error(0);
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(this->port);
    this->serv_addr.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to localhost port 5500
    if (bind(this->sockfd, (struct sockaddr *)(&this->serv_addr), sizeof(this->serv_addr)) == -1)
        return msg_error(1);
    if (listen(this->sockfd, this->backlog) == -1)
        return msg_error(2);
    return 0;
}

std::string ft_read(std::string name)
{
    std::ifstream file(name.c_str());
    std::string line_s;
    std::string line;
    while (getline(file, line))
    {
        line.append("\n");
        line_s += line;
    }
    return line_s;
}

int Webserv::run_server()
{
    std::string response = ft_read("www/index.html");
    char client_msg[4096] = "";
    int client_socket;

    FD_ZERO(&this->stes_write);
    FD_ZERO(&this->stes_read);
    FD_SET(this->sockfd, &this->stes_read);
    FD_SET(this->sockfd, &this->stes_write);
    this->max_fd = this->sockfd;

    while (true)
    {
        printf("------------> wait ....\n");
        int fd_select = select(this->max_fd + 1, &this->stes_read, &this->stes_write, NULL, NULL);
        for (int fd = 0; fd <= this->max_fd; fd++)
        {
            if (FD_ISSET(fd, &this->stes_read))
            {
                if (fd == this->sockfd)
                {
                    client_socket = accept(this->sockfd, NULL, NULL);
                    FD_SET(client_socket, &this->stes_read);
                    FD_SET(client_socket, &this->stes_write);
                    if (client_socket > this->max_fd)
                        this->max_fd = client_socket;
                }
                else
                {
                    recv(fd, client_msg, 4095, 0);

                    std::cout<<"===============================\n\n"<<std::endl;
                    Prasing_Request request(client_msg);
                    std::cout<<request.getUrl()<<std::endl;

                    for (int fd2 = 0; fd2 <= this->max_fd; fd2++)
                    {
                        if (FD_ISSET(fd2, &this->stes_write))
                        {
                            send(fd2, response.c_str(), response.length(), 0);
                            printf("====> %d | %d\n", fd, fd2);
                            close(fd2);
                            FD_CLR(fd2, &this->stes_write);
                        }
                    }
                    close(fd);
                    FD_CLR(fd, &this->stes_read);
                }
            }
        }
    }
    return 0;
}
