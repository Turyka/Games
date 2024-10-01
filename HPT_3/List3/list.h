#pragma once
template <class T>
class List {
protected:
    // Osztályon belüli osztály, ami kívülről nem érhető el. Programozási elv: kifelé csak az látszódjon, aminek muszáj
    class ListItem {
        int value;
        ListItem *next, *prev;
        friend class List;
        ListItem(int _value = 0) : value(_value), next(nullptr), prev(nullptr){}
    };

    // Egy kijelölt elem kell, hogy valahol el tudjuk kezdeni
    // Kezelés szempontjából itt is mutató
    ListItem *head;
public:

    // Ez az osztály elérhető kívülről, hiszen az a célja, hogy kifelé biztosítson interfészt
    class Iterator {
        ListItem *item;
        friend class List; // Az órai insert függvény miatt kell
    public:
        Iterator(ListItem *_item = 0);
        // A lista elemein való iteráláshoz használjuk, mint ciklusváltozót, ezért szükség van pár operátorra
        bool operator== (const Iterator &other) const;
        bool operator!= (const Iterator &other) const;
		Iterator operator++(int);
		Iterator& operator++();
		Iterator operator--(int);
		Iterator& operator--();
        // Referenciával térünk vissza, ami lehetőséget ad az adat megváltoztatására
		int& operator*();
    };

    List();
    ~List();
    void newItem(int value);
    // Itt nincs print függvény, hiszen már van lehetőségünk külső kódból is elérni az elemeket
    // Viszont kellenek függvények, amik lehetővé teszik az iterátorok használatát
    Iterator begin();
    Iterator end();

    // Órai feladatok
    Iterator insert(Iterator where, int value);
	
    class ReverseIterator {
        ListItem* item;
        friend class List;
    public:
        ReverseIterator(ListItem* _item = 0);
        bool operator== (const ReverseIterator& other) const;
        bool operator!= (const ReverseIterator& other) const;
        ReverseIterator operator++(int);
        ReverseIterator& operator++();
        ReverseIterator operator--(int);
        ReverseIterator& operator--();
        int& operator*();
    };
    ReverseIterator rbegin();
    ReverseIterator rend();
};

