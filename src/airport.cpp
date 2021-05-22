#include "airport.h"

#include <utility>

#include "connection.h"

Airport::Airport(const int &id, const double &latitude, const double &longitude) : id(id), latitude(latitude),
                                                                                   longitude(longitude), visited(false),
                                                                                   processing(false), indegree(0) {}

Airport::Airport(const int &id, const double &latitude, const double &longitude, std::string name) : id(id),
                                                                                                     name(std::move(
                                                                                                             name)),
                                                                                                     latitude(latitude),
                                                                                                     longitude(
                                                                                                             longitude),
                                                                                                     visited(false),
                                                                                                     processing(false),
                                                                                                     indegree(0) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Airport::addConnection(Airport *d, double dist) {
    for (auto c : this->connections) {
        if (c.dest == d)
            return;     //already exists
    }
    this->connections.emplace_back(Connection(this, d, dist));
}

/*
 * Auxiliary function to remove an outgoing connection (with a given destination (d))
 * from an airport (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Airport::removeConnectionTo(Airport *d) {
    auto it = this->connections.begin();
    for (it; it != this->connections.end(); it++) {
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

Airport::~Airport() {
    connections.clear();
}
