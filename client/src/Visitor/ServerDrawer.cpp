#include "ShapeDrawer.hpp"

using std::string;

ServerDrawer::ServerDrawer() : DrawingVisitor()
{
    Socket::createConnexion();
}

void ServerDrawer::draw(Circle* circle)
{
    string request = (string) circle;
    Socket::sendRequest(request);
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}

void ServerDrawer::draw(Segment* segment)
{

}

void ServerDrawer::draw(Triangle* triangle)
{

}

void ServerDrawer::draw(Polygon* polygon)
{

}
