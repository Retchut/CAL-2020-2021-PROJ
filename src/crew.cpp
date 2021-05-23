//
// Created by Mario on 23/05/2021.
//

#include "crew.h"
#include "airport.h"
#include "plane.h"

Crew::Crew(double hours, Airport *resting){
    this->hours = hours;
    this->resting = resting;
    this->working = NULL;
}

Crew::Crew(double hours, Plane *working){
    this->hours = hours;
    this->working = working;
    this->resting = NULL;
}

double Crew::getHours(){
    return this->hours;
}

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

Airport *Crew::getRestingAirport(){
    return this->resting;
}

Plane *Crew::getWorkingAirport(){
    return this->working;
}