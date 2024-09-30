#pragma once

// Sablonos List osztály, hogy bármilyen típusú elemekkel dolgozhassunk
template <class T>
class List {
protected:
    // Sablonos belső osztály a lista elemeinek tárolására
    class ListItem {
        T value;
        ListItem* next, * prev;
        friend class List;
        ListItem(T _value = T()) : value(_value), next(nullptr), prev(nullptr) {}
    };

    ListItem* head;

public:
    class Iterator {
        ListItem* item;
        friend class List;
    public:
        Iterator(ListItem* _item = nullptr) : item(_item) {}
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
        Iterator operator++(int) {
            Iterator ret(item);
            item = item->next;
            return ret;
        }
        Iterator& operator++() {
            item = item->next;
            return *this;
        }
        Iterator operator--(int) {
            Iterator ret(item);
            item = item->prev;
            return ret;
        }
        Iterator& operator--() {
            item = item->prev;
            return *this;
        }
        T& operator*() { return item->value; }
    };

    List() : head(new ListItem()) {
        head->next = head->prev = head;
    }

    ~List() {
        ListItem* current = head->next;
        while (current != head) {
            current = current->next;
            delete current->prev;
        }
        delete head;
    }

    void newItem(T value) {
        ListItem* new_item = new ListItem(value);
        new_item->next = head->next;
        new_item->prev = head;
        head->next->prev = new_item;
        head->next = new_item;
    }

    Iterator begin() { return Iterator(head->next); }
    Iterator end() { return Iterator(head); }

    Iterator insert(Iterator where, T value) {
        ListItem* new_item = new ListItem(value);
        new_item->next = where.item;
        new_item->prev = where.item->prev;
        new_item->next->prev = new_item;
        new_item->prev->next = new_item;
        return Iterator(new_item);
    }

    class ReverseIterator {
        ListItem* item;
        friend class List;
    public:
        ReverseIterator(ListItem* _item = nullptr) : item(_item) {}
        bool operator==(const ReverseIterator& other) const { return item == other.item; }
        bool operator!=(const ReverseIterator& other) const { return item != other.item; }
        ReverseIterator operator++(int) {
            ReverseIterator ret(item);
            item = item->prev;
            return ret;
        }
        ReverseIterator& operator++() {
            item = item->prev;
            return *this;
        }
        ReverseIterator operator--(int) {
            ReverseIterator ret(item);
            item = item->next;
            return ret;
        }
        ReverseIterator& operator--() {
            item = item->next;
            return *this;
        }
        T& operator*() { return item->value; }
    };

    ReverseIterator rbegin() { return ReverseIterator(head->prev); }
    ReverseIterator rend() { return ReverseIterator(head); }
};