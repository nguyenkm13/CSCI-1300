// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3


#include <iostream>
#include "Region.h"
using namespace std;

// Default constructor
Region::Region() {
    // all data members are empty/0
    regionNum = 0;
    regionName = "";
    army = 0;
    ally = 0;
}

// constructor
Region::Region(int regionNum_, string regionName_, int army_) {
    if(regionNum_ <= 7 && regionNum_ >= 1 && army_ >= 0) {
        // region numbers are from 1-7 and army cannot be negative
        regionNum = regionNum_;
        regionName = regionName_;
        army = army_;
        ally = 0;
    } else {
        // all data members are empty
        cout << "REGION NOT ADDED: Please check that all Region attributes are in bounds.\n";
        regionNum = 0;
        regionName = "";
        army = 0;
        ally = 0;
    }
}
   
// returns region number
int Region::getRegionNum() {
    return regionNum;
}

// returns region name
string Region::getRegionName() {
    return regionName;
}

// returns army size
int Region::getArmy() {
    return army;
}

// returns ally 
int Region::getAlly() {
    return ally;
}

// sets region number
void Region::setRegionNum(int regionNum_){
    if(regionNum_ >= 1 && regionNum_ <= 7) {
        // region numbers can only be 1-7
        regionNum = regionNum_;
    } else {
        cout << "REGION NUMBER NOT UPDATED: Region numbers can only take values from 1-7\n";
    }
}

// sets region name
void Region::setRegionName(string name) {
    regionName = name;
}

// adds to army size
void Region::addToArmy(int add_){
    army += add_;
    if(army < 0) {
        // army size cannot be negative
        army = 0;
    }
}

// sets ally
void Region::setAlly(int ally_){
    if(ally_ >= 0 && ally <= 4) {
        // ally can only take values from 0-4
        ally = ally_;
    } else {
        cout << "ALLY NOT UPDATED: Ally can only take values fom 0-4\n";
    } 
}
