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
    //weather   -   not implemented
    std::string weather;
    std::vector<Connection> connections;  // list of outgoing edges
    bool processing;       // auxiliary field used by isDAG
    Crew *replCrew;
    std::vector<Passenger *> passengers;
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
    std::vector<Passenger *> getPassengers() const;
    int getId() const;
    bool getAccessibility() const;
    //-------------------

    //------setters------
    void setReplacementCrew(Crew* newRepl);
    void generatePassengers(const int &nr, const std::vector<Airport *>& airports);
    //-------------------

    //----other funcs----
    void disembark(Plane* plane);
    bool embark(Plane* plane, Passenger *passenger);
    void disembark(Plane* plane, Passenger *passenger);
    void addPassenger(Passenger *toAdd);
    void updatePassengers(Plane* plane);
    bool hasReplacementCrew();
    //-------------------
};

#endif  /*  _CAL_AIRPORT_H_ */