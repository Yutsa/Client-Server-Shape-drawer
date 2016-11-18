#include "../Network/Socket.hpp"

using std::cout;
using std::endl;

int main()
{
    Socket::getInstance();
    Socket::createConnexion();
    Socket::sendRequest("Circle,red,100,100,100");
    cout << Socket::receiveData() << endl;
    return 0;
}
