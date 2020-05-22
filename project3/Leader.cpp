// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3

#include <iostream>
#include "Leader.h"
using namespace std;


// default constructor
Leader::Leader() {
    regionNum= 0;
    string leaderName = "";
    warrior = 0;
    salary = 0;
    ally = 0;
    loyalty = 0;
}

// constructor
Leader::Leader(int regionNum_, string leaderName_,int warrior_, int loyalty_, int salary_) {
    warrior = warrior_;
    salary = salary_;
    ally = 0;
    leaderName = leaderName_;
    regionNum = regionNum_;
    loyalty = loyalty_;
}

// returns region number
int Leader::getRegionNum() {
    return regionNum;
}

// returns leader name
string Leader::getLeaderName() {
    return leaderName;
}

// returns warrior score
int Leader::getWarrior() {
    return warrior;
}

// returns salary
int Leader::getSalary() {
    return salary;
}

// returns ally number
int Leader::getAlly() {
    return ally;
}

// returns loyalty score
int Leader::getLoyalty() {
    return loyalty;
}

// sets the region number
void Leader::setRegionNum(int regionNum_) {
    if(regionNum_ >= 1 && regionNum_ <= 7) {
        // region number can only take values from 1-7
        regionNum = regionNum_;
    } else {
        cout << "Region numbers can only take values from 1-7.\n";
    }
}

// sets leader name
void Leader::setLeaderName(string leaderName_) {
    leaderName = leaderName_;
}

// sets warrior score
void Leader::setWarrior(int warrior_) {
    if(warrior_ >= 0 && warrior_ <= 10) {
        warrior = warrior_;
    } else {
        cout << "Warrior scores can only take values from 0 to 10\n";
    }  
}

// sets salary
void Leader::setSalary(int salary_) {
    if(salary_ >= 0) {
        // salary cannot be negative
        salary = salary_;
    } else {
        cout << "Salaries can only take values greater than or equal to zero.\n";
    } 
}

// sets ally number
void Leader::setAlly(int ally_) {
    if(ally_ >= 0 && ally_ <= 4) {
        // ally can only take values from 0 to 4
        ally = ally_;
    } else {
        cout << "Ally can only take values from 0-4.\n";
    }  
}

// adds to loyalty score
void Leader::addLoyalty(int delta) {
    loyalty = loyalty + delta;

    // loyalty can only take values from 0 to 10
    if(loyalty < 0) {
        loyalty = 0;
    } else if (loyalty > 10) {
        loyalty = 10;
    }
}