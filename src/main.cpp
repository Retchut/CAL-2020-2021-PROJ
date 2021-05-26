#include <iostream>
#include <string>

#include "graph.h"
#include "airport.h"
#include "plane.h"
#include "connection.h"

int loader(Graph &graph, const std::string &directory, const std::string &prefix, const std::string &suffix);


void insertNewAirport(Graph g){
    int id = g.getAirportNum() +1;
    std::string name;
    double latitude;
    double longitude;
    std::string confirm = "";

    do {
        std::cout << "Please input the airport's latitude\n";
        std::cin >> latitude;
        std::cout << "Please input the airport's longitude\n";
        std::cin >> longitude;
        std::cout << "Finally, input the airport's 3 letter IATA code name\n";
        std::getline(std::cin, name);

        std::cout << "You're about to create an airport with the following characteristics:\nid: " << id
                  << "\nlatitude: " << latitude
                  << "\nlongitude: " << longitude
                  << "\nname: " << name <<
                  "\n Do you want to confirm? Enter 'y' to confirm or 'b' to go back to the menu\n";
        std::getline(std::cin, confirm);
    }while(confirm != "y" && confirm != "b");

    if(confirm == "y")
        g.addAirport(id,latitude,longitude,name);
}

void insertNewConnection(Graph g){
        int id = g.getConnectionNum() +1;
        int source;
        int destination;
        int distance;
        std::string confirm = "";

        do{
            std::cout << "Please input the connection's source airport's ID\n";
            std::cin >> source;
            std::cout << "Please input the connection's destination airport's ID\n";
            std::cin >> destination;
            std::cout << "Please input the connection's distance\n";
            std::cin >> distance;

            std::cout << "You're about to create a connection with the following characteristics:\nid: " << id
            << "\nsource ID: " << source
            << "\ndestination ID: " << destination
            << "\nconnection's distance: " << distance
            <<  "\n Do you want to confirm? Enter 'y' to confirm  or 'b' to go back to the menu\n";
            std::getline(std::cin,confirm);
        }
        while(confirm != "y" && confirm != "b");

        if(confirm == "y")
            g.addConnection(id,source,destination,distance);


}

int drawIberianDataSet(){;
    std::cout << "Which dataset would you like to work with?\n";
    std::cout << "1-Iberian Peninsula data set\n";
    std::cout << "2-World data set\n";
    std::cout << "0-Quit\n";

    std::string input;

    while(true){
        std::getline(std::cin,input);
        if(input == "1"){
            return 1;
        }
        if(input == "2"){
            return 2;
        }
        if(input == "0"){
            return 0;
        }
    }
}

int readInput(Graph g){
    std::cout << "1-Insert Airport\n";
    std::cout << "2-Insert Connection\n";
    std::cout << "3-Stop making changes and run the program\n";
    std::cout << "0-Close the program\n";

    std::string input;

    while(true){
        std::getline(std::cin,input);
        if(input == "1"){
            insertNewAirport(g);
            return 1;
        }
        if(input == "2"){
            insertNewConnection(g);
            return 2;
        }
        if(input == "3"){
            return 3;
        }
        if(input == "0"){
            return 0;
        }
    }
}

int getPassengerNum(){

    std::cout << "Please input the maximum number of passengers to add to each airport (min 1).\n";
    int num = 0;
    std::string input;
    std::string::size_type sz;
    std::getline(std::cin, input);
    try{
        num = std::stoi(input, &sz);
        if(num <= 0){
            std::cout << "That amount is too low. The maximum was set to 20.\n";
            return 20;
        }
        return num;
    }
    catch (...) {
        std::cout << "Invalid input. The maximum was set to 20.\n";
        return 20;
    }
}

int getPlaneNum(){

    std::cout << "Please input the number of planes to create (min 1).\n";
    int num = 0;
    std::string input;
    std::string::size_type sz;
    std::getline(std::cin, input);
    try{
        num = std::stoi(input, &sz);
        if(num <= 0){
            std::cout << "That amount is too low. 10 planes will be created.\n";
            return 10;
        }
        return num;
    }
    catch (...) {
        std::cout << "Invalid input. 10 planes will be created.\n";
        return 10;
    }
}

/*
int getRplcNum(){

    std::cout << "Please input the number of replacement crews to create (min 0 - disabled replacement).\n";
    int num = 0;
    std::string input;
    std::string::size_type sz;
    std::getline(std::cin, input);
    try{
        num = std::stoi(input, &sz);
        if(num < 0){
            std::cout << "That amount is too low. 0 replacement crews will be created.\n";
            return 0;
        }
        return num;
    }
    catch (...) {
        std::cout << "Invalid input. 0 replacement crews will be created.\n";
        return 0;
    }
}
*/

int getTrackedPlane(int maxPlanes){

    std::cout << "Please input the ID of the plane whose route you'd like to display on the graph viewer (min 1).\n";
    std::cout << "Input -1 to see all planes's routes.\n";
    int id = 0;
    std::string input;
    std::string::size_type sz;
    std::getline(std::cin, input);
    try{
        id = std::stoi(input, &sz);
        if(id < -1){
            std::cout << "That amount is too low. The route of plane 0 will be displayed.\n";
            return 0;
        }
        else if(id > (maxPlanes - 1)){
            std::cout << "That id does not exist. The route of plane 0 will be displayed.\n";
            return 0;
        }
        return id;
    }
    catch (...) {
        std::cout << "Invalid input. The route of plane 0 will be displayed.\n";
        return 0;
    }
}

int main() {
    std::cout << "-----Welcome to FightNet!-----\n\n";
    /*
    while(true){
        srand(time(0));
        Graph g;
        switch(drawIberianDataSet()){
            case 1:
                loader(g, "../airports_datasets/airports_iberia/", "", ".txt");
                break;
            case 2:
                loader(g,"../airports_datasets/airports_full/",  "", ".txt");
                break;
            case 0:
                return 0;
        }

        while(true){
            int input = readInput(g);

            //display graph
            if(input == 3){
                break;
            }
            //end execution of program
            else if(input == 0){
                return 0;
            }
            //keep altering the graph
        }
        int passengerNum = getPassengerNum();
        int planeNum = getPlaneNum();
        //int replacementNum = getRplcNum();
        int trackedPlaneID = getTrackedPlane(planeNum);

        g.generatePassengers(passengerNum);
        g.generatePlanes(planeNum);
        g.generateReplacementCrews();
        g.calculateSteps();
        g.printRoutes();
        g.viewGraph("", trackedPlaneID);
        std::cout << "\n";
    }
     */
    Graph g;
    //loader(g,"../airports_datasets/airports_full/",  "", ".txt");
    loader(g, "../airports_datasets/airports_iberia/", "", ".txt");

    g.generatePassengers(1000);
    g.generatePlanes(30);
    g.generateReplacementCrews();
    g.calculateSteps();
    g.printRoutes();
    //g.viewGraph("", 0);

    /*
    //Test dijkstra
    Graph g;
    loader(g, "../airports_datasets/dijkstra_test/", "", ".txt");
    g.generatePassengers(1);
    g.generatePlanes(1);
    g.generateReplacementCrews();
    Plane p1 = g.getPlanes()[0];
    //A to B
    std::vector<Connection> p1c = *p1.getCurrentAirport()->getConnections();
    Connection *AtoBid1 = &p1c[0];
    p1.movePlane(AtoBid1);

    //B to C
    std::vector<Connection> p2c = *p1.getCurrentAirport()->getConnections();
    Connection *BtoCid4 = &p2c[1];
    p1.movePlane(BtoCid4);

    //C to D
    std::vector<Connection> p3c = *p1.getCurrentAirport()->getConnections();
    Connection *CtoDid4 = &p3c[2];
    p1.movePlane(CtoDid4);

    g.cycleUsingDijkstra(&p1, p1.getSourceAirport());
    */
}