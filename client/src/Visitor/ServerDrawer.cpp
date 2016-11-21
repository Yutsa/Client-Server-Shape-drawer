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
    this->draw( (Shape*) circle);
}

void ServerDrawer::draw(const Segment* segment) const
{
    this->draw( (Shape*) segment);
}

void ServerDrawer::draw(const Triangle* triangle) const
{
    this->draw( (Shape*) triangle);
}

void ServerDrawer::draw(const Polygon* polygon) const
{
    this->draw( (Shape*) polygon);
}

void ServerDrawer::draw(const Shape *shape) const
{
    string request = (string) *shape;
    Socket::sendRequest(request + "\n");
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}
