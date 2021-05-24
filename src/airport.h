#ifndef _CAL_AIRPORT_H_
#define _CAL_AIRPORT_H_

#include <vector>
#include <string>
#include <set>

#include "passenger.h"
#include "plane.h"

class Connection;
class Passenger;
class Crew;

class Airport {
    int id;
    //location
    std::string name;
    double latitude, longitude;
    //weather
    std::string weather;
    //visited -> this is probably getting removed (mário)
    std::vector<Connection> connections;  // list of outgoing edges
    bool visited;          // auxiliary field used by dfs and bfs
    bool processing;       // auxiliary field used by isDAG
    int indegree;          // auxiliary field used by topsort
    Crew *replCrew;
    std::vector<Passenger> passengers;
    bool accessible = true;

    void addConnection(const int &conId, Airport *d, double dist);

    bool removeConnectionTo(Airport *d);

    bool removeConnections();

public:
    //----Constructor----
    Airport(const int &id, const double &latitude, const double &longitude);

    Airport(const int &id, const double &latitude, const double &longitude, std::string name);
    //-------------------

    friend class Graph;

    //----Destructor-----
    virtual ~Airport();
    //-------------------

    //------getters------
    std::vector<Connection> *getConnections();
    Crew* getReplacementCrew();
    std::vector<Passenger> getPassengers() const;
    int getId();
    bool getAccessibility();
    //-------------------

    //------setters------
    void setReplacementCrew(Crew* newRepl);
    void generatePassengers(const int &nr, const std::vector<Airport *>& airports);
    //-------------------

    //----other funcs----
    void embark(Plane* plane);
    void disembark(Plane* plane);
    void embark(Plane* plane, Passenger passenger);
    void disembark(Plane* plane, Passenger passenger);
    void updatePassengers(Plane* plane);
    //-------------------
};

#endif  /*  _CAL_AIRPORT_H_ */