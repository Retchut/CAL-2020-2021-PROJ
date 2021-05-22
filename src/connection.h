#ifndef _CAL_CONNECTION_H_
#define _CAL_CONNECTION_H_

class Airport;

class Connection {
	int id;
    Airport * orig;	//origin airport
	Airport * dest;     //destination airport
	double distance;      //distance
public:
	Connection(const int& id, Airport *o, Airport *d, double dist);
	Airport * getOrigin();
	Airport * getDestination();
	double getDistance();
	friend class Graph;
	friend class Airport;
};

#endif  /*  _CAL_CONNECTION_H_ */