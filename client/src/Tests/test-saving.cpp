

/* getenv example: getting path */
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main ()
{
    char* pPath;
    string prout = "prout";
    pPath = getenv ("HOME");
    if (pPath!=NULL)
    {
        strcat(pPath, "/");
        strcat(pPath, prout.c_str());
        cout << pPath << endl;
    }
    return 0;
}
