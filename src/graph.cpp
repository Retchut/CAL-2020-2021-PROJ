#include "graph.h"

#include "airport.h"

int Graph::getAirportNum() const {
	return airportSet.size();
}

/*
 * Auxiliary function to find an airport with a given location.
 */
Airport * Graph::findAirport(const int& id) const {
	for (auto a : airportSet)
		if (a->id == id)
			return a;
	return nullptr;
}

/*
 *  Adds an airport with a given location to a graph (this).
 *  Returns true if successful, and false if an Airport with that content already exists.
 */
bool Graph::addAirport(const int& id, const double& latitude, const double& longitude) {
    if(findAirport(id) == nullptr){
        airportSet.push_back(new Airport(id, latitude, longitude));
        return true;
    }
    return false;
}

bool Graph::addAirport(const int& id, const double& latitude, const double& longitude, const std::string& name) {
    if(findAirport(id) == nullptr){
        airportSet.push_back(new Airport(id, latitude, longitude, name));
        return true;
    }
    return false;
}

/*
 * Removes a Connection from a graph (this), starting at ls and ending at ld.
 * The Connection is identified by its origin and ending locations.
 * Returns true if successful, and false if such Airport does not exist.
 */
bool Graph::removeConnection(const int& ida, const int& idb) {
    auto a1 = findAirport(ida);
    auto a2 = findAirport(idb);
    if(a1 == nullptr || a2 == nullptr)
        return false;
    return a1->removeConnectionTo(a2);
}

/*
 * Adds a Connection to a graph (this), from the airport at l origin
 * to the airport at d destination, with distance dist.
 * Returns true if successful, and false if either of the source or
 * destination Airports do not exist.
 */
bool Graph::addConnection(const int& source, const int& destination, double dist = 0.0) const {
    auto a1 = findAirport(source);
    auto a2 = findAirport(destination);
    if(a1 == nullptr || a2 == nullptr)
        return false;
    a1->addConnection(a2, dist);
    return true;
}

/*
 *  Removes an Airport at a given location l from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
bool Graph::removeAirport(const int& id) {
    Airport *a = findAirport(id);
    if(a == nullptr)
        return false;
    for(auto it = airportSet.begin(); it != airportSet.end(); it++){
        if((*it) == a){
            if(!(*it)->removeConnections())
                return false;
            this->airportSet.erase(it);
            return true;
        }
    }
    return false;
}

Graph::~Graph() {
    for(Airport* airport : airportSet){
        delete airport;
    }
}
