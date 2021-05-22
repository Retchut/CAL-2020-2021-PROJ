#include <iostream>

#include "graph.h"

void ex1();

int loader(Graph& graph, const std::string &directory, const std::string &prefix, const std::string &suffix);

int main() {
    ex1();
    Graph g;
    loader(g,"../airports_dataset/",  "airports_full_", ".txt");

    std::cout << "Finish" << std::endl;
}