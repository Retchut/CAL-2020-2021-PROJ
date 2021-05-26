#include <algorithm>
#include "plane.h"
#include "airport.h"
#include "connection.h"
#include "passenger.h"
#include "crew.h"


#include <iostream>

//----Constructor----
Plane::Plane(unsigned int id, Airport *src, double speed, double fuelConsump, double maxFuel, unsigned int maxPas,
             Crew *crew, size_t airportNum) :
         id(id),
        src(src),
        speed(speed),
        fuelConsump(
                fuelConsump),
        maxFuel(maxFuel),
        maxPas(maxPas),
        crew(crew),
        arrived(false),
        airportNumber(airportNum){
    this->curr = src;
    this->visited = {};
    this->route = {};
}
//-------------------


//----Destructor-----
Plane::~Plane(){

    /*
    if(this->crew != nullptr){
        delete this->crew;
    }
    */

}
//-------------------


//------getters------
Airport *Plane::getSourceAirport() const { return this->src; }

Airport *Plane::getCurrentAirport() const { return this->curr; }

std::vector<Connection *> Plane::getRoute() const { return this->route; }

double Plane::getSpeed() const { return this->speed; }

double Plane::getFuelConsumption() const { return this->fuelConsump; }

bool Plane::hasArrived() const { return arrived; }

double Plane::getMaxFuel() const { return this->maxFuel; }

std::vector<Passenger> Plane::getCurrentPassengers() const { return this->currPas; }

unsigned int Plane::getMaxPassengers() const { return this->maxPas; }

Crew *Plane::getCrew() const { return this->crew; }
//-------------------


//------setters------
void Plane::setCrew(Crew* newCrew) {
    this->crew = newCrew;
}

void Plane::setArrived(bool val) {
    this->arrived = val;
}
//-------------------


//----other funcs----
void Plane::replaceCrew() {
    Crew *oldCrew = this->crew;
    this->crew = this->curr->getReplacementCrew();
    this->curr->setReplacementCrew(oldCrew);
}

void Plane::traverseEdge(Connection *toTraverse){
    this->route.push_back(toTraverse);
    //this->crew->decrementHours(toTraverse->getDistance() / this->getSpeed());
}

void Plane::visitAirport(Airport *next) {
    this->curr = next;
    this->visited.push_back(next);
}

void Plane::updateCrew() {
    if(this->crew->getHours() <= 0.0 && this->getCurrentAirport()->hasReplacementCrew()){
        Crew *newCrew = this->getCurrentAirport()->getReplacementCrew();
        this->getCurrentAirport()->setReplacementCrew(this->crew);
        this->setCrew(newCrew);
    }
}

void Plane::dropOffPassengers() {
    this->curr->disembark(this);
}

double Plane::calculateConsumption(const Connection &c) const {
    double dist = c.getDistance();
    return fuelConsump * dist;
}

bool Plane::canMoveThrough(const Connection &c) const {
    //TODO: weather makes us return false
    if (!c.getDestination()->getAccessibility())
        return false;

    double h = this->getCrew()->getHours();
    double s = this->getSpeed();
    double dist = c.getDistance();
    if (this->getCrew()->getHours() * this->speed < c.getDistance())
        return false;

    for(Airport* visit : visited){
        if (visit->getId() == c.getDestination()->getId())
            return false;
    }

    return calculateConsumption(c) <= this->maxFuel;
}

Connection *Plane::calculateBestConnection() {
    if(this->visited.size() == this->airportNumber){
        for(auto& c : *(this->curr->getConnections())){
            if(c.getDestination() == this->src)
                return &c;
        }
        return nullptr;
    }

    std::vector<std::pair<Connection *, double>> vals = {};

    //finds route the plane can move through and hasn't traversed
    for (auto& c : *this->curr->getConnections()) {
        double val = 0.0;
        if (canMoveThrough(c)) {
            if (!this->currPas.empty()) {
                for (const auto &pas : this->currPas) {
                    if (pas.getDestination() == c.getDestination())
                        val += 1;
                }
                val = 0.6 * (val / this->currPas.size()) + 0.4 * (0.4 / (c.getDistance() / 100));
            } else {
                val = 1 / c.getDistance();
            }
            vals.emplace_back(std::make_pair(&c, val));
        }
    }

    //descending
    std::sort(vals.begin(), vals.end(), [](std::pair<Connection *, double> a, std::pair<Connection *, double> b) {
        return a.second > b.second;
    });
    return vals.empty() ? nullptr :  vals[0].first;
}

void Plane::movePlane(Connection *toTraverse){
    this->traverseEdge(toTraverse);
    this->visitAirport(toTraverse->getDestination());
}

bool Plane::nextStep() {
    std::cout << this->visited[this->visited.size() - 1]->getId() << "\n";  //debug print
    Connection *c = calculateBestConnection();

    //if we can't directly move anywhere, we use dijkstra to return to the origin
    if(c == nullptr)
        return false;

    movePlane(c);

    //if we could move directly to the plane's source node
    if(c->getDestination() == src){
        arrived = true;
        this->dropOffPassengers();
    }
    //if we moved elsewhere
    else
        curr->updatePassengers(this);
    return true;
}

void Plane::printRoute(){
    std::cout << "Plane " << this->id << ": ";
    for(int i = 0; i < this->visited.size(); i++){
        std::cout << this->visited[i]->getId() << " ";
    }
    std::cout << "\n";
}

// ------------

//---funcs to add and remove passengers
bool Plane::addPassenger(const Passenger &passenger) {
    if (this->currPas.size() > this->maxPas) {
        this->currPas.push_back(passenger);
        return true;
    }
    return false;
}

bool Plane::removePassenger(const Passenger &passenger) {
    for (auto it = this->currPas.begin(); it != this->currPas.end(); it++) {
        if (*it == passenger) {
            this->currPas.erase(it);
            return true;
        }
    }
    return false;
}
//-------------------