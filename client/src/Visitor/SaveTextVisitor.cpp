#include <iostream>
#include <cstring>
#include "SaveTextVisitor.hpp"

using std::string;

void SaveTextVisitor::save(const Circle *circle,
    const string & filename) const
{
    char* path;
    string textShape = (string) *circle;
    path = getenv("HOME");
    if (path != NULL)
    {
        strcat(pPath, "/");
        strcat(path, filename.c_str());
    }
}
