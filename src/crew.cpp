//
// Created by Mario on 23/05/2021.
//

#include "crew.h"
#include "airport.h"
#include "plane.h"

//----Constructor----
Crew::Crew(unsigned int id, Airport *resting) : id(id), hours(8.0), resting(resting), working(nullptr) {}

Crew::Crew(unsigned int id, Plane *working) : id(id), hours(8.0), working(working), resting(nullptr) {}
//-------------------


//----Destructor-----
Crew::~Crew() = default;
//-------------------


//------getters------
double Crew::getHours() const {
    return this->hours;
}

Airport *Crew::getRestingAirport() {
    return this->resting;
}

Plane *Crew::getWorkingAirport() {
    return this->working;
}

int Crew::getID() const {
    return this->id;
}
//-------------------


//------setters------
//-------------------


//----other funcs----
bool Crew::isWorking() {
    return (working != nullptr);
}

void Crew::startWorking(Plane *nworking) {
    this->resting = nullptr;
    this->working = nworking;
}

void Crew::stopWorking(Airport *nresting) {
    this->working = nullptr;
    this->resting = nresting;
}
//-------------------