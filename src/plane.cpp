//
// Created by Mario on 23/05/2021.
//

#include "plane.h"
#include "passenger.h"
#include "crew.h"

Plane::Plane(Airport *start, double speed, double currFuel, double maxFuel, std::vector<Passenger *> currPas, unsigned int maxPas, Crew *crew){
    this->src = src;
    this->speed = speed;
    this->currFuel = currFuel;
    this->maxFuel = maxFuel;
    this->currPas = currPas;
    this->maxPas = maxPas;
    this->crew = crew;
}