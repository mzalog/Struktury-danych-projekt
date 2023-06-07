#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "stos.h"
#include "kolejka_priorytetowa.h"

using namespace std;

class Graph {
private:
    int V; // liczba wierzcho³ków
    vector<vector<int>> adjacencyMatrix; // macierz s¹siedztwa

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    int findMinKey(vector<int>& key, vector<bool>& mstSet);
    void printMST(vector<int>& parent);
    void primMST();
    void primMST_kol();
    auto readGraphFromFile(const string& filename);
    
    void primMST_stack();
    void generateRandomGraph(int numVertices);

};



Graph readGraphFromFile(const string& filename);