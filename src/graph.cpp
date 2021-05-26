#include "graph.h"

#include "airport.h"
#include "connection.h"
#include "crew.h"
#include "plane.h"
#include "graphviewer.h"
#include "MutablePriorityQueue.h"

#include <iostream>
using Node = GraphViewer::Node;
using Edge = GraphViewer::Edge;

std::vector<Plane> Graph::getPlanes(){
    return this->planeSet;
}
int Graph::getAirportNum() const {
    return airportSet.size();
}

int Graph::getConnectionNum() const {
    return connectionIds.size();
}

/*
 * Auxiliary function to find an airport with a given location.
 */
Airport *Graph::findAirport(const int &id) const {
    for (auto a : airportSet)
        if (a->id == id)
            return a;
    return nullptr;
}

/*
 *  Adds an airport with a given location to a graph (this).
 *  Returns true if successful, and false if an Airport with that content already exists.
 */
bool Graph::addAirport(const int &id, const double &latitude, const double &longitude) {
    if (findAirport(id) == nullptr) {
        airportSet.push_back(new Airport(id, latitude, longitude));
        return true;
    }
    return false;
}

bool Graph::addAirport(const int &id, const double &latitude, const double &longitude, const std::string &name) {
    if (findAirport(id) == nullptr) {
        airportSet.push_back(new Airport(id, latitude, longitude, name));
        return true;
    }
    return false;
}

/*
 * Removes a Connection from a graph (this), starting at ls and ending at ld.
 * The Connection is identified by its origin and ending locations.
 * Returns true if successful, and false if such Airport does not exist.
 */
bool Graph::removeConnection(const int &ida, const int &idb) {
    auto a1 = findAirport(ida);
    auto a2 = findAirport(idb);
    if (a1 == nullptr || a2 == nullptr)
        return false;
    return a1->removeConnectionTo(a2);
}

/*
 * Adds a Connection to a graph (this), from the airport at l origin
 * to the airport at d destination, with distance dist.
 * Returns true if successful, and false if either of the source or
 * destination Airports do not exist.
 */
bool Graph::addConnection(const int &cid, const int &source, const int &destination, double dist = 0.0) {
    if (connectionIds.find(cid) != connectionIds.end())
        return false;
    auto a1 = findAirport(source);
    auto a2 = findAirport(destination);
    if (a1 == nullptr || a2 == nullptr)
        return false;
    a1->addConnection(cid, a2, dist);
    connectionIds.insert(cid);
    return true;
}

/*
 *  Removes an Airport at a given location l from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
bool Graph::removeAirport(const int &id) {
    Airport *a = findAirport(id);
    if (a == nullptr)
        return false;
    for (auto it = airportSet.begin(); it != airportSet.end(); it++) {
        if ((*it) == a) {
            if (!(*it)->removeConnections())
                return false;
            this->airportSet.erase(it);
        } else {
            if ((*it)->removeConnectionTo(a))
                return false;
        }
    }
    connectionIds.erase(id);
    return true;
}

Graph::~Graph() {
    /*
    int c = 0;
    for (auto a : airportSet) {
        if (a != nullptr){
            delete a;
            a = nullptr;
        }
        c++;
    }*/
}

void Graph::viewGraph(const std::string &imgPath, int planeID) const {
    GraphViewer gv;

    gv.setCenter(sf::Vector2f(0, 0));
    gv.createWindow(1280, 720);
    if (!imgPath.empty())
        gv.setBackground(imgPath);

    for (auto airport : airportSet) {
        Node &node0 = gv.addNode(airport->id,
                                 sf::Vector2f(airport->longitude * 10 + 800, (-airport->latitude * 10) + 4025));
        if(airport == planeSet[planeID].getSourceAirport() && planeID != -1){
            node0.setColor(GraphViewer::RED);
        }
        else{
            node0.setColor(GraphViewer::BLUE);
        }
    }

    /*
    //Display connections between airports:
    for (auto airport : airportSet) {
        for (auto connection : airport->connections) {

            Edge &edge =
                    gv.addEdge(connection.id, gv.getNode(connection.orig->id), gv.getNode(connection.dest->id),
                               GraphViewer::Edge::EdgeType::UNDIRECTED);
            edge.setColor(GraphViewer::BLACK);
        }
    }
    */

    //Display ALL planes' routes, in different colors
    if(planeID == -1){
        GraphViewer::Color colors[12] = {GraphViewer::BLACK, GraphViewer::RED, GraphViewer::GREEN,
                                         GraphViewer::BLUE, GraphViewer::YELLOW, GraphViewer::MAGENTA, GraphViewer::CYAN,
                                         GraphViewer::PINK, GraphViewer::ORANGE, GraphViewer::GRAY, GraphViewer::LIGHT_GRAY,
                                         GraphViewer::DARK_GRAY};
        size_t availableID = connectionIds.size() + 1;
        std::vector<size_t> usedIDs;
        for (size_t i = 0; i < planeSet.size(); i++) {
            auto color = colors[i%12];
            for (auto connection : planeSet[i].getRoute()) {
                unsigned int id = connection->getId();
                if(std::find(usedIDs.begin(), usedIDs.end(), id) != usedIDs.end()){
                    id = availableID;
                    availableID++;
                }
                Edge &edge =
                        gv.addEdge(id, gv.getNode(connection->getOrigin()->getId()), gv.getNode(connection->getDestination()->getId()),
                                   GraphViewer::Edge::EdgeType::DIRECTED);
                edge.setColor(color);
                usedIDs.push_back(connection->getId());
            }
        }
    }
    else{//Display the selected plane's route
        for (auto connection : planeSet[planeID].getRoute()) {
            Edge &edge =
                    gv.addEdge(connection->getId(), gv.getNode(connection->getOrigin()->getId()), gv.getNode(connection->getDestination()->getId()),
                               GraphViewer::Edge::EdgeType::DIRECTED);
            edge.setColor(GraphViewer::BLACK);
        }
    }

    gv.join();
}

void Graph::generatePassengers(const int &maxNr) {
    for (auto airport : airportSet) {
        airport->generatePassengers(maxNr, airportSet);
    }
}

void Graph::generateRandomPlane(const unsigned int &id) {
    /*
     * https://en.wikipedia.org/wiki/Airbus_A350
     * The Airbus A350 constitutes the model for our planes
     * We artifically inflated its moveSpeed, in order to prevent problems calculating some routes
     * -speed: 2000 - 2900 km/h (*1000 m/h,
     * -fuel consumption: 5000-5800 l/h
     * -max fuel: 165000 l
     * -passenger: 350-410
     */
    //generate plane at a pseudo random airport
    unsigned int speed = 2000000 + (rand() % 90000);
    unsigned int consumption = 4.8 + (rand() % 5);
    unsigned int maxFuel = 165000;
    unsigned int maxPass = 350 + (rand() % 350);
    //unsigned int airportId = (rand() % airportSet.size()) + 1;    // 1 - size
    unsigned int test = airportSet.size();
    unsigned int airportId = 1;
    Plane newPlane = Plane(id, findAirport(airportId), speed, consumption / speed, maxFuel, maxPass, nullptr,
                           this->airportSet.size());
    //generate crew
    Crew *crew = new Crew(id, &newPlane);
    newPlane.setCrew(crew);
    //visit the airport of origin
    newPlane.visitAirport(newPlane.getCurrentAirport());
    //update passengers
    newPlane.getCurrentAirport()->updatePassengers(&newPlane);
    planeSet.push_back(newPlane);
}

void Graph::generateReplacementCrews() {
    unsigned int startID = planeSet.size();
    for (size_t i = 0; i < airportSet.size(); i++) {
        Airport *at = airportSet[i];
        Crew *resting = new Crew(startID + i, at);
        at->setReplacementCrew(resting);
    }
}

void Graph::generatePlanes(size_t planeNum) {
    for (size_t i = 0; i < planeNum; i++) {
        generateRandomPlane(i);
    }
}

void Graph::calculateSteps() {
    unsigned long planes = planeSet.size();
    while (planes > 0) {
        for (Plane &p : planeSet) {
            if (!p.hasArrived()) {
                //if the plane can't move anywhere, it returns to the origin node using Dijkstra's pathfinding algorithn
                if(!p.nextStep()){
                    //TODO
                    //Dijkstra(plane *, plane->current)
                    // returns nodes to travel through to get from current to the origin
                    //  create a new function to move through those nodes
                    //  move
                    p.setArrived(true);
                    planes--;
                }
            } else {
                planes--;
            }
        }
    }
}

void Graph::printRoutes(){
    for(auto p : planeSet){
        p.printRoute();
    }
}

void Graph::moveAirplaneThroughPath(Plane *plane, std::vector<Connection *> path){
    for(Connection *c : path){
        plane->movePlane(c);
    }
}

void Graph::cycleUsingDijkstra(Plane *plane, Airport *origin) {
    struct auxEdge {
        Connection *connection;
        bool visited = false;
    };

    struct auxNode {
        Airport* airport;
        std::vector<struct auxEdge> edges;
        bool visited;
        struct auxNode *via;
        double distance;
        int queueIndex = 0;

        bool operator<(const struct auxNode &a) const { return distance < a.distance; }
    };


    std::vector<struct auxNode> nodes;
    for (auto airport : airportSet) {
        struct auxNode a{};
        a.airport = airport;
        a.visited = false;
        a.via = nullptr;
        a.queueIndex = 0;
        a.distance = std::numeric_limits<double>::max();
        for (auto &connection : *airport->getConnections()) {
            struct auxEdge b;
            b.connection = &connection;
            b.visited = false;
            a.edges.emplace_back(b);
        }
        nodes.emplace_back(a);
    }

    struct auxNode *origAirport;
    for(auxNode &node : nodes){
        if(node.airport == plane->getCurrentAirport()){
            origAirport = &node;
            origAirport->distance = 0.0;
            break;
        }
    }

    MutablePriorityQueue<struct auxNode> airportsToVisit;

    airportsToVisit.insert(origAirport);

    while (!airportsToVisit.empty()) {
        struct auxNode *current = airportsToVisit.extractMin();
        if (!current->visited) {
            current->visited = true;
            for (struct auxEdge& edge : current->edges) {
                struct auxNode *a = &*std::find_if(nodes.begin(), nodes.end(), [&edge](const struct auxNode &a) {
                    return a.airport == edge.connection->getDestination();
                });

                if ((!a->visited && a->via == nullptr) || current->distance + edge.connection->distance < a->distance) {
                    if (!a->visited && a->via != nullptr) {
                        a->distance = current->distance + edge.connection->distance;
                        a->via = current;
                        airportsToVisit.decreaseKey(a);
                    } else {
                        a->visited = false;
                        a->distance = current->distance + edge.connection->distance;
                        a->via = current;
                        airportsToVisit.insert(a);
                    }
                }
            }
        }
    }

    std::vector<Connection *> path = {};
    auxNode *curr = &*std::find_if(nodes.begin(), nodes.end(), [&origin](auxNode &node){
        return node.airport == origin;
    });
    while(curr->via != nullptr){
        auxNode *prev = curr->via;
        for(auto &edge : prev->edges){
            if(edge.connection->getDestination() == curr->airport){
                path.insert(path.begin(), edge.connection);
                break;
            }
        }
        curr = prev;
    }

    moveAirplaneThroughPath(plane, path);
    plane->printRoute();
}
