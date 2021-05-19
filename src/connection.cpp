#include "connection.h"

Connection::Connection(Airport *o, Airport *d, double dist): orig(o), dest(d), distance(dist) {}

Airport * Connection::getOrigin(){    return this->orig;  }
Airport * Connection::getDestination(){   return this->dest;  }
double Connection::getDistance(){  return this->distance;   }
