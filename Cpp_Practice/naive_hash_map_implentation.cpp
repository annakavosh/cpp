#include <iostream>
#include <string>


class Record {
public:
    int key;
    std::string Title;
    std::string PlacementInfo;
    Record() : key(-1) {} // default contsructor to initialize key as -1

    Record(int key, const std::string& title, const std::string& placement_info):
        key(key), Title(title), PlacementInfo(placement_info) {}

};

class HashTable{
private:
    Record* HT_array; //pointer to store address of dynamically allocated array
    int max_length; //to store maximum number of elements in the hashmap
    int length; // to keep track of total records in the hashmap

    int H(int key) const; // hash function

public:
    HashTable(int size) : max_length(size), length(0) {
        HT_array = new Record[size];
    }

    ~HashTable() {
        delete[] HT_array;
    }

    bool Insert(const Record& item);
    bool Search(int key, Record& returnedItem);
    bool Delete(int key);
};

// define hash function
int HashTable::H(int key) const {
    return key % max_length; 
}

// define naive insert
bool HashTable::Insert(const Record& item) {
    if (length == max_length) {
        std::cerr << "Hash map is full." << std::endl;
        return false;
    }

    int index = H(item.key);
    HT_array[index] = item;
    length ++;
    return true;
}

// define naive search
bool HashTable::Search(int key, Record& returnedItem) {
    int index = H(key);
    if (HT_array[index].key == -1) {
        return false; //record not found
    }
    returnedItem = HT_array[index]; // asign the found record to the returnedItem
    return true; // to indicate that the record was found
}

// define naive delete
bool HashTable::Delete(int key) {
    int index = H(key);

    if (HT_array[index].key == key) {
        HT_array[index].key = -1; //mark the slot as empty
        length --;
        return true;
    }
    return false; // the slot is already empty or there is a different item in the slot
}


// The driver code
int main() {
    HashTable hashTable(10);

    // insert info
    hashTable.Insert(Record(101, "Intro to programming", "A2 shelf"));
    hashTable.Insert(Record(102, " data structures", "B1 shelf"));
    hashTable.Insert(Record(103, " databases", "C3 shelf"));

    // retrieve info
    Record book;
    if (hashTable.Search(101, book)) {
        std::cout << "book info for key " << book.key << ":\n";
        std::cout << "Title: " << book.Title << std::endl;
        std::cout << "Placement Info: " << book.PlacementInfo << std::endl;
    } else {
        std::cout << "no book found for key 101" << std::endl;
    }

    // delete a book info
    hashTable.Delete(101);

    if (hashTable.Search(101, book)) {
        std::cout << "book info for key " << book.key << ":\n";
        std::cout << "Title: " << book.Title << std::endl;
        std::cout << "Placement Info: " << book.PlacementInfo << std::endl;
    } else {
        std::cout << "no book found for key 101" << std::endl;
    }

    return 0;
}
 