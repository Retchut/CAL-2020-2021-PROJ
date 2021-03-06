#ifndef _CAL_GRAPH_H_
#define _CAL_GRAPH_H_

#include <string>
#include <vector>
#include <set>


#include "passenger.h"
#include "plane.h"

class Airport;

class Connection;


class Graph {
private:
    std::vector<Airport *> airportSet;    // vertex set
    std::vector<Plane *> planeSet;
    std::set<int> connectionIds;

    void generateRandomPlane(const unsigned int& id);

public:
    std::vector<Plane *> getPlanes();

    int getAirportNum() const;

    int getConnectionNum() const;

    Airport *findAirport(const int &id) const;

    bool addAirport(const int &aid, const double &latitude, const double &longitude);

    bool addAirport(const int &aid, const double &latitude, const double &longitude, const std::string &name);

    bool addConnection(const int &conid, const int &source, const int &destination, double dist);

    bool removeConnection(const int &ida, const int &idb);

    void generatePassengers(const int& maxNr);

    void generateReplacementCrews();

    void generatePlanes(size_t planeNum);

    void calculateSteps();

    void printRoutes();

    static void moveAirplaneThroughPath(Plane *plane, std::vector<Connection *> path);

    void cycleUsingDijkstra(Plane* plane, Airport* origin);

    bool removeAirport(const int &aid);

    void viewGraph(const std::string &imgPath, int planeToDisplay) const;

    virtual ~Graph();
};

#endif  /*  _CAL_GRAPH_H_   */