#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

class HashEntry {
public:
    HashEntry() = default;
    HashEntry(string k, string v) : key(k), value(v){};
    void SetEntry(string k, string v) {
        key = k;
        value = v;
    };
    void ClearEntry() {
        key.clear();
        value.clear();
    }
    string GetValue() { return value; }
    string GetKey() { return key; }
    void SetValue(string v) { value = v; }

private:
    string key{};
    string value{};
};

class HashTable {
public:
    HashTable(int s) : size(s) {
        table = new HashEntry *[size];
        for (int i = 0; i < size; i++) { table[i] = new HashEntry(); }
    }
    HashTable() = delete;
    ~HashTable() {
        for (int i = 0; i < size; i++) { delete table[i]; }
        delete[] table;
    }

    bool Exists(string key) {
        int hash = Hash(key);
        int original_index = hash;

        while (true) {
            if (table[hash]->GetKey() == key) return true;
            hash = (hash + 1) % size;
            if (hash == original_index) return false;
        }
    };

    string GetValue(string key) {
        int hash = Hash(key);
        int original_index = hash;

        while (true) {
            if (table[hash]->GetKey() == key) return table[hash]->GetValue();
            hash = (hash + 1) % size;
            if (hash == original_index) return {"Empty Value"};
        }
    }

    bool Add(string key, string value) {
        int hash = Hash(key);
        int original_index = hash;

        while (true) {
            if (table[hash]->GetKey().size() == 0) {
                // empty key, set new entry
                table[hash]->SetEntry(key, value);
                return true;
            } else if (table[hash]->GetKey() == key) {
                // replace value
                cout << "key: " << key << " already exist." << endl;
                table[hash]->SetValue(value);
                return true;
            } else {
                // hash collision
                hash = (hash + 1) % size;
                // full hash
                if (hash == original_index) return false;
            }
        }
    };

    bool Delete(string key) {
        int hash = Hash(key);
        int original_index = hash;
        while (true) {
            if (table[hash]->GetKey() == key) {
                table[hash]->ClearEntry();
                return true;
            } else {
                hash = (hash + 1) % size;
                if (hash == original_index) return false;
            }
        }
    }

private:
    int Hash(string key) {
        int hash = 0;

        for (int i = 0; i < key.size(); i++) { hash += static_cast<int>(key[i]); }
        hash = hash % size;
        return hash;
    }
    int size;
    HashEntry **table;
};

TEST(HashTable, Driver) {
    HashTable hashtable(5);
    hashtable.Add("Taipei", "36.1");
    hashtable.Add("Taoyuan", "35.1");
    hashtable.Add("Taichung", "32.3");

    cout << hashtable.GetValue("Taipei") << endl;
    cout << hashtable.GetValue("Taoyuan") << endl;
    cout << hashtable.GetValue("Taichung") << endl;

    cout << boolalpha << hashtable.Exists("Taipei") << endl;
    cout << boolalpha << hashtable.Exists("Hsinchu") << endl;

    cout << "Delete: " << boolalpha << hashtable.Delete("Taichung") << endl;

    cout << hashtable.GetValue("Taichung") << endl;
}
