//
// Created by Mario on 23/05/2021.
//

#ifndef PROJ_PLANE_H
#define PROJ_PLANE_H

#include <vector>

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

    public:
        //----Constructor----
        Plane(Airport *src, double speed, double currFuel, double maxFuel, std::vector<Passenger *> currPas, unsigned int maxPas, Crew *crew);
        //-------------------

        //----Destructor-----
        virtual ~Plane();
        //-------------------

        //------getters------
        Airport *getSourceAirport() const ;
        Airport *getCurrentAirport() const ;
        double getSpeed() const ;
        double getCurrentFuel() const ;
        double getMaxFuel() const ;
        std::vector<Passenger *> getCurrentPassengers() const ;
        unsigned int getMaxPassengers() const ;
        Crew *getCrew() const ;
        //-------------------

        //------setters------
        //-------------------

        //----other funcs----
        void replenishFuel();
        void replaceCrew();
        void visitAirport();
        //functions to add and remove passengers
        //-------------------
};


#endif //PROJ_PLANE_H