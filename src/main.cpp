#include <iostream>

#include "graph.h"

int loader(Graph &graph, const std::string &directory, const std::string &prefix, const std::string &suffix);

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