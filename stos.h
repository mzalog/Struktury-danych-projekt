#pragma once

class Node {
public:
    int data;
    Node* link;
    // konstruktor
    Node(int n);

};

class Stack {
    Node* top;

public:
    Stack();

    void push(int data);

    bool isEmpty();

    int peek();

    void pop();

    void display();

};



