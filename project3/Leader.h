// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3

#ifndef LEADER_H
#define LEADER_H
#include <iostream>
using namespace std;

class Leader
{
    private:
        int regionNum;
        string leaderName;
        int warrior;
        int loyalty;
        int salary;
        int ally;
    public:
        // constructors
        Leader();
        Leader(int regionNum_, string leaderName_, int warrior_, int loyalty_, int salary_);

        // member functions
        int getRegionNum();
        string getLeaderName();
        int getWarrior();
        int getSalary();
        int getAlly();
        int getLoyalty();
       
        void setRegionNum(int regionNum_);
        void setLeaderName(string leaderName_);
        void setWarrior(int warrior_);
        void setSalary(int salary_);
        void setAlly(int ally_);
        void addLoyalty(int delta);
};

#endif

