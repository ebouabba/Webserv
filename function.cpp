#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>

void ft_execve(int ac, char **av, char **envp)
{
    std::cout << execve(av[1], av, envp) << std::endl;
    std::cout << "is corect this!" << std::endl;
}

void ft_pipe()
{
    int fd[2];
    pipe(fd);
}

int main(int ac, char **av, char **envp)
{
    ft_pipe();
    struct sockaddr_in address;
    address.sin_port = htons(80);
    std::cout<<address.sin_port<<std::endl;
    return 0;

}