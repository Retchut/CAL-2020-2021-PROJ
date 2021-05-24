#include <iostream>

#include "graph.h"

int loader(Graph &graph, const std::string &directory, const std::string &prefix, const std::string &suffix);

/*
void insertNewAirport(Graph g){
    string n
}

void insertNewConnection(Graph g){

}

void readInput(Graph g){
    std::cout << "-----Welcome to FightNet!-----\n\n";

    std::cout << "1-Insert Airport\n";
    std::cout << "2-Insert Connection\n";
    std::cout << "enter-Run program\n";

    char input = "";

    while(input != "\n"){
    std::cin >> input;
        if(input == 1)
            insertNewAirport(g);
        if(input == 2)
            insertNewConnection(g);
    }

}*/

int main() {
    Graph g;
    //loader(g,"../airports_datasets/airports_full/",  "", ".txt");
    loader(g, "../airports_datasets/airports_iberia/", "", ".txt");
    g.generatePassengers(15);
    g.generatePlanes(1);
    g.generateReplacementCrews(0);
    g.calculateSteps();
    g.viewGraph("");
    std::cout << "Finish" << std::endl;
}