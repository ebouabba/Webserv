#include "Response.hpp"

Response::Response(/* args */)
{
    std::cout<<"url----------------------------------------------url\n";
    std::cout<<this->request.getUrl()<<std::endl;
    std::cout<<"url----------------------------------------------url\n";
}

Response::~Response()
{
}
