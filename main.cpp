#include "src/webserv.hpp"

#include "src/Configfile/Configuration.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
        exit(1);
    Webserv myserver(8080, 5);
    if (-1 == myserver.init_server())
        return 1;
    myserver.run_server();

    return 0;
}
