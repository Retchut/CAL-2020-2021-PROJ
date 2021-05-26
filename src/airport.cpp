#include "airport.h"

#include "connection.h"


//----Constructor----
Airport::Airport(const int &id, const double &latitude, const double &longitude) : id(id), latitude(latitude),
                                                                                   longitude(longitude){
}

Airport::Airport(const int &id, const double &latitude, const double &longitude, std::string name) : id(id),
                                                                                                     name(std::move(
                                                                                                             name)),
                                                                                                     latitude(latitude),
                                                                                                     longitude(
                                                                                                             longitude) {}
//-------------------


//----Destructor-----
Airport::~Airport() {
    connections.clear();
    delete this->replCrew;
    for(auto pass : passengers){
        delete pass;
    }
}
//-------------------


/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Airport::addConnection(const int &conId, Airport *d, double dist) {
    for (auto c : this->connections) {
        if (c.dest == d)
            return;     //already exists
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
std::vector<Connection> *Airport::getConnections() { return &this->connections; }

Crew* Airport::getReplacementCrew() { return this->replCrew; }

int Airport::getId() const {return this->id;}

bool Airport::getAccessibility() const {
    return accessible;
}

std::vector<Passenger *> Airport::getPassengers() const {
    return passengers;
}
//-------------------

//------setters------
void Airport::setReplacementCrew(Crew* newRepl) {
    this->replCrew = newRepl;
    this->replCrew->setHours(0.0);
}

void Airport::generatePassengers(const int &nr, const std::vector<Airport *>& airports) {
    for(int i = 0; i < rand() % nr; i++){
        Airport* dest = airports.at(rand()%airports.size());
        if(dest == this){
            i--;
            continue;
        }
        Passenger *a = new Passenger(this, dest, nullptr);
        passengers.emplace_back(a);
    }
}
//-------------------

//----other funcs----
//-------------------

bool Airport::embark(Plane *plane, Passenger *passenger) {
    if(plane->addPassenger(passenger)){
        for(auto it = this->passengers.begin(); it != this->passengers.end();it++){
            if(*it == passenger){
                this->passengers.erase(it);
                return true;
            }
        }
    }
    return false;
}

void Airport::addPassenger(Passenger *toAdd){
    this->passengers.push_back(toAdd);
}

void Airport::updatePassengers(Plane *plane) {
    auto it = (*plane->getCurrentPassengers()).begin();
    while(it != (*plane->getCurrentPassengers()).end()){
        Passenger *pas = (*it);
        Passenger test = *pas;
        if(pas->getDestination() == this){
            (*it)->setPlane(nullptr);
            it = (*plane->getCurrentPassengers()).erase(it);
        }
        else{
            ++it;
        }
    }

    while(!passengers.empty()){
        //embark as many passengers as we can
        if(!embark(plane, passengers[0])){
            break;
        }
    }
}

bool Airport::hasReplacementCrew(){
    return this->replCrew != nullptr;
}