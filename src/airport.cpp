#include "airport.h"

#include <utility>

#include "connection.h"


//----Constructor----
Airport::Airport(const int &id, const double &latitude, const double &longitude) : id(id), latitude(latitude),
                                                                                   longitude(longitude), visited(false),
                                                                                   processing(false), indegree(0),
                                                                                   replCrew(nullptr) {}

Airport::Airport(const int &id, const double &latitude, const double &longitude, std::string name) : id(id),
                                                                                                     name(std::move(
                                                                                                             name)),
                                                                                                     latitude(latitude),
                                                                                                     longitude(
                                                                                                             longitude),
                                                                                                     visited(false),
                                                                                                     processing(false),
                                                                                                     indegree(0),
                                                                                                     replCrew(nullptr) {}
//-------------------


//----Destructor-----
Airport::~Airport() {
    connections.clear();
}
//-------------------


/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Airport::addConnection(const int &conId, Airport *d, double dist) {
    for (auto c : this->connections) {
        if (c.dest == d)
            return;     //already existsa
    }
    this->connections.emplace_back(Connection(conId, this, d, dist));
}

/*
 * Auxiliary function to remove an outgoing connection (with a given destination (d))
 * from an airport (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Airport::removeConnectionTo(Airport *d) {
    for (auto it = this->connections.begin(); it != this->connections.end(); it++) {
        if ((*it).dest == d) {
            this->connections.erase(it);
            return true;
        }
    }
    return false;
}

/*
 * Auxiliary function to remove all connections from this Airport
 * Returns true if successful, and false
 */
bool Airport::removeConnections() {
    this->connections.clear();
    return this->connections.empty();
}


//------getters------
Crew *Airport::getReplacementCrew() { return this->replCrew; }

int Airport::getId() {return this->id;}
//-------------------

//------setters------
void Airport::setReplacementCrew(Crew *newRepl) {
    this->replCrew = newRepl;
}

void Airport::generatePassengers(const int &nr, const std::vector<Airport *>& airports) {
    for(int i = 0; i < rand() % nr; i++){
        Airport* dest = airports.at(rand()%airports.size());
        if(dest == this){
            i--;
            continue;
        }
        Passenger a = Passenger(this, dest, nullptr);
        passengers.emplace_back(a);
    }
}
//-------------------

//----other funcs----
//-------------------

void Airport::embark(Plane *plane, Passenger passenger) {
    if(plane->addPassenger(passenger)){
        for(auto it = this->passengers.begin(); it != this->passengers.end();it++){
            if(*it == passenger){
                this->passengers.erase(it);
                return;
            }
        }
    }
}

void Airport::disembark(Plane *plane, Passenger passenger) {
    if(plane->removePassenger(passenger) && passenger.getDestination()->getId() != this->id)
        this->passengers.push_back(passenger);
}
