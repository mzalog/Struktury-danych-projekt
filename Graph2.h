#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include "stos.h"
#include "kolejka_priorytetowa.h"

class Graph {
    int numVertices; // liczba wierzcho³ków
    std::vector<std::vector<int>> adjacencyList; // lista s¹siedztwa

public:
    Graph(int numVertices);
    void addEdge(int src, int dest, int weight);
    void printGraph();
    void primMST_stack();
    void primMST_kol();
    static Graph readGraphFromFile(const std::string& filename);
    void generateRandomGraph(int numVertices);
};
