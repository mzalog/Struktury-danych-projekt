#include "graph.h"
#include <random>

Graph::Graph(int V) {
    this->V = V;
    adjacencyMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyMatrix[u][v] = weight;
    adjacencyMatrix[v][u] = weight;
}

int Graph::findMinKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void Graph::printMST(vector<int>& parent) {
    cout << "Minimalne drzewo rozpinajace (MST):" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
}

void Graph::primMST_stack()
{
    vector<int> parent(V, -1); // tablica przechowuj¹ca MST
    vector<int> key(V, INT_MAX); // klucze wierzcho³ków
    vector<bool> mstSet(V, false); // wierzcho³ki ju¿ w³¹czone do MST

    key[0] = 0; // klucz startowego wierzcho³ka ustawiony na 0

    Stack stack; // stos do przechowywania wierzcho³ków

    stack.push(0); // dodanie startowego wierzcho³ka na stos

    while (!stack.isEmpty())
    {
        int u = stack.peek();
        stack.pop();

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (adjacencyMatrix[u][v] != 0 && !mstSet[v] && adjacencyMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adjacencyMatrix[u][v];
            }
        }

        // Znalezienie wierzcho³ka o najmniejszym kluczu
        int minKeyVertex = -1;
        int minKey = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!mstSet[i] && key[i] < minKey)
            {
                minKey = key[i];
                minKeyVertex = i;
            }
        }

        if (minKeyVertex != -1)
        {
            stack.push(minKeyVertex);
        }
    }

    //printMST(parent);
}


void Graph::primMST_kol() {
    vector<int> parent(V, -1); // tablica przechowuj¹ca MST
    vector<int> key(V, INT_MAX); // klucze wierzcho³ków
    vector<bool> mstSet(V, false); // wierzcho³ki ju¿ w³¹czone do MST

    key[0] = 0; // klucz startowego wierzcho³ka ustawiony na 0

    PriorityQueue pq(V); // tworzenie kolejki priorytetowej

    pq.push(0); // dodanie startowego wierzcho³ka do kolejki priorytetowej

    while (!pq.empty()) {
        int u = pq.pop();

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (adjacencyMatrix[u][v] != 0 && !mstSet[v] && adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjacencyMatrix[u][v];
                pq.push(v); // dodanie wierzcho³ka do kolejki priorytetowej
            }
        }
    }

    //printMST(parent);
}

auto Graph::readGraphFromFile(const string& filename) {
    string filePath = "D:\\Data Miko³aj\\visual studio\\SD algorytm projekt 2\\projekt 2 SD\\graph\\" + filename;

    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku " << filename << endl;
        exit(1);
    }

    int V, E;
    file >> V >> E;

    Graph graph(V);

    int u, v, weight;
    for (int i = 0; i < E; i++) {
        file >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    file.close();

    return graph;
}


void Graph::generateRandomGraph(int numVertices) {
    this->V = numVertices;//h
    adjacencyMatrix.resize(V, vector<int>(V, 0));

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> weightDist(1, 100);

    for (int u = 0; u < V; u++) {
        for (int v = u + 1; v < V; v++) {
            int weight = weightDist(gen);
            addEdge(u, v, weight);
        }
    }
}
