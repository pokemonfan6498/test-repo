#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

struct Entry {
    string key;
    int value;
    Entry* next;

    Entry(string key, int value) : key(key), value(value), next(nullptr) {}
};

class EntryList {
public:
    Entry* head;

    EntryList() : head(nullptr) {}

    static Entry* find(EntryList* entry, string key) {
        Entry* current = entry->head;
        while (current) {
            if (current->key == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    static void show(EntryList* entry, string key) {
        Entry* element = find(entry, key);
        if (element) {
            cout << "Key: " << element->key << ", Value: " << element->value << endl;
        }
        else {
            cout << "Element o podanym keyu nie istnieje." << endl;
        }
    }

    static void insert(EntryList* entry, string key, int value) {
        if (find(entry, key)) {
            cout << "Element o podanym keyu już istnieje." << endl;
            return;
        }
        Entry* new_element = new Entry(key, value);
        if (!entry->head) {
            entry->head = new_element;
        }
        else {
            Entry* current = entry->head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_element;
        }
    }

    static void delete_entry(EntryList* entry, string key) {
        Entry* current = entry->head;
        Entry* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    entry->head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Element o podanym keyu nie istnieje." << endl;
    }
};

string create_key(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}
