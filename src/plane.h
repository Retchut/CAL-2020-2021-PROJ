#ifndef PROJ_PLANE_H
#define PROJ_PLANE_H

#include <vector>
#include <set>

class Airport;
class Connection;
class Passenger;
class Crew;

class Plane {
    Airport *src;
    Airport *curr;
    double speed;
    double fuelConsump; // l/km
    double maxFuel;
    std::vector<Passenger> currPas;
    unsigned int maxPas;
    Crew *crew;
    std::vector<Airport *> visited;

public:
    //----Constructor----
    Plane(Airport *src, double speed, double fuelConsump, double maxFuel, unsigned int maxPas, Crew *crew);
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


    std::vector<Passenger> getCurrentPassengers() const;

    // get passengers

    unsigned int getMaxPassengers() const;

    Crew *getCrew() const;
    //-------------------

    //------setters------
    // add passengers
    // remove passengers
    //-------------------

    //----other funcs----
    double calculateConsumption(const Connection &c) const;

    bool canMoveThrough(const Connection &c) const;

    void replaceCrew();

    void visitAirport(Airport *next);

    void nextStep();

    Connection* calculateBestConnection();


    //functions to add and remove passengers
    bool addPassenger(const Passenger&  passenger);

    bool removePassenger(const Passenger&  passenger);
    //-------------------
};


#endif //PROJ_PLANE_H
