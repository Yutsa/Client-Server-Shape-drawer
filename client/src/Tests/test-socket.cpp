#include "../Network/Socket.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    
    string answer;
    Socket::getInstance();
    Socket::createConnexion();
    Socket::sendRequest("Circle,red,100,100,100\n");
    answer = Socket::receiveData();
    cout << answer << endl;
    return 0;
}
