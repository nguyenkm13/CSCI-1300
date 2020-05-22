// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Hero.h"
#include "Leader.h"
#include "Region.h"
using namespace std;

class Game
{
    private:
        Hero users[4]; 
        Hero library[20]; 
        Leader leaders[7]; 
        Region regions[7];
        int numUsers;
        int numLeaders;
        int numRegions;
        int sizeLibrary;
        int winner;
    public:
        Game();

        // getters and setters
        Hero getUserAt(int userNum); 
        Hero getHeroAt(int heroNum);
        Leader getLeaderAt(int regNum); 
        Region getRegionAt(int regNum); 
        int getNumUsers();
        int getNumLeaders();
        int getNumRegions();
        int getSizeLibrary();
        int getWinner();
        int getUserPayroll(int userNum);
        void setUserAt(int userNum, Hero user_);
        void setHeroAt(int heroNum, Hero hero_); ///
        void setLeaderAt(int regNum, Leader leader_);
        void setRegionAt(int regNum, Region region_);
        void setNumUsers(int numUsers_);
        void setNumLeaders(int numLeaders_);
        void setNumRegions(int numRegions_);
        void setSizeLibrary(int size);
        void setWinner(int winner_);

        // functions that read txt files
        int readHeroes(string filename);
        int readLeaders(string filename);
        int readRegions(string filename);

        // remove user/hero/leader/region from game arrays
        void removeUserAt(int userNum);
        void removeHeroAt(int heroNum);
        void removeLeaderAt(int leaderNum);
        void removeRegionAt(int regionPos);

        // view game stats
        void viewHero(int heroNum);
        void viewUser(int userNum);
        void viewLeader(int regNum);
        void viewRegion(int regNum);

        // battle/bribe functions
        bool battleLeader(int userNum, int regNum);
        bool battleUsers(int atk, int def);
        bool bribeLeader(int userNum, int regNum);
        bool conquer(int userNum, int regNum);
        int conquest(int userNum);

        // end of round functions
        int checkWinner(int userNum);
        void checkBonus(int userNum);
        void clearUser(int userNum);

        // check if game can be started
        bool startGame(); 
};
#endif