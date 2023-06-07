#include "stos.h"
#include <iostream>
using namespace std;


Node::Node(int n)
{
    // konstruktor
    this->data = n;
    this->link = NULL;
}

Stack::Stack()
{
    top = NULL;
}

void Stack::push(int data)
{
    // wêze³ temp,który alkowoany jest w pamieci za pomoca new
    Node* temp = new Node(data);
    // sprawdzenie czy alkoacja sie udala
    if (!temp) {
        std::cout << "\nStack Overflow";
        exit(1);
    }

    // wart data przypisywana do pola data wezla temp 
    temp->data = data;

    // pole line wêz³a temp ustawiane na akt wart wskazywana przez top
    temp->link = top;

    // wskaznik top ustawiany na wezel top, czyli jest nowym wierzcholkiem stosu
    top = temp;
}

// sprawdzenie czy stos jest pusty
bool Stack::isEmpty()
{
    // jesli top jest pusty onzacza to, ze stos jest pusty
    return top == NULL;
}
// fcja uzywana do zwrocenia elementu na szczycie stosu
int Stack::peek()
{
    // jesli stos nie jest pusty zwraca wartosc data
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// funkcja usuwajaca elementy stosu
void Stack::pop()
{
    Node* temp;
    // sprawdzenie czy stos nie jest pusty
    if (top == NULL) {
        std::cout << "\nStack Underflow" << std::endl;
        exit(1);
    }
    else {
        // przypisanie do top temp
        temp = top;

        // przypisanie drugiego elementu do top
        top = top->link;

        // To automatycznie niszczy link miêdzy pierwszym i drugim elementem

        // zwalnianie pamiêci wierzcho³ka przez usuniêcie go z pamiêci przy u¿yciu funkcji free
        free(temp);
    }
}
// fcja wyswietlajaca 
void Stack::display()
{
    Node* temp;
    // sprawdzenie czy stos jest pusty
    if (top == NULL) {
        std::cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = top;
        while (temp != NULL) {
            // wydrukownie daty 
            cout << temp->data;

            // przypisanie linku do zmiennej temp 
            temp = temp->link;
            if (temp != NULL)
                cout << " -> ";
        }
    }
}

    /*
    // wlozenie na stos elementow
        stack.push(11);
        stack.push(22);
        stack.push(33);
        stack.push(44);

        // wyswietlenie wszystkich elementow stosu
        stack.display();

        // wyswietlenie wierzcholka stosu
        cout << "\nTop element is " << stack.peek() << endl;

        // usuniecie dwoch elementow z gory stosu
        stack.pop();
        stack.pop();

        // wyswietlenie elementow stosu
        stack.display();

        // wyswietlenie wierzcholka stosu
        cout << "\nTop element is " << stack.peek() << endl;

        return 0;*/


