#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H
#include <vector>
#include <string>

struct Entry { 
    std::string key;
    std::string description;
    
    Entry() { key = "---"; }
};

class HT {
    private:
        std::vector<Entry>* hTable;
        int table_size;
        int item_count;
        int hashing(const std::string&);
    public:
        HT(int size);
        ~HT();
        bool insert(const Entry&);
        int search(const std::string&);
        bool remove(const std::string&);
        void print();
};

#endif
