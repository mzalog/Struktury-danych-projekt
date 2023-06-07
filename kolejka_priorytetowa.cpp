#include "kolejka_priorytetowa.h"

PriorityQueue::PriorityQueue(int capacity) {
    heap = new int[capacity];
    this->capacity = capacity;
    size = 0;
}//Konstruktor klasy PriorityQueue alokuje pamiêæ dla tablicy heap o podanej pojemnoœci capacity. Ustawia pocz¹tkow¹ wartoœæ size na 0, poniewa¿ pocz¹tkowo kolejka priorytetowa jest pusta.

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}//Destruktor klasy PriorityQueue zwalnia pamiêæ zajmowan¹ przez tablicê heap.

void PriorityQueue::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    int value = heap[index];

    while (index > 0 && heap[parentIndex] > value) {
        heap[index] = heap[parentIndex];
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }

    heap[index] = value;
}//Metoda heapifyUp naprawia kopiec w górê, przywracaj¹c w³aœciwoœci kopca po dodaniu elementu. Przesuwa element value na odpowiedni¹ pozycjê w kopcu, porównuj¹c go z jego rodzicami i zamieniaj¹c miejscami, jeœli jest mniejszy.

void PriorityQueue::heapifyDown(int index) {
    int value = heap[index];

    while (true) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestChildIndex = index;

        if (leftChildIndex < size && heap[leftChildIndex] < heap[smallestChildIndex]) {
            smallestChildIndex = leftChildIndex;
        }

        if (rightChildIndex < size && heap[rightChildIndex] < heap[smallestChildIndex]) {
            smallestChildIndex = rightChildIndex;
        }

        if (smallestChildIndex == index) {
            break;
        }

        heap[index] = heap[smallestChildIndex];
        index = smallestChildIndex;
    }

    heap[index] = value;
}//Metoda heapifyDown naprawia kopiec w dó³, przywracaj¹c w³aœciwoœci kopca po usuniêciu elementu. Przesuwa element value na odpowiedni¹ pozycjê w kopcu, porównuj¹c go z jego dzieæmi i zamieniaj¹c miejscami, jeœli jest wiêkszy.

void PriorityQueue::resize() {
    int newCapacity = capacity * 2;
    int* newHeap = new int[newCapacity];

    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }

    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

void PriorityQueue::push(int value) {
    if (size == capacity) {
        resize();
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

int PriorityQueue::pop() {
    if (empty()) {
        throw std::out_of_range("Kolejka jest pusta");
    }

    int minValue = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return minValue;
}

bool PriorityQueue::empty() const {
    return size == 0;
}
