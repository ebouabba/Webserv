#ifndef RESPONSE_HPP
#define RESPONSE_HPP

//    define variables //

// -------  cpp -----//
#include <iostream>

// ------    c   ----//
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>  /* See NOTES */
#include <netinet/in.h> // for type (struct sockaddr_in)
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <map>
#include <sstream>
#include <string>
#include "../request/Prasing_Request.hpp"
#include "../Configfile/Configuration.hpp"

class Response
{
private:
    int status;
    std ::map<std::string, std::string> mymap;
    std::string respons;

public:
    int run_cgi();
    Response();
    Response(Prasing_Request rq, Configuration conf_serv);
    std ::string get_respons();
};
#endif