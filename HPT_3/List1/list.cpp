#include "list.h"

#include <iostream>

List::List() : head(0) {
}

List::~List() {
    ListItem *current = head;
    while (head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }
}

void List::newItem(int value) {
    ListItem *new_item = new ListItem(value);
    new_item->next = head; // Igen, a List osztály eléri a ListItem adattagjait, emlékezzünk a friend-re
    head = new_item;
}

void List::print() const {
    ListItem *current = head;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current=current->next;
    }
}

void List::erase(int value)
{
 
}

void List::newItemBack(int value)
{
 
}
