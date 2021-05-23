//
// Created by Mario on 23/05/2021.
//

#ifndef PROJ_PASSENGER_H
#define PROJ_PASSENGER_H

class Airport;
class Plane;

class Passenger {
    Airport *src;
    Airport *dest;
    Plane *plane;
    //identifying data?

    public:
        Passenger(Airport *src, Airport *dest, Plane *plane);
        Plane *getPlane();
};


#endif //PROJ_PASSENGER_H
