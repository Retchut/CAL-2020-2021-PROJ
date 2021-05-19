#include "graph.h"

#include "airport.h"

int Graph::getAirportNum() const {
	return airportSet.size();
}

/*
 * Auxiliary function to find an airport with a given location.
 */
Airport * Graph::findAirport(std::string l) const {
	for (auto a : airportSet)
		if (a->location == l)
			return a;
	return NULL;
}

/*
 *  Adds an airport with a given location to a graph (this).
 *  Returns true if successful, and false if an Airport with that content already exists.
 */
bool Graph::addAirport(std::string l, std::string w) {
    if(findAirport(l) == NULL){
        airportSet.push_back(new Airport(l, w));
        return true;
    }
    return false;
}

/*
 * Removes a Connection from a graph (this), starting at ls and ending at ld.
 * The Connection is identified by its origin and ending locations.
 * Returns true if successful, and false if such Airport does not exist.
 */
bool Graph::removeConnection(std::string ls, std::string ld) {
    auto a1 = findAirport(ls);
    auto a2 = findAirport(ld);
    if(a1 == NULL || a2 == NULL)
        return false;
    return a1->removeConnectionTo(a2);
}

/*
 * Adds a Connection to a graph (this), from the airport at l origin
 * to the airport at d destination, with distance dist.
 * Returns true if successful, and false if either of the source or
 * destination Airports do not exist.
 */
bool Graph::addConnection(std::string l, std::string d, double dist) {
    auto a1 = findAirport(l);
    auto a2 = findAirport(d);
    if(a1 == NULL || a2 == NULL)
        return false;
    a1->addConnection(a2, dist);
    return true;
}

/*
 *  Removes an Airport at a given location l from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
bool Graph::removeAirport(std::string l) {
    Airport *a = findAirport(l);
    if(a == NULL)
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
