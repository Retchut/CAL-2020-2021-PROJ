//
// Created by Mario on 23/05/2021.
//

#ifndef PROJ_CREW_H
#define PROJ_CREW_H

class Airport;
class Plane;

class Crew {
    double hours;       //começa com um valor e decrementa?
    Airport *resting;
    Plane *working;

    public:
        //----Constructor----
        Crew(double hours, Airport *resting);
        Crew(double hours, Plane *working);
        //-------------------

        //----Destructor-----
        virtual ~Crew();
        //-------------------

        //------getters------
        double getHours();
        Airport *getRestingAirport();
        Plane *getWorkingAirport();
        //-------------------

        //------setters------
        //-------------------

        //----other funcs----
        bool isWorking();
        void startWorking(Plane *working);
        void stopWorking(Airport *resting);
        //-------------------
};


#endif //PROJ_CREW_H
