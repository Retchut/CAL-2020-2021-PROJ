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
    double speed;
    double currFuel;
    double maxFuel;
    std::vector<Passenger *> currPas;
    unsigned int maxPas;
    Crew *crew;

    public:
        Plane(Airport *src, double speed, double currFuel, double maxFuel, std::vector<Passenger *> currPas, unsigned int maxPas, Crew *crew);
};


#endif //PROJ_PLANE_H
