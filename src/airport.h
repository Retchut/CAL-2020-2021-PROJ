#ifndef _CAL_AIRPORT_H_
#define _CAL_AIRPORT_H_

#include <vector>
#include <string>

class Connection;

class Airport {
	int id;
    //location
    std::string name;
    double latitude, longitude;
	//weather
    std::string weather;
	//visited -> this is probably getting removed (mário)
	std::vector<Connection> connections;  // list of outgoing edges
	bool visited;          // auxiliary field used by dfs and bfs
	bool processing;       // auxiliary field used by isDAG
	int indegree;          // auxiliary field used by topsort

	void addConnection(const int& conId, Airport *d, double dist);
	bool removeConnectionTo(Airport *d);
    bool removeConnections();
public:
	Airport(const int& id, const double& latitude, const double& longitude);
    Airport(const int& id, const double& latitude, const double& longitude, std::string  name);
	friend class Graph;
    virtual ~Airport();
};

#endif  /*  _CAL_AIRPORT_H_ */