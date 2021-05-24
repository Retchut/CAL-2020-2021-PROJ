#include "connection.h"

Connection::Connection(const int &id, Airport *o, Airport *d, double dist) : id(id), orig(o), dest(d), distance(dist) {}

Airport *Connection::getOrigin() const { return this->orig; }

Airport *Connection::getDestination() const { return this->dest; }

double Connection::getDistance() const { return this->distance; }
