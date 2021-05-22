#ifndef _CAL_GRAPH_H_
#define _CAL_GRAPH_H_

#include <string>
#include <vector>

class Airport;
class Connection;

class Graph {
private:
    std::vector<Airport *> airportSet;    // vertex set

public:
    int getAirportNum() const;
    Airport *findAirport(const int& id) const;
	bool addAirport(const int& id, const double& latitude, const double& longitude);
    bool addAirport(const int& id, const double& latitude, const double& longitude, const std::string& name);
	bool addConnection(const int& source, const int& destination, double dist) const;
	bool removeConnection(const int& ida, const int& idb);
	bool removeAirport(const int& id);


    virtual ~Graph();
};

#endif  /*  _CAL_GRAPH_H_   */