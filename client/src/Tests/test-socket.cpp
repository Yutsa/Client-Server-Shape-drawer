#include "../Network/Socket.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    string answer;
    Socket::getInstance();
    Socket::createConnexion();
    Socket::sendRequest("Circle,red,100,100,100\n");
    answer = Socket::receiveData();
    cout << answer << endl;
    return 0;
}