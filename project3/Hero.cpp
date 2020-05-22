// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3 

#include <iostream>
#include "Hero.h"
#include "Region.h"
using namespace std;

// default constructor, all data members are empty
Hero::Hero() {
    base = 0;
    name = "";
    clout = 0;
    wealth = 0;
    company = 0;
    warrior = 0;
    charisma = 0;
    bounty = 0;  
    for(int i = 0; i < 7; i++){
        payroll[i] = 0;
        territory[i] = 0;
    }
    defeated = 0;
}

// constructor
Hero::Hero(int base_, string name_, int wealth_, int company_, int warrior_, int charisma_) {
    if(base_ > 0 && base_ <= 7 && wealth_ >= 0 && company_ >= 0 
    && warrior_ >= 0 && warrior_ <= 10 && charisma_ >= 0 && charisma_ <= 10) {
        base = base_;
        name = name_;
        clout = 0;
        wealth = wealth_;
        company = company_;
        warrior = warrior_;
        charisma = charisma_;
        bounty = 0;

        for(int i = 0; i < 7; i++){
            payroll[i] = 0;
            territory[i] = 0;
        }
        defeated = 0;
    } else {
        // if initial conditions are not met, default hero is empty
        cout << "HERO NOT ADDED: Please check that all Hero attributes are in bounds.\n";
        base = 0;
        name = "";
        clout = 0;
        wealth = 0;
        company = 0;
        warrior = 0;
        charisma = 0;
        bounty = 0;  
        for(int i = 0; i < 7; i++){
            payroll[i] = 0;
            territory[i] = 0;
        }
        defeated = 0;
    }
    
}

// returns base region number
int Hero::getBase() {
    return base;
}

// returns hero name
string Hero::getName() {
    return name;
}

// returns clout
int Hero::getClout() {
    return clout;
}

// returns wealth
int Hero::getWealth() {
    return wealth;
}

// returns company
int Hero::getCompany() {
    return company;
}

// returns warrior
int Hero::getWarrior() {
    return warrior;
}

// returns charisma
int Hero::getCharisma() {
    return charisma;
}

// returns bounty
int Hero::getBounty() {
    return bounty;
}

// returns a boolean indicating whether a leader is on the payroll
bool Hero::getPayrollAt(int regNum) {
    return payroll[regNum -1];
}

// returns a boolean indicating whether a the user controlls a region
bool Hero::getTerritoryAt(int regNum) {
    return territory[regNum -1];
}

// returns a boolean indicating if the user has been defeated
bool Hero::getDefeated() {
    return defeated;
}

// sets the hero's base region 
void Hero::setBase(int base_) {
    if(base_ >= 1 && base_ <= 7) {
        base = base_;
    } else {
        cout << "BASE NOT UPDATED: Base can only take values from 1-7.\n";
    }
}

// sets the hero's name
void Hero::setName(string name_) {
    name = name_;
}

// sets the hero's clout
void Hero::setClout(int clout_) {
    if(clout >= 0) {
        // clout cannot be negative
        clout = clout_;
    } else {
        cout << "CLOUT NOT UPDATED: Clout can only take values greater than or equal to zero.\n";
    }  
}

// sets the hero's wealth
void Hero::setWealth(int wealth_) {
    if(wealth_ >= 0) {
        // wealth cannot be negative
        wealth = wealth_;
    } else {
        cout << "WEALTH NOT UPDATED: Wealth can only take values greater than or equal to zero.\n";
    } 
}

// sets company size
void Hero::setCompany(int company_) {
    if(company_ >= 0) {
        // companhy cannot be negative
        company = company_;
    } else {
        cout << "COMPANY SIZE NOT UPDATED: Company size can only take values greater than or equal to zero.\n";
    }   
}

// sets warrior score
void Hero::setWarrior(int warrior_) {
    if(warrior_ >= 0 && warrior_ <= 10) {
        // warrior score can have a max initial value of 10
        warrior = warrior_;
    } else {
        cout << "WARROR SCORE NOT UPDATED: Warrior scores can only take values from 0-10.\n";
    }
}

// sets charisma
void Hero::setCharisma(int charisma_) {
    if(charisma_ >= 0 && charisma_ <= 10) {
        // charisma can have a max inital value of 10
        charisma = charisma_;
    } else {
        cout << "CHARISMA NOT UPDATED:\nCharisma scores can only take values from 0-10.\n";
    }
}

// sets bounty
void Hero::setBounty(int bounty_) {
    if(bounty_ >= 0) {
        // bounty cannot be negative
        bounty = bounty_;
    } else {
        cout << "BOUNTY NOT UPDATED: Bounties can only take values greater than or equal to zero.\n";
    }
}

// sets defeated to true
void Hero::eliminate() {
    defeated = 1;
}

// adds clout 
void Hero::addClout(int delta) {
    clout = clout + delta;
    // clout cannot be less than zero
    if(clout < 0) {
        clout = 0;
    }
}

// adds to wealth
void Hero::addWealth(int delta) {
    wealth = wealth + delta;
    
    // wealth cannot be negative
    if(wealth < 0) {
        wealth = 0;
    }
}

// adds to company size
void Hero::addCompany(int delta) {
    company = company + delta;
    if(company < 0) {
        // company cannot be less than zero
        company = 0;
    }
}

// adds to warrior
void Hero::addWarrior(int delta) {
    warrior = warrior + delta;
    if(warrior < 0) {
        // warrior cannot be less than zero
        warrior = 0;
    } else if (warrior > 10) {
        // warrior cannot be greater than 10
        warrior = 10;
    }
}

// adds to charisma
void Hero::addCharisma(int delta) {
    charisma = charisma + delta;
    if(charisma < 0) {
        // charisma cannot be less than 0
        charisma = 0;
    } else if (charisma > 10) {
        // charisma cannot be greater than 10
        charisma = 10;
    }
}

// add to bounty
void Hero::addBounty(int delta) {
    bounty = bounty + delta;
    // bounty cannot be less than zero
    if(bounty < 0) {
        bounty = 0;
    }
}

// adds a leader to the payroll
void Hero::addToPayroll(int regNum) {
    int index = regNum - 1;
    if(!payroll[index]) {
        // if the leader is not already on the payroll
        payroll[index] = 1;
        clout++; // +1 clout for each leader added to the payroll
    } else {
        cout << "ERROR: This leader is already on your payroll\n";
    }
}

// places a region under a user's control
void Hero::addTerritory(int regNum) {
    int regIndex = regNum - 1;
    if(regNum < 1 || regNum > 7) {
        cout << "ERROR: There are only seven regions\n";
    } else {
        if(!territory[regIndex]) {
            // if the region is not already under the user's control
            territory[regIndex] = 1;
            clout++; // +1 clout for each region added
        } else {
            cout << "ERROR: You already control this territory\n";
        }
    }
}

// removes a leader from the payroll
void Hero::removeFromPayroll(int regNum) {
    int index = regNum - 1;
    if(regNum > 0 && regNum <= 7) {
        if(payroll[index]) {
            payroll[index] = 0;
            clout--; // -1 clout for each region removed
        } else {
            cout << "ERROR: This leader is not on the payroll\n";
        }
    } else {
        cout << "ERROR: There are only seven leaders\n";
    }
}

// removes a territory from user control
void Hero::removeTerritory(int regNum) {
    int index = regNum -1;
    if(regNum < 1 || regNum > 7) {
        cout << "ERROR: There are only seven regions\n";
    } else {
        if(territory[index] != 0) {
            territory[index] = 0;
            clout--; // -1 clout for each region removed
        } else {
            cout << "ERROR: You do not control this region\n";
        }
    }
}
