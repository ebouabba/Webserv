
#include "Prasing_Request.hpp"

#include <bits/stdc++.h>

int Prasing_Request::check_first_line(std::string first_line)
{
    std::cout<<"-> "<<first_line<<std::endl;
    this->methode = strtok((char *)first_line.c_str(), " ");
    if (this->methode != "GET" && this->methode != "POST" && this->methode != "DELETE")
    {
        std ::cout << "405 Method Not Allowed" << std::endl;
        status = 405;
        return (0);
    }
    char *urlll = strtok(NULL, " ");
    this->url = urlll;
    std::cout<<this->url<<std::endl;
    if (urlll[0] != '/')
    {
        std ::cout << "400 Bad Request" << std::endl;
        status = 400;
        return (0);
    }
    std ::string htb = strtok(NULL, " ");
    if (htb != "HTTP/1.1")
    {
        std::cout << "505 HTTP Version Not Supported" << std::endl;
        status = 505;
        return (0);
    }
    if (strchr(this->url.c_str(), '?'))
    {
        strtok((char *)this->url.c_str(), "?");
        char *str = strtok(NULL, "?");
        this->budy_url = str;
        // std ::cout << this->budy_url << std::endl;
    }
    return (1);
}

std ::vector<std ::string> split(std::string str, std::string delimiter)
{
    std ::vector<std ::string> v;
    if (!str.empty())
    {
        int start = 0;
        do
        {
            int idx = str.find(delimiter, start);
            if (idx == std ::string::npos)
            {
                break;
            }

            int length = idx - start;
            v.push_back(str.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        v.push_back(str.substr(start));
    }

    return v;
}

void Prasing_Request::prasing_headr(std ::string headrs)
{

    std ::vector<std ::string> res = split(headrs, "\r\n");
    for (int i = 0; i < res.size(); i++)
    {
        std ::string key = res[i].substr(0, res[i].find(":"));
        std ::string value = res[i].substr(res[i].find(" "));
        mymap.insert(std ::pair<std ::string, std::string>(key, value));
    }
    if (status == 200)
    {
        if (this->methode == "POST" && mymap["Content-Type"].empty())
        {
            std ::cout << "error on Content-Type !!!" << std::endl;
            status = 400;
            return;
        }
        if (this->methode == "POST" && (mymap["Content-Length"].empty() || atoi(mymap["Content-Length"].c_str()) < 0))
        {
            std ::cout << "error on Content-Length !!!" << std::endl;
            status = 400;
            return;
        }
        if (mymap["HOST"].empty())
        {
            std ::cout << "error om HOST !!" << std ::endl;
            status = 400;
            return;
        }
        if (atoi(mymap["Content-Length"].c_str()) > 2000)
        {
            std ::cout << "eroore on size Content-Length " << std::endl;
            status = 400;
            return;
        }
    }
}

Prasing_Request::Prasing_Request(std::string requst)
{
    check_first_line(requst.substr(0, requst.find("\n")));
    // prasing_headr(requst.substr(requst.find("\n", requst.length())));
    std::cout << this->url << std::endl;
}

std::string Prasing_Request::getMethode()
{
    return (this->methode);
}
std::string Prasing_Request::getUrl()
{
    return (this->url);
}
std::string Prasing_Request::getBudy_url()
{
    return (this->budy_url);
}
