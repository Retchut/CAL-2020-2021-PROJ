#include "plane.h"
#include "airport.h"
#include "passenger.h"
#include "crew.h"

//----Constructor----
Plane::Plane(Airport *src, double speed, double currFuel, double maxFuel,
             std::vector<Passenger *> currPas, unsigned int maxPas, Crew *crew) : src(src), speed(speed),
                                                                                  currFuel(currFuel),
                                                                                  maxFuel(maxFuel), currPas(currPas),
                                                                                  maxPas(maxPas), crew(crew) {
    this->curr = src;
    this->visited = {};
}
//-------------------


//----Destructor-----
Plane::~Plane() {}
//-------------------


//------getters------
Airport *Plane::getSourceAirport() const { return this->src; }

Airport *Plane::getCurrentAirport() const { return this->curr; }

double Plane::getSpeed() const { return this->speed; }

double Plane::getCurrentFuel() const { return this->currFuel; }

double Plane::getMaxFuel() const { return this->maxFuel; }

std::vector<Passenger> Plane::getCurrentPassengers() const { return this->currPas; }

unsigned int Plane::getMaxPassengers() const { return this->maxPas; }

Crew *Plane::getCrew() const { return this->crew; }
//-------------------


//------setters------
//-------------------


//----other funcs----
void Plane::replenishFuel() {
    this->currFuel = this->maxFuel;
}

void Plane::replaceCrew() {
    Crew *oldCrew = this->crew;
    this->crew = this->curr->getReplacementCrew();
    this->curr->setReplacementCrew(oldCrew);
}

void Plane::visitAirport() {
    this->visited.push_back(this->curr);
}

void Plane::addPassenger(Passenger * passenger) {
    if(this->currPas.size() > this->maxPas)
        this->currPas.push_back(*passenger);
}

void Plane::removePassenger(Passenger *passenger) {
    for(auto it = this->currPas.begin(); it != this->currPas.end();it++){
        if(*it == *passenger){
            this->currPas.erase(it);
            return;
        }
    }
}
//-------------------