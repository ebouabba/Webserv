#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <iostream>
#include <fstream>
#include <string>

class Configuration
{
private:
    std::string path_conf;
public:
    Configuration(std::string path);
    Configuration();
    void parsing_Config_file();
    ~Configuration();
};

#endif
