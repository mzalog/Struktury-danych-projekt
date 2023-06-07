#pragma once
#include <stdexcept>

class PriorityQueue {
private:
    int* heap;//Wska�nik na tablic� dynamiczn�, przechowuje elementy kolejki priorytetowej.
    int capacity;//Maksymalna pojemno�� kolejki priorytetowej (rozmiar tablicy).
    int size;//Aktualny rozmiar kolejki priorytetowej (liczba element�w).

    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    PriorityQueue(int capacity);// Konstruktor klasy PriorityQueue, kt�ry inicjalizuje kolejk� priorytetow� z okre�lon� pojemno�ci�.
    ~PriorityQueue();//Destruktor klasy PriorityQueue, kt�ry zwalnia pami�� zajmowan� przez tablic� heap.

    void push(int value);
    int pop();
    bool empty() const;
};
