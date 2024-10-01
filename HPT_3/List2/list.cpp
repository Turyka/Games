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
    // A lista végén a kovetkezo értéke nem 0, hanem head
    while(current != head) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

void List::printBackwards() const {

}

void List::newItemBack(int value) {

}
