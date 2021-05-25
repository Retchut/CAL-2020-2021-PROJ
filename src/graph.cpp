#include "graph.h"

#include "airport.h"
#include "connection.h"
#include "crew.h"
#include "plane.h"
#include "graphviewer.h"
#include "MutablePriorityQueue.h"

using Node = GraphViewer::Node;
using Edge = GraphViewer::Edge;

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
    for (Airport *airport : airportSet) {
        if (airport != nullptr){
            delete airport;
            airport = nullptr;
        }
    }
}

void Graph::viewGraph(const std::string &imgPath) const {
    GraphViewer gv;

    gv.setCenter(sf::Vector2f(0, 0));
    gv.createWindow(1280, 720);
    if (!imgPath.empty())
        gv.setBackground(imgPath);

    for (auto airport : airportSet) {
        Node &node0 = gv.addNode(airport->id,
                                 sf::Vector2f(airport->longitude * 10 + 800, (-airport->latitude * 10) + 4025));
        node0.setColor(GraphViewer::BLUE);
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
    /*
     *  static const Color BLACK     ;
        static const Color WHITE     ;
        static const Color RED       ;
        static const Color GREEN     ;
        static const Color BLUE      ;
        static const Color YELLOW    ;
        static const Color MAGENTA   ;
        static const Color CYAN      ;
        static const Color PINK      ;
        static const Color ORANGE    ;
        static const Color GRAY      ;
        static const Color LIGHT_GRAY;
        static const Color DARK_GRAY ;
     */


    //This breaks if we display more than one equal edge
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

/*
    for (auto connection : planeSet[0].getRoute()) {
        Edge &edge =
                gv.addEdge(connection->getId(), gv.getNode(connection->getOrigin()->getId()), gv.getNode(connection->getDestination()->getId()),
                           GraphViewer::Edge::EdgeType::DIRECTED);
        edge.setColor(GraphViewer::BLACK);
    }

    */
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
     * -speed: 1040 - 1090,
     * -fuel consumption: 5000-5800 l/h
     * -max fuel: 165000 l
     * -passenger: 350-410
     */
    unsigned int speed = 1040 + (rand() % 50);
    unsigned int consumption = 4.8 + (rand() % 5);
    unsigned int maxFuel = 165000;
    unsigned int maxPass = 350 + (rand() % 350);
    unsigned int airportId = (rand() % airportSet.size()) + 1;    // 1 - size
    //Plane newPlane = Plane(id, findAirport(airportId), speed, consumption/speed, maxFuel, maxPass, nullptr);
    Plane newPlane = Plane(id, findAirport(1), speed, consumption / speed, maxFuel, maxPass, nullptr,
                           this->airportSet.size());
    Crew *crew = new Crew(id, &newPlane);
    newPlane.setCrew(crew);
    newPlane.visitAirport(newPlane.getCurrentAirport());
    newPlane.getCurrentAirport()->updatePassengers(&newPlane);
    planeSet.push_back(newPlane);
}

void Graph::generateReplacementCrews(size_t restingNum) {
    unsigned int startID = airportSet.size() + 1;
    for (size_t i = 0; i < restingNum; i++) {
        Airport *at = airportSet[rand() % airportSet.size()];
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
                p.nextStep();
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


void Graph::cycleUsingDjiskstra(Plane *plane, Airport *origin) {
    struct edge {
        Connection *connection;
        bool visited = false;
    };

    struct node {
        Airport* airport;
        std::vector<struct edge> edges;
        bool visited;
        struct node *via;
        double distance;
        int queueIndex = 0;

        bool operator<(const struct node &a) const { return distance < a.distance; }
    };


    std::vector<struct node> nodes;
    for (auto airport : airportSet) {
        struct node a{};
        a.airport = airport;
        a.visited = false;
        a.via = nullptr;
        a.queueIndex = 0;
        a.distance = std::numeric_limits<double>::max();
        for (auto connection : *airport->getConnections()) {
            struct edge b;
            b.connection = &connection;
            b.visited = false;
            a.edges.emplace_back(b);
        }
        nodes.emplace_back(a);
    }

    MutablePriorityQueue<struct node> airportsToVisit;

    struct node *origAirport;
    origAirport = &nodes.at(0);
    for (auto node : nodes) {
        if (node.airport->getPassengers().size() > origAirport->airport->getPassengers().size())
            origAirport = &node;
    }
    origAirport->distance = 0.0;

    airportsToVisit.insert(origAirport);

    while (!airportsToVisit.empty()) {
        struct node *current = airportsToVisit.extractMin();
        if (!current->visited) {
            current->visited = true;
            for (struct edge& edge : current->edges) {
                struct node *a = &*std::find_if(nodes.begin(), nodes.end(), [&edge](const struct node &a) {
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
}
