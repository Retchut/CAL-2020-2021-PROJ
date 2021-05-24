//
// Created by Mario on 23/05/2021.
//

#include "passenger.h"
#include "airport.h"

int Passenger::idcnt = 1;

//----Constructor----
Passenger::Passenger(Airport *src, Airport *dest, Plane *plane) : id(idcnt), src(src), dest(dest),
                                                                  plane(plane) { idcnt++; }
//-------------------


//----Destructor-----
Passenger::~Passenger() {}
//-------------------


//------getters------
Plane *Passenger::getPlane() const { return this->plane; }

Airport *Passenger::getSource() const { return this->src; }

Airport *Passenger::getDestination() const { return this->dest; }
//-------------------


//------setters------
void Passenger::setPlane(Plane *plane) {
    this->plane = plane;
}

bool Passenger::operator==( const Passenger& a) const {
    return id == a.id;
}
//-------------------