#include <gtest/gtest.h>
#include <iostream>
#include <string>

class HashEntry {
public:
    HashEntry() = default;
    HashEntry(std::string k, std::string v) : key(k), value(v){};
    void SetEntry(std::string k, std::string v) {
        key = k;
        value = v;
    };
    void ClearEntry() {
        key.clear();
        value.clear();
    }
    std::string GetValue() { return value; }
    std::string GetKey() { return key; }
    void SetValue(std::string v) { value = v; }

private:
    std::string key{};
    std::string value{};
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

    bool Exists(std::string key) {
        int hash = Hash(key);
        int original_index = hash;

        while (true) {
            if (table[hash]->GetKey() == key) return true;
            hash = (hash + 1) % size;
            if (hash == original_index) return false;
        }
    };

    std::string GetValue(std::string key) {
        int hash = Hash(key);
        int original_index = hash;

        while (true) {
            if (table[hash]->GetKey() == key) return table[hash]->GetValue();
            hash = (hash + 1) % size;
            if (hash == original_index) return {"Empty Value"};
        }
    }

    bool Add(std::string key, std::string value) {
        int hash = Hash(key);
        int original_index = hash;

        while (true) {
            if (table[hash]->GetKey().size() == 0) {
                // empty key, set new entry
                table[hash]->SetEntry(key, value);
                return true;
            } else if (table[hash]->GetKey() == key) {
                // replace value
                std::cout << "key: " << key << " already exist." << std::endl;
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

    bool Delete(std::string key) {
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
    int Hash(std::string key) {
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

    std::cout << hashtable.GetValue("Taipei") << std::endl;
    std::cout << hashtable.GetValue("Taoyuan") << std::endl;
    std::cout << hashtable.GetValue("Taichung") << std::endl;

    std::cout << std::boolalpha << hashtable.Exists("Taipei") << std::endl;
    std::cout << std::boolalpha << hashtable.Exists("Hsinchu") << std::endl;

    std::cout << "Delete: " << std::boolalpha << hashtable.Delete("Taichung") << std::endl;

    std::cout << hashtable.GetValue("Taichung") << std::endl;
}
