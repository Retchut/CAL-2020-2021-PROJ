//
// Created by Mario on 23/05/2021.
//

#include "passenger.h"
#include "airport.h"

Passenger::Passenger(Airport *src, Airport *dest, Plane *plane) {
    this->src = src;
    this->dest = dest;
    this->plane = plane;
}
Plane *Passenger::getPlane(){
    return this->plane;
}