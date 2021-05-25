#include <iostream>
#include <string>

#include "graph.h"

int loader(Graph &graph, const std::string &directory, const std::string &prefix, const std::string &suffix);


void insertNewAirport(Graph g){
    int id = g.getAirportNum() +1;
    std::string name;
    double latitude;
    double longitude;
    std::string confirm = "";

    do {
        std::cout << "Please introduce the airport's latitude\n";
        std::cin >> latitude;
        std::cout << "Please introduce the airport's longitude\n";
        std::cin >> longitude;
        std::cout << "Finally, introduce the airport's 3 letter IATA code name\n";
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
            std::cout << "Please introduce the connection's source airport's ID\n";
            std::cin >> source;
            std::cout << "Please introduce the connection's destination airport's ID\n";
            std::cin >> destination;
            std::cout << "Please introduce the connection's distance\n";
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

int readInput(Graph g){
    std::cout << "1-Insert Airport\n";
    std::cout << "2-Insert Connection\n";
    std::cout << "3-Close menu and run program\n";
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

int getDisplayInput(){

    std::cout << "Please insert the ID of the plane whose route you'd like to display on the graph viewer.\n";
    int id = 0;
    std::string input;
    std::string::size_type sz;
    std::getline(std::cin, input);
    try{
        id = std::stoi(input, &sz);
        return id;
    }
    catch (...) {
        std::cout << "Invalid input. The route of plane 1 will be displayed.";
        return 1;
    }
}

int main() {
    std::cout << "-----Welcome to FightNet!-----\n\n";
    Graph g;
    //loader(g,"../airports_datasets/airports_full/",  "", ".txt");
    loader(g, "../airports_datasets/airports_iberia/", "", ".txt");

    while(true){
        int input = readInput(g);
        if(input == 0)
            return 0;
        else if(input == 3)
            break;
    }
    
    int planeToDisplay = getDisplayInput();

    g.generatePassengers(15);
    g.generatePlanes(5);
    g.generateReplacementCrews(0);
    g.calculateSteps();
    g.printRoutes();
    g.viewGraph("", planeToDisplay);
    return 0;
}