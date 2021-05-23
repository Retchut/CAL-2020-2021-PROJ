//
// Created by Mario on 23/05/2021.
//

#include "passenger.h"
#include "airport.h"

//----Constructor----
Passenger::Passenger(Airport *src, Airport *dest, Plane *plane) : src(src), dest(dest), plane(plane){}
//-------------------


//----Destructor-----
Passenger::~Passenger(){}
//-------------------


//------getters------
Plane * Passenger::getPlane() const {  return this->plane; }
Airport * Passenger::getSource() const {   return this->src;   }
Airport * Passenger::getDestination() const {  return this->dest;  }
//-------------------


//------setters------
void Passenger::setPlane(Plane *plane){
    this->plane = plane;
}
//-------------------