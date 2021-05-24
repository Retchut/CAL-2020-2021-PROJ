#ifndef _CAL_CONNECTION_H_
#define _CAL_CONNECTION_H_

class Airport;

class Connection {
    unsigned int id;
    Airport *orig;    //origin airport
    Airport *dest;     //destination airport
    double distance;      //distance
public:
    Connection(const unsigned int &id, Airport *o, Airport *d, double dist);

    Airport *getOrigin() const;

    Airport *getDestination() const;

    unsigned getId() const;

    double getDistance() const;

    friend class Graph;

    friend class Airport;
};

#endif  /*  _CAL_CONNECTION_H_ */