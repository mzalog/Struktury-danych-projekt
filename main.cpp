#include "stos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <chrono>
#include "kolejka_priorytetowa.h"
#include "Graph2.h"
#include <random>

using namespace std;

void processGraph(int numVertices, ofstream& outputFile) {
    Graph graph(numVertices);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // Tworzenie grafu pe³nego
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int randomNum = dist(gen);
            graph.addEdge(i, j, randomNum);
        }
    }

    // Mierzenie czasu trwania
    auto start = std::chrono::high_resolution_clock::now();
    
    //graph.primMST();
    graph.primMST_stack();
    //graph.primMST_kol();

    // Zakoñczenie pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double timeInSeconds = duration.count();

    // Wyœwietlenie czasu trwania
    //std::cout << "Czas trwania: " << timeInSeconds << " sekundy" << std::endl;
    //cout << timeInSeconds <<endl;
    //cout << numVertices << "\t" << timeInSeconds << "\t";

    auto start2 = std::chrono::high_resolution_clock::now();

    graph.primMST_kol();
    //graph.primMST();
    // Zakoñczenie pomiaru czasu
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    double timeInSeconds2 = duration2.count();

    // Wyœwietlenie czasu trwania
    //std::cout << "Czas trwania kolejka: " << timeInSeconds2 << " sekundy" << std::endl;
    //cout << timeInSeconds2 << endl;
    //cout << timeInSeconds2 << endl;
    outputFile << numVertices << "\t" << timeInSeconds << "\t" << timeInSeconds2 << endl;
}

void processGraph2(int numVertices, ofstream& outputFile) {
    Graph graph(numVertices); // Create a graph object with 5 vertices
    graph.generateRandomGraph(numVertices); // Generate a random graph with 5 vertices

    auto start = std::chrono::high_resolution_clock::now();

    graph.primMST_stack();
  
    // Zakoñczenie pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double timeInSeconds = duration.count();

    auto start2 = std::chrono::high_resolution_clock::now();

    graph.primMST_kol();
    //graph.primMST();
    // Zakoñczenie pomiaru czasu
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    double timeInSeconds2 = duration2.count();

    outputFile << numVertices << "\t" << timeInSeconds << "\t" << timeInSeconds2 << endl;
}


int main()
{
    //string filename = "graphV200D0.75.txt";

    //Graph graph = readGraphFromFile(filename);
    /*vector<int> graphSizes = {10, 100, 190, 280, 370, 460, 550, 640, 730, 820, 910, 1000, 1090, 1180, 1270, 1360, 1450, 1540, 1630, 1720, 1810, 1900, 1990, 2080, 2170, 2260, 2350, 2440, 2530, 2620, 2710, 2800, 2890, 2980, 3070, 3160, 3250, 3340, 3430, 3520, 3610, 3700, 3790, 3880, 3970, 4060, 4150, 4240, 4330, 4420, 4510, 4600, 4690, 4780, 4870, 4960, 5050, 5140, 5230, 5320, 5410, 5500, 5590, 5680, 5770, 5860, 5950, 6040, 6130, 6220, 6310, 6400, 6490, 6580, 6670, 6760, 6850, 6940, 7030, 7120, 7210, 7300, 7390, 7480, 7570, 7660, 7750, 7840, 7930, 8020, 8110, 8200, 8290, 8380, 8470, 8560, 8650, 8740, 8830, 8920, 9010, 9100, 9190, 9280, 9370, 9460, 9550, 9640, 9730, 9820, 9910, 10000};

    cout << "iloœæ krawêdzi grafu\tstos\tkolejka" << endl;

    for (int size : graphSizes) {
        processGraph(size);
    }

    return 0;
    
    
    ofstream outputFile("wyniki.csv");  // Nazwa pliku wyjœciowego
    


    vector<int> graphSizes = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500,
        5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000 };


    outputFile << "iloœæ krawêdzi grafu\tstos\tkolejka" << endl;

    for (int size : graphSizes) {
        processGraph2(size, outputFile);
    }

    outputFile.close();
    */
    
    ofstream outputFile("wyniki.csv");  // Nazwa pliku wyjœciowego

    vector<int> graphSizes = { 10, 100, 190, 280, 370, 460, 550, 640, 730, 820, 910, 1000, 1090, 1180, 1270, 1360, 1450, 1540, 1630, 1720, 1810, 1900, 1990, 2080, 2170, 2260, 2350, 2440, 2530, 2620, 2710, 2800, 2890, 2980, 3070, 3160, 3250, 3340, 3430, 3520, 3610, 3700, 3790, 3880, 3970, 4060, 4150, 4240, 4330, 4420, 4510, 4600, 4690, 4780, 4870, 4960, 5050, 5140, 5230, 5320, 5410, 5500, 5590, 5680, 5770, 5860, 5950, 6040, 6130, 6220, 6310, 6400, 6490, 6580, 6670, 6760, 6850, 6940, 7030, 7120, 7210, 7300, 7390, 7480, 7570, 7660, 7750, 7840, 7930, 8020, 8110, 8200, 8290, 8380, 8470, 8560, 8650, 8740, 8830, 8920, 9010, 9100, 9190, 9280, 9370, 9460, 9550, 9640, 9730, 9820, 9910, 10000 };




    outputFile << "iloœæ krawêdzi grafu\tstos\tkolejka" << endl;

    for (int size : graphSizes) {
        processGraph(size, outputFile);
    }

    outputFile.close();

    return 0;

}
