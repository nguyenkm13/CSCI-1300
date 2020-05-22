// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3

#ifndef HERO_H
#define HERO_H

#include <iostream>
#include "Leader.h"
using namespace std;

class Hero
{
    private:
        int base; // base region number
        string name;
        int clout;
        int wealth;
        int company;
        int warrior;
        int charisma;
        int bounty;
        bool payroll[7];
        bool territory[7];
        bool defeated;

    public:
        // constructors
        Hero();
        Hero(int base_, string name_, int wealth_, int company_, int warrior_, int charisma_);

        // getters and setters
        int getBase();
        string getName();
        int getClout();
        int getWealth();
        int getCompany();
        int getWarrior();
        int getCharisma();
        int getBounty();
        bool getPayrollAt(int regNum);
        bool getTerritoryAt(int index);
        bool getDefeated();

        void setBase(int base_);
        void setName(string name_);
        void setClout(int clout_);
        void setWealth(int wealth_);
        void setCompany(int company_);
        void setWarrior(int warrior_);
        void setCharisma(int charisma_);
        void setBounty(int bounty_);
        void eliminate();

        // add to attribute values
        void addClout(int delta);
        void addWealth(int delta);
        void addCompany(int delta);
        void addWarrior(int delta);
        void addCharisma(int delta);
        void addBounty(int delta);

        // edit leader and region control
        void addToPayroll(int regNum);
        void removeFromPayroll(int regNum);
        void addTerritory(int regNum);
        void removeTerritory(int regNum);
};
#endif