#include "ServerDrawer.hpp"

#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"

using std::string;

ServerDrawer::ServerDrawer() : DrawingVisitor()
{
    Socket::createConnexion();
}

ServerDrawer::~ServerDrawer()
{

}

void ServerDrawer::draw(const Circle* circle)
{
    this->draw( (Shape*) circle);
}

void ServerDrawer::draw(const Segment* segment)
{
    this->draw( (Shape*) segment);
}

void ServerDrawer::draw(const Triangle* triangle)
{
    this->draw( (Shape*) triangle);
}

void ServerDrawer::draw(const Polygon* polygon)
{
    this->draw( (Shape*) polygon);
}

void ServerDrawer::draw(const Shape *shape)
{
    string request = (string) *shape;
    Socket::sendRequest(request + "\n");
    // Prints the message received from the server.
    cout << Socket::receiveData() << endl;
}
