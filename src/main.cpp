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

bool readInput(Graph g){
    std::cout << "-----Welcome to FightNet!-----\n\n";

    std::cout << "1-Insert Airport\n";
    std::cout << "2-Insert Connection\n";
    std::cout << "3-Close menu and run program\n";
    std::cout << "0-Close the program\n";

    std::string input = "";

    while(true){
        std::getline(std::cin,input);
        if(input == "1"){
            return true;
            insertNewAirport(g);
        }
        if(input == "2"){
            return true;
            insertNewConnection(g);
        }
        if(input == "3"){
            return true;
        }
        if(input == "0"){
            return false;
        }
    }
}

int main() {
    Graph g;
    //loader(g,"../airports_datasets/airports_full/",  "", ".txt");
    loader(g, "../airports_datasets/airports_iberia/", "", ".txt");

    while(true){
        /*
        if(!readInput(g))
            break;
        */
        bool test = readInput(g);
        std::cout << "bool was " << test << "\n";
        if(!test)
            break;

/*
        g.generatePassengers(15);
        g.generatePlanes(2);
        g.generateReplacementCrews(0);
        g.calculateSteps();
        g.viewGraph("");
        std::cout << "Finish" << std::endl;
        */
    }

    /*
    g.generatePassengers(15);
    g.generatePlanes(2);
    g.generateReplacementCrews(0);
    g.calculateSteps();
    g.printRoutes();
    g.viewGraph("");
    std::cout << "Finish" << std::endl;
    */

}