#ifndef _CAL_GRAPH_H_
#define _CAL_GRAPH_H_

#include <string>
#include <vector>

class Airport;
class Connection;

class Graph {
    std::vector<Airport *> airportSet;    // vertex set

	Airport *findAirport(std::string l) const;
public:
	int getAirportNum() const;
	bool addAirport(std::string l, std::string w);
	bool addConnection(std::string l, std::string d, double dist);
	bool removeConnection(std::string ls, std::string ld);
	bool removeAirport(std::string l);
};

#endif  /*  _CAL_GRAPH_H_   */