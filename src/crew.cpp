//
// Created by Mario on 23/05/2021.
//

#include "crew.h"
#include "airport.h"
#include "plane.h"

//----Constructor----
Crew::Crew(double hours, Airport *resting) : hours(hours), resting(resting), working(NULL) {}

Crew::Crew(double hours, Plane *working) : hours(hours), working(working), resting(NULL) {}
//-------------------


//----Destructor-----
Crew::~Crew(){}
//-------------------


//------getters------
double Crew::getHours(){
    return this->hours;
}

Airport * Crew::getRestingAirport(){
    return this->resting;
}

Plane * Crew::getWorkingAirport(){
    return this->working;
}
//-------------------


//------setters------
//-------------------


//----other funcs----
bool Crew::isWorking(){
    return (working != NULL);
}

void Crew::startWorking(Plane *working){
    this->resting = NULL;
    this->working = working;
}
void Crew::stopWorking(Airport *resting){
    this->working = NULL;
    this->resting = resting;
}
//-------------------