#pragma once
#include <stdexcept>

class PriorityQueue {
private:
    int* heap;//WskaŸnik na tablicê dynamiczn¹, przechowuje elementy kolejki priorytetowej.
    int capacity;//Maksymalna pojemnoœæ kolejki priorytetowej (rozmiar tablicy).
    int size;//Aktualny rozmiar kolejki priorytetowej (liczba elementów).

    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    PriorityQueue(int capacity);// Konstruktor klasy PriorityQueue, który inicjalizuje kolejkê priorytetow¹ z okreœlon¹ pojemnoœci¹.
    ~PriorityQueue();//Destruktor klasy PriorityQueue, który zwalnia pamiêæ zajmowan¹ przez tablicê heap.

    void push(int value);
    int pop();
    bool empty() const;
};
