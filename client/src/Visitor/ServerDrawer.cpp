#include "ServerDrawer.hpp"

using std::string;

ServerDrawer::ServerDrawer() : DrawingVisitor()
{
    Socket::createConnexion();
}

ServerDrawer::~ServerDrawer()
{

}

void ServerDrawer::draw(const Circle* circle) const
{
    string request = (string) *circle;
    Socket::sendRequest(request);
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}

void ServerDrawer::draw(const Segment* segment) const
{
    string request = (string) *segment;
    Socket::sendRequest(request);
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}

void ServerDrawer::draw(const Triangle* triangle) const
{
    string request = (string) *triangle;
    Socket::sendRequest(request);
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}

void ServerDrawer::draw(const Polygon* polygon) const
{
    string request = (string) *polygon;
    Socket::sendRequest(request);
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}

/* Could be better to do this
void ServerDrawer::draw(const Shape* shape) const
{
    string request = (string) *shape;
    Socket::sendRequest(request);
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}
*/
