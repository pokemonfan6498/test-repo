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



int main() {
    srand(time(nullptr));

    EntryList* list1 = new EntryList();
    EntryList* list2 = new EntryList();

    EntryList::show(list1, "key11");
    EntryList::show(list2, "key21");

    string key1random = create_key(5);
    string key2random = create_key(5);
    string key3random = create_key(5);
    string key4random = create_key(5);

    EntryList::insert(list1, "key11", rand() % 101);
    EntryList::insert(list1, key1random, rand() % 101);
    EntryList::insert(list1, key2random, rand() % 101);
    EntryList::insert(list1, "Algorytmy", rand() % 101);
    EntryList::insert(list1, key3random, rand() % 101);
    EntryList::insert(list1, key4random, rand() % 101);
    EntryList::insert(list1, "Arsenii Radionov", rand() % 101);


    string key5random = create_key(5);
    string key6random = create_key(5);
    string key7random = create_key(5);
    string key8random = create_key(5);

    EntryList::insert(list2, "key21", rand() % 101);
    EntryList::insert(list2, key5random, rand() % 101);
    EntryList::insert(list2, key6random, rand() % 101);
    EntryList::insert(list2, "Struktury danych", rand() % 101);
    EntryList::insert(list2, key7random, rand() % 101);
    EntryList::insert(list2, key8random, rand() % 101);
    EntryList::insert(list2, "Dominik Rynkiewicz", rand() % 101);

   
    EntryList::show(list1, "key11");
    EntryList::show(list2, "key21");
    EntryList::show(list1, "Algorytmy");
    EntryList::show(list2, "Struktury danych");

    EntryList::delete_entry(list1, "key11");
    EntryList::delete_entry(list2, "key21");
    EntryList::delete_entry(list1, "Algorytmy");
    EntryList::delete_entry(list2, "Struktury danych");

    EntryList::show(list1, "key11");
    EntryList::show(list1, key1random);
    EntryList::show(list1, key2random);
    EntryList::show(list1, "Algorytmy");
    EntryList::show(list1, key3random);
    EntryList::show(list1, key4random);
    EntryList::show(list1, "Arsenii Radionov");

    EntryList::show(list2, "key21");
    EntryList::show(list2, key5random);
    EntryList::show(list2, key6random);
    EntryList::show(list2, "Struktury danych");
    EntryList::show(list2, key7random);
    EntryList::show(list2, key8random);
    EntryList::show(list2, "Dominik Rynkiewicz");


    

    return 0;
}
