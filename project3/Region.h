// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3

#ifndef REGION_H
#define REGION_H

#include <iostream>
using namespace std;

class Region {
    private:
        int regionNum; // region number
        string regionName;
        int army; 
        int ally; // ally number
    public:
        // constructors
        Region();
        Region(int regionNum_, string regionName_, int army_);

        // member fucntions: getters and setters
        int getRegionNum();
        string getRegionName();
        int getArmy();
        int getAlly();

        void setRegionNum(int RegionNum_);
        void setRegionName(string name);
        void addToArmy(int add);
        void setAlly(int ally_);
};

#endif