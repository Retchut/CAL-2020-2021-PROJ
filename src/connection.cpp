#include "connection.h"

Connection::Connection(const unsigned int &id, Airport *o, Airport *d, double dist) : id(id), orig(o), dest(d), distance(dist) {}

Airport *Connection::getOrigin() const { return this->orig; }

Airport *Connection::getDestination() const { return this->dest; }

unsigned Connection::getId() const { return this->id; }

double Connection::getDistance() const { return this->distance; }

bool Connection::operator<(const Connection &o) {
    return this->distance < o.getDistance();
}
