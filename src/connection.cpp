#include "connection.h"

Connection::Connection(const int &id, Airport *o, Airport *d, double dist) : id(id), orig(o), dest(d), distance(dist) {}

Airport *Connection::getOrigin() { return this->orig; }

Airport *Connection::getDestination() { return this->dest; }

double Connection::getDistance() const{ return this->distance; }
