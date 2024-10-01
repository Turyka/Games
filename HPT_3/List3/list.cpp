#include "list.h"

List::List() : head(new ListItem()) {
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
    // Fontos a sorrend. Előbb használjuk a head->next régi értékét, cask ez után adjunk neki újat
}

List::Iterator List::begin() {
    return Iterator(head->next);
}

List::Iterator List::end() {
    return Iterator(head);
}

List::Iterator::Iterator(List::ListItem *_item) : item(_item) {
}

bool List::Iterator::operator==(const List::Iterator &other) const {
    return item == other.item;
}

bool List::Iterator::operator!=(const List::Iterator &other) const {
    return item != other.item;
}

List::Iterator List::Iterator::operator++(int) {
	Iterator ret(item);
	item = item->next;
	return ret;
}

List::Iterator &List::Iterator::operator++() {
	item = item->next;
	return *this;
}

List::Iterator List::Iterator::operator--(int) {
	Iterator ret(item);
	item = item->prev;
	return ret;
}

List::Iterator &List::Iterator::operator--() {
	item = item->prev;
	return *this;
}

int& List::Iterator::operator *() {
    return item->value;
}

// Órai feladatok

// insert
List::Iterator List::insert(Iterator where, int value) {
    // új elem létrehozása
    ListItem *new_item = new ListItem(value);

    // az új elem mutatóinak beállítása
	// a where iterátor által mutatott elem elé
    new_item->next = where.item;
    new_item->prev = where.item->prev;

    // az új elem bekötése
    new_item->next->prev = new_item;
    new_item->prev->next = new_item;

    // visszatér az újelemre mutató iterátorral
    return Iterator(new_item);
}

// ReverseIterator
// Az "első" elem a bejárás során a lista utolsó eleme
List::ReverseIterator List::rbegin() {
    return ReverseIterator(head->prev);
}

// Az "utolsó" utáni elem a fej
List::ReverseIterator List::rend() {
    return ReverseIterator(head);
}

// Ugyanaz, mint az Iterator-nál
List::ReverseIterator::ReverseIterator(List::ListItem* _item) : item(_item) {
}

// Ugyanaz, mint az Iterator-nál
bool List::ReverseIterator::operator==(const List::ReverseIterator& other) const {
    return item == other.item;
}

// Ugyanaz, mint az Iterator-nál
bool List::ReverseIterator::operator!=(const List::ReverseIterator& other) const {
    return item != other.item;
}

// A másik irányba megyünk a listán
List::ReverseIterator List::ReverseIterator::operator++(int) {
    ReverseIterator ret(item);
    item = item->prev;
    return ret;
}

// A másik irányba megyünk a listán
List::ReverseIterator& List::ReverseIterator::operator++() {
    item = item->prev;
    return *this;
}

// A másik irányba megyünk a listán
List::ReverseIterator List::ReverseIterator::operator--(int) {
    ReverseIterator ret(item);
    item = item->next;
    return ret;
}

// A másik irányba megyünk a listán
List::ReverseIterator& List::ReverseIterator::operator--() {
    item = item->next;
    return *this;
}

// Ugyanaz, mint az Iterator-nál
int& List::ReverseIterator::operator *() {
    return item->value;
}