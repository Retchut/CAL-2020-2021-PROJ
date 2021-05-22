#include <fstream>
#include <iostream>
#include <algorithm>

#include "graph.h"
#include "airport.h"


void removeChars(std::string &string, const std::string &charsToRemove) {
    string.erase(std::remove_if(string.begin(), string.end(),
                                [&charsToRemove](char character) {
                                    return charsToRemove.find(character) != std::string::npos;
                                }), string.end());
}


int loader(Graph &graph, const std::string &directory, const std::string &prefix = std::string(""),
           const std::string &suffix = std::string("")) {
    // Load airports
    std::ifstream fileA;
    std::ifstream fileB;
    std::string rowA, rowB;
    int rowsToReadA = 0, rowsToReadB = 0;
    std::cout << "Reading data from: " << directory + prefix + "node_coords" + suffix << std::endl;
    std::cout << "Reading data from: " << directory + prefix + "node_names" + suffix << std::endl;

    fileA.open(directory + prefix + "node_coords" + suffix, std::ios::in);
    fileB.open(directory + prefix + "node_names" + suffix, std::ios::in);

    if (!fileA.is_open()) {
        std::cout << "Failed opening node_coord fileA" << std::endl;
        return 1;
    }

    if (!fileB.is_open()) {
        std::cout << "Failed opening node_names fileA" << std::endl;
        return 1;
    }

    if (getline(fileA, rowA)) {
        rowsToReadA = std::stoi(rowA);
    }

    if (getline(fileB, rowB)) {
        rowsToReadB = std::stoi(rowA);
    }
    if (rowsToReadA != rowsToReadB) {
        std::cout << "Node_coords and node_names files dont match" << std::endl;
        return 1;
    }

    int rowNr = 0;
    while (getline(fileA, rowA)) {
        if (!getline(fileB, rowB)) {
            return 1;
        }
        rowNr++;
        removeChars(rowA, "()");
        removeChars(rowB, "()");
        int idNode = std::stoi(rowA.substr(0, rowA.find_first_of(',')));
        rowA.erase(0, rowA.find_first_of(',') + 1);
        double latitude = std::stod(rowA.substr(0, rowA.find_first_of(',')));
        rowA.erase(0, rowA.find_first_of(',') + 1);
        double longitude = std::stod(rowA);

        int idName = std::stoi(rowB.substr(0, rowB.find_first_of(',')));
        rowB.erase(0, rowB.find_first_of(',') + 1);
        if (idName == idNode)
            graph.addAirport(idNode, latitude, longitude, rowB);
        else
            graph.addAirport(idNode, latitude, longitude);
    }

    fileA.close();
    fileB.close();

    if (rowNr != rowsToReadA) {
        std::cout << "WARNING: Nodes incorrectly loaded" << std::endl;
    }


    // Load connections
    std::cout << "Reading data from: " << directory + prefix + "edges" + suffix << std::endl;
    std::cout << "Reading data from: " << directory + prefix + "edge_weights" + suffix << std::endl;
    fileA.open(directory + prefix + "edges" + suffix, std::ios::in);
    fileB.open(directory + prefix + "edge_weights" + suffix, std::ios::in);
    if (!fileA.is_open()) {
        std::cout << "Failed opening edges fileA" << std::endl;
        return 1;
    }

    if (getline(fileA, rowA)) {
        rowsToReadA = std::stoi(rowA);
    }
    if (getline(fileB, rowB)) {
        rowsToReadB = std::stoi(rowA);
    }
    if (rowsToReadA != rowsToReadB) {
        std::cout << "Node_coords and node_names files dont match" << std::endl;
        return 1;
    }

    rowNr = 0;
    while (getline(fileA, rowA)) {
        if (!getline(fileB, rowB)) {
            return 1;
        }
        rowNr++;
        removeChars(rowA, "()");
        removeChars(rowB, "()");
        int sourceAirportEdges = std::stoi(rowA.substr(0, rowA.find_first_of(',')));
        rowA.erase(0, rowA.find_first_of(',') + 1);
        int destinationAirportEdges = std::stoi(rowA);

        int sourceAirportWeights = std::stoi(rowB.substr(0, rowB.find_first_of(',')));;
        rowB.erase(0, rowB.find_first_of(',') + 1);
        int destinationAirportWeights = std::stoi(rowB);
        rowB.erase(0, rowB.find_first_of(',') + 1);

        if (sourceAirportEdges == sourceAirportWeights && destinationAirportEdges == destinationAirportWeights) {
            graph.addConnection(rowNr, sourceAirportEdges, destinationAirportEdges, std::stod(rowB));
        } else {
            return 1;
        }

    }

    if (rowNr != rowsToReadA) {
        std::cout << "WARNING: Edges fileA was incorrectly loaded" << std::endl;
    }

    fileA.close();
    fileB.close();

    return 0;
}

