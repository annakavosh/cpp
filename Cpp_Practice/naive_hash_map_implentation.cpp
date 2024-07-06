#include <iostream>

class Record {
public:
    int key;
    std::string Title;
    std::string PlacementInfo;
    Record() : key(-1) {} // default contsructor to initialize key as -1

    Record(int key, const std::string& title, const std::string& placement_info):
    key(key), Title(title), PlacementInfo(placement_info) {}

};