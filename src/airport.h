#ifndef _CAL_AIRPORT_H_
#define _CAL_AIRPORT_H_

#include <vector>
#include <string>

class Connection;

class Airport {
	//location
    std::string location;
	//weather
    std::string weather;
	//visited -> this is probably getting removed (mário)
	std::vector<Connection> connections;  // list of outgoing edges
	bool visited;          // auxiliary field used by dfs and bfs
	bool processing;       // auxiliary field used by isDAG
	int indegree;          // auxiliary field used by topsort

	void addConnection(Airport *d, double dist);
	bool removeConnectionTo(Airport *d);
    bool removeConnections();
public:
	Airport(std::string l, std::string w);
	friend class Graph;
};

#endif  /*  _CAL_AIRPORT_H_ */