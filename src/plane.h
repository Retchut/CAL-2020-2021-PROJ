#ifndef PROJ_PLANE_H
#define PROJ_PLANE_H

#include <vector>
#include <set>

class Airport;

class Passenger;

class Crew;

class Plane {
    Airport *src;
    Airport *curr;
    double speed;
    double currFuel;
    double maxFuel;
    std::vector<Passenger *> currPas;
    unsigned int maxPas;
    Crew *crew;
    std::vector<Airport *> visited;
    std::set<Passenger> passengers;

public:
    //----Constructor----
    Plane(Airport *src, double speed, double currFuel, double maxFuel, std::vector<Passenger *> currPas,
          unsigned int maxPas, Crew *crew);
    //-------------------

    //----Destructor-----
    virtual ~Plane();
    //-------------------

    //------getters------
    Airport *getSourceAirport() const;

    Airport *getCurrentAirport() const;

    double getSpeed() const;

    double getCurrentFuel() const;

    double getMaxFuel() const;

    // get passengers

    std::vector<Passenger *> getCurrentPassengers() const;

    unsigned int getMaxPassengers() const;

    Crew *getCrew() const;
    //-------------------

    //------setters------
    //add passengers
    //remove passengers
    //-------------------

    //----other funcs----
    void replenishFuel();

    void replaceCrew();

    void visitAirport();
    //functions to add and remove passengers
    //-------------------
};


#endif //PROJ_PLANE_H
