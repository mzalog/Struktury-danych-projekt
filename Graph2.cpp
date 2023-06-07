#include "Graph2.h"
#include "stos.h"
#include "kolejka_priorytetowa.h"

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int src, int dest, int weight) {
    adjacencyList[src].push_back(dest);
    adjacencyList[dest].push_back(src);
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Wierzcholek " << i << " -> ";
        for (int j : adjacencyList[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::primMST_stack() {
    std::vector<int> parent(numVertices, -1); // tablica przechowuj¹ca MST
    std::vector<int> key(numVertices, INT_MAX); // klucze wierzcho³ków
    std::vector<bool> mstSet(numVertices, false); // wierzcho³ki ju¿ w³¹czone do MST

    key[0] = 0; // klucz startowego wierzcho³ka ustawiony na 0

    Stack stack; // stos do przechowywania wierzcho³ków

    stack.push(0); // dodanie startowego wierzcho³ka na stos

    while (!stack.isEmpty()) {
        int u = stack.peek();
        stack.pop();

        mstSet[u] = true;

        for (int v : adjacencyList[u]) {
            if (!mstSet[v] && key[v] > 0) {
                parent[v] = u;
                key[v] = 0;
                stack.push(v);
            }
        }
    }

    //printMST(parent);
}

void Graph::primMST_kol() {
    std::vector<int> parent(numVertices, -1); // tablica przechowuj¹ca MST
    std::vector<int> key(numVertices, INT_MAX); // klucze wierzcho³ków
    std::vector<bool> mstSet(numVertices, false); // wierzcho³ki ju¿ w³¹czone do MST

    key[0] = 0; // klucz startowego wierzcho³ka ustawiony na 0

    PriorityQueue pq(numVertices); // tworzenie kolejki priorytetowej

    pq.push(0); // dodanie startowego wierzcho³ka do kolejki priorytetowej

    while (!pq.empty()) {
        int u = pq.pop();

        mstSet[u] = true;

        for (int v : adjacencyList[u]) {
            if (!mstSet[v] && adjacencyList[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjacencyList[u][v];
                pq.push(v); // dodanie wierzcho³ka do kolejki priorytetowej
            }
        }
    }

    //printMST(parent);
}

Graph Graph::readGraphFromFile(const std::string& filename) {
    std::string filePath = "D:\\Data Miko³aj\\visual studio\\SD algorytm projekt 2\\projekt 2 SD\\graph\\" + filename;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku " << filename << std::endl;
        exit(1);
    }

    int numVertices, numEdges;
    file >> numVertices >> numEdges;

    Graph graph(numVertices);

    int src, dest, weight;
    for (int i = 0; i < numEdges; i++) {
        file >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    file.close();

    return graph;
}

void Graph::generateRandomGraph(int numVertices) {
    this->numVertices = numVertices;
    adjacencyList.resize(numVertices);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weightDist(1, 100);

    for (int u = 0; u < numVertices; u++) {
        for (int v = u + 1; v < numVertices; v++) {
            int weight = weightDist(gen);
            addEdge(u, v, weight);
        }
    }
}
