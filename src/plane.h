#ifndef PROJ_PLANE_H
#define PROJ_PLANE_H

#include <vector>
#include <set>

#include "crew.h"

class Airport;
class Connection;
class Passenger;
class Crew;

class Plane {
    unsigned int id;
    Airport *src;
    Airport *curr;
    double speed;

    double fuelConsump; // l/km
    double maxFuel;
    std::vector<Passenger *> currPas;
    unsigned int maxPas;
    Crew* crew;
    std::vector<Airport *> visited;
    std::vector<Connection *> route;
    bool arrived;
    size_t airportNumber;

public:
    //----Constructor----
    Plane(unsigned int id, Airport *src, double speed, double fuelConsump, double maxFuel, unsigned int maxPas, Crew *crew, size_t airportNum);
    //-------------------

    //----Destructor-----
    virtual ~Plane();
    //-------------------

    //------getters------
    Airport *getSourceAirport() const;

    Airport *getCurrentAirport() const;

    std::vector<Connection *> getRoute() const;

    double getSpeed() const;

    double getFuelConsumption() const;

    double getMaxFuel() const;

    bool hasArrived() const;

    std::vector<Passenger *> *getCurrentPassengers();

    // get passengers

    unsigned int getMaxPassengers() const;

    Crew *getCrew() const;
    //-------------------

    //------setters------
    void setCrew(Crew* newCrew);
    void setArrived(bool val, unsigned int &activePlanes);
    //-------------------

    //----other funcs----
    double calculateConsumption(const Connection &c) const;

    bool canMoveThrough(const Connection &c);

    bool canReplaceCrew();

    void replaceCrew();

    void traverseEdge(Connection *toTraverse);

    void visitAirport(Airport *next);

    void dropOffPassengers();

    Connection* calculateBestConnection();

    void movePlane(Connection *toTraverse);

    bool nextStep(unsigned int &activePlanes);

    void printRoute();

    //functions to add and remove passengers
    bool addPassenger(Passenger *passenger);

    bool removePassenger(Passenger *passenger);
    //-------------------
};


#endif //PROJ_PLANE_H
