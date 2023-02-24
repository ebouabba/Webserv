#include <iostream>
#include <glob.h>
#include <vector>
using namespace std;

vector<string> globVector(const string &pattern)
{
    glob_t glob_result;
    glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
    vector<string> files;
    for (unsigned int i = 0; i < glob_result.gl_pathc; ++i)
    {
        files.push_back(string(glob_result.gl_pathv[i]));
        std::cout<<files[0]<<std::endl;

    }
    globfree(&glob_result);
    return files;
}

int main()
{
    vector<string> a = globVector("/home/ebouabba/Desktop/Webserv/www");
    return (0);
}