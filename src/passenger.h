#ifndef PROJ_PASSENGER_H
#define PROJ_PASSENGER_H

class Airport;

class Plane;



class Passenger {
    static int idcnt;

    int id;
    Airport *src;
    Airport *dest;
    Plane *plane;

public:
    //----Constructor----
    Passenger(Airport *src, Airport *dest, Plane *plane);
    //-------------------

    //----Destructor-----
    virtual ~Passenger();
    //-------------------

    //------getters------
    Airport *getSource() const;

    Airport *getDestination() const;

    Plane *getPlane() const;
    //-------------------

    //------setters------
    void setPlane(Plane *plane);
    //-------------------

   bool operator==( const Passenger& a) const;
};


#endif //PROJ_PASSENGER_H
