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
        //----Constructor----
        Passenger(Airport *src, Airport *dest, Plane *plane);
        //-------------------

        //----Destructor-----
        virtual ~Passenger();
        //-------------------

        //------getters------
        Airport *getSource() const ;
        Airport *getDestination() const ;
        Plane *getPlane() const ;
        //-------------------

        //------setters------
        void setPlane(Plane *plane);
        //-------------------
};


#endif //PROJ_PASSENGER_H
