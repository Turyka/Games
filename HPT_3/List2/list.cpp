#include "list.h"

#include <iostream>

List::List() :  head(new ListItem()) {
    // Az elején csak ez az egy elem van, de mivel körkörös, magára mutat
    head->next = head->prev = head;
}

List::~List() {
    // Az utolsó elemnél a kovetkező értéke a head, így a korábbi megoldás nem működik, de szerencsére ez sem bonyolultabb
    ListItem *current = head->next;
    while(current != head) {
        current = current->next;
        delete current->prev;
    }
    delete head;
}

void List::newItem(int value) {
    // Legyen megint az elejére fűzés
    ListItem *new_item = new ListItem(value);
    
    // Először beállítjuk az új elem mutatóit a két szomszédjára
    new_item->next = head->next;
    new_item->prev = head;
    
    // Majd a szomszédok segítségével beláncoljuk a listába
    head->next->prev = new_item;
    head->next = new_item;
    
    // Fontos a sorrend. Előbb használjuk a head->next régi értékét, csak ez után adjunk neki újat
}

void List::print() const {
    // Ismét: a head nem az első elemre mutat, hanem az extra fejelemre
    ListItem *current = head->next;
    // A lista végén a következő értéke nem nullptr, hanem head
    while(current != head) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

// Órai feladatok

void List::printBackwards() const {
    // A head nem az utolsó elemre mutat, hanem az extra fejelemre
    ListItem *current = head->prev;
    // A lista elején az előző értéke nem nullptr, hanem head
    while(current != head) {
        std::cout << current->value << std::endl;
        current = current->prev;
    }
}

void List::newItemBack(int value) {
    ListItem *new_item = new ListItem(value);

    // Először beállítjuk az új elem mutatóit a két szomszédjára
	// Mivel az új elem lesz az utolsó, ezért utána a head következik
    new_item->next = head;
    new_item->prev = head->prev;

    // Majd a szomszédok segítségével beláncoljuk a listába
    head->prev->next = new_item;
    head->prev = new_item;

    // Fontos a sorrend. Előbb használjuk a head->prev régi értékét, csak ez után adjunk neki újat
}

void List::erase(int value) {
    ListItem *current;
	// Keresünk egy value értékű elemet
    current = head->next;
    while(current != head && current->value != value)
        current = current->next;
	// ha találtunk ilyen elemet
    if(current != head) {
		// bekötjük a listába
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
}
