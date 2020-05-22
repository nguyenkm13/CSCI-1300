// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3 

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <time.h>
#include "Game.h"
using namespace std;

// This function prompts the user to verify their selection. It returns a boolean value that indicates the player's response
bool verify() {
    string input;
    cout << "Continue? (Y/N)\n";
    cin >> input;
    // if the user enters a variant of "yes"
    if(input == "y" || input == "Y" || input == "yes" || input == "Yes") {
        return 1;
    } else {
        return 0;
    }
}

//This function generates and returns a random integer between given starting value and ending value, inclusive
int random(int begin, int end) {
    int dif = end - begin + 1;
    srand(time(NULL));
    int val = rand() % dif + begin;
    return val;
}

// converts all lowercase letters in a string to upper case
string toUpper(string input) {
    string output = "";
    for(int i = 0; i < input.length(); i++) {
        // if the character is a lowercase letter, convert to upper case
        if(input[i] >= 'a' && input[i] <='z') {
            output += input[i] - 32;
        }

        // if the character is not a lowercase letter, do nothing
        else {
           output += input[i];
        }
    }
    // returns the converted string
    return output;
}

// This fucntion takes a string , splits it by a delimeter, then stores the split pieces into an array
// Returns the number of pieces the string was split into
int split(string input, char delimiter, string arr[], int size)
{
    input.push_back(delimiter);
    int pos = 0;
    for(int i = 0; i < input.length(); i++) {
        //Deletes multiple occurances of delimiters
        while(input[0] == delimiter) {
            input.erase(0,1);
        }
        
        //places the substring piece between delimiters into the array
        if(input[i] == delimiter)
        {
            arr[pos] = input.substr(0, i);
            input.erase(0, i + 1); //clears the begining of the string
            i = 0;
            pos ++; // Adds one to the piece counter
        }
    }
    
    // If the string is split into more pieces than the size of the array, then it returns -1.
    if(pos > size) {
        return -1;
    } else {
        return pos;
    }
}

// Default contructor, all data members are empty
Game :: Game() {
    Hero emptyH;
    for(int i = 0; i < 4; i++) {
        users[i] = emptyH;
    }
    Leader emptyL;
    Region emptyR;
    for(int j = 0; j < 7; j++) {
        leaders[j] = emptyL;
        regions[j] = emptyR;
    }
    for(int k = 0; k < 20; k++) {
        library[k] = emptyH;
    }
    numUsers = 0;
    numLeaders = 0;
    numRegions = 0;
    sizeLibrary = 0;
    winner = 0;
}

// Returns a user with a given user number
Hero Game::getUserAt(int userNum) {
    if(userNum >= 1 && userNum <= 4) {
        return users[userNum - 1];
    } else {
        Hero empty;
        cout << "ERROR: Please choose a user number from 1-4\n";
        return empty;
    }
}

// Returns a hero with a given hero number
Hero Game::getHeroAt(int heroNum) {
    if(heroNum <= 0 || heroNum > sizeLibrary) {
        cout << "ERROR: There are only " << sizeLibrary << " heroes in the library\n";
        Hero empty;
        return empty;
    } else {
        return library[heroNum - 1];
    }
}

// Returns a leader with a given region number
Leader Game::getLeaderAt(int regNum) {
    if(regNum > 0 && regNum <= 7) {
        return leaders[regNum - 1];
    } else {
        Leader empty;
        cout << "ERROR: Please choose a region number from 1-7\n";
        return empty;
    }
}

// returns a region with a given region number
Region Game::getRegionAt(int regNum){
    if(regNum > 0 && regNum <= 7) {
        return regions[regNum - 1];
    } else {
        Region empty;
        cout << "ERROR: Please choose a region number from 1-7\n";
        return empty;
    }
}

// returns the number of users in the game
int Game::getNumUsers() {
    return numUsers;
}

// returns the number of leaders in the game
int Game::getNumLeaders() {
    return numLeaders;
}

// returns the number of regions in the game
int Game::getNumRegions() {
    return numRegions;
}

// returns the size of the hero library
int Game::getSizeLibrary(){
    return sizeLibrary;
}

// returns the winner number, or '0'
int Game::getWinner() {
    return winner;
}

// returns a user's total payroll 
int Game::getUserPayroll(int userNum) {
    int totalPayroll = 0;
    Hero tempUser = users[userNum -1];

    // sums the salaries of leaders if they are on the payroll
    for(int i = 0; i < 7; i++) {
        if(tempUser.getPayrollAt(i+1)) {
            totalPayroll += leaders[i].getSalary();
        }
    }
    return totalPayroll;
}

// sets the user at a certain user number
void Game::setUserAt(int userNum, Hero user_) {
    int matches = 0;
    bool empty = 1;

    string search = toUpper(user_.getName());

    // searches the library for existing matches
    for(int i = 0; i < 4; i++) {
        if(i != userNum -1) {
            if(toUpper(users[i].getName()) == search) {
                matches++;
            }
        } 
    }

    if (userNum <= 0 || userNum > 4) {
        cout << "USER NOT UPDATED: User numbers must be from 1-4\n";
    } else if(matches > 0) {
        cout <<"USER NOT UPDATED: This hero has already been claimed\n";
    } else {
        
        users[userNum - 1] = user_;
        cout << "User " << userNum << " has been updated\n"; 
        numUsers++;
        
    }
}

// Updates a hero at a hero number
void Game::setHeroAt(int heroNum, Hero hero_) {
    if(heroNum > 0 && heroNum < 20) {
        cout << "HERO NOT UPDATED: The library can only hold 20 heroes\n";
    } else {
        library[heroNum - 1] = hero_;
    }
}

// updates a leader at a region number
void Game::setLeaderAt(int regNum, Leader leader_) {
    if(regNum > 0 && regNum <= 7) {
        leaders[regNum - 1] = leader_;
    } else {
        cout << "LEADER NOT UPDATED: Region numbers must be from 1-7\n";
    }
}

// updates a region at a region number
void Game::setRegionAt(int regNum, Region region_) {
    if(regNum > 0 && regNum <= 7) {
        regions[regNum - 1] = region_;
    } else {
        cout << "REGION NOT UPDATED: Region numbers must be from 1-7\n";
    }
}

// set the number of users
void Game::setNumUsers(int numUsers_) {
    if(numUsers_ <= 4 && numUsers_ >= 0) {
        numUsers = numUsers_;
    } else {
        cout << "ERROR: Maximum of four players allowed\n";
    }
}

// set the number of leaders
void Game::setNumLeaders(int numLeaders_) {
    if(numLeaders_ >= 0 && numLeaders_ <= 7) {
        numLeaders = numLeaders_;
    } else {
        cout << "ERROR: Maximum of seven leaders allowed\n";
    }
}

// set the number of regions
void Game::setNumRegions(int numRegions_) {
    if(numRegions_ >= 0 && numRegions_ <=7) {
        numRegions = numRegions_;
    } else {
        cout << "ERROR: Maximum of seven regions allowed\n";
    }
}

// sets the size of the library
void Game::setSizeLibrary(int size) {
    if(size >= 0 && size <= 20) {
        // The library can hold up to 20 heroes
        sizeLibrary = size;
    } else {
        cout << "ERROR: The Contender Library can hold up to 20 heroes\n";
    }
}

// sets the winner number
void Game::setWinner(int winner_) {
    if(winner_ < 0 || winner_ > 4) {
        cout << "ERROR: There are only four players\n";
    } else {
        winner = winner_;
    }
}

// reads a heroes file
int Game::readHeroes(string filename) {
    ifstream file(filename);

    if(!file.is_open()) {
        cout << "File could not be opened\n" << endl;
        return -1;
    }
    else
    {
        cout << "--- Loading contenders file---\n";
        string line;
        string arr[6];
        int lineCount = 0;
        while(getline(file,line) && sizeLibrary <= 20) {
            lineCount++;

            // stores the line into a temporary array
            split(line, ',', arr, 6);
            int errors = 0;
            int tempBase = stoi(arr[0]);
            string tempName = arr[1];
            int tempCompany = stoi(arr[2]);
            int tempWealth = stoi(arr[3]);
            int tempWarrior = stoi(arr[4]);
            int tempCharisma = stoi(arr[5]);

            cout << "Line " << lineCount << ":";

            string search = toUpper(tempName);
            int matchedName = 0;

            // searches for existing matches in the library
            for(int i = 0; i < 20; i++) {
                if(toUpper(library[i].getName()) == search) {
                    matchedName++;
                }
            }
            
            if (matchedName > 0) {
                cout << "\n   A contender with that name already exists in the library\n";
                errors++;
            } 
            if(tempBase < 1 || tempBase > 7) {
                cout << "\n   Initial base can only take values from 1 to 7\n";
                errors++;
            } 
            if (tempName == "") {
                cout << "\n   Contender name cannot be empty\n";
                errors++;
            } 
            if (tempWealth < 0 || tempWealth > 10000) {
                cout << "\n   Initial wealth can only take values from 0 to 10,000\n";
                errors++;
            } 
            if(tempCompany < 0 || tempCompany > 8000) {
                cout << "\n   Initial company can only take values from 0 to 5,000\n";
                errors++;
            } 
            if(tempWarrior < 0 || tempWarrior > 10) {
                cout << "\n   Initial warrior score can only take values from 0 to 10\n";
                errors++;
            } 
            if(tempCharisma < 0 || tempCharisma > 10) {
                cout << "\n   Initial charisma score can only take values from 0 to 10\n";
                errors++;
            } 
            if(tempCharisma + tempWarrior > 10 ) {
                cout << "\n   Contendenders can only begin with a maximum of 10 attribute points\n";
                errors++;
            }

            if(errors == 0) {
                // stores the hero in the library
                Hero tempUser(tempBase, tempName, tempWealth, tempCompany, tempWarrior, tempCharisma); 
                library[sizeLibrary] = tempUser;
                sizeLibrary++;
                cout << " SUCCESS\n";
                
            } else {
                // does not store the hero if there are any errors
                cout << "CONTENDER WAS NOT ADDED TO THE LIBRARY\n";
            }  
        }
        file.close(); // closes the file
        return sizeLibrary;
    }
}

// this fucntion reads a txt file of leaders
int Game::readLeaders(string filename) {
    ifstream file(filename);

    if(!file.is_open()) {
        cout << "File could not be opened.\n";
        return -1;
    } else {
        string line;
        string arr[6];
        int lineCount = 0;

        cout << "--- Loading leaders file ---\n";
        while(getline(file, line) && numLeaders <= 7) {
            lineCount++;

            // splits each line and stores split pieces into an array
            int errors = 0;
            split(line, ',', arr, 6);
            int tempRegNum = stoi(arr[0]);
            string tempLeaderName = arr[1];
            int tempWarrior = stoi(arr[2]);
            int tempLoyalty = stoi(arr[3]);
            int tempSalary = stoi(arr[4]);
            
            cout << "Line " << lineCount << ":";


            // searches the current leaders for duplicates
            string search = toUpper(tempLeaderName);
            int matchedName = 0;
            int matchedNum = 0;
            for(int i = 0; i < 7; i++) {
                if(toUpper(leaders[i].getLeaderName()) == search) {
                    matchedName++;
                }
                if(leaders[i].getRegionNum() == tempRegNum) {
                    matchedNum++;
                }
            }
            
            if(matchedName > 0) {
                cout << "\n   This leader already exists in the library\n";
                errors++;
            }
            if(matchedNum > 0) {
                cout << "\n    A leader is already assigned to this region\n";
                errors++;
            }
            if(tempWarrior > 10 || tempWarrior < 0) {
                cout << "\n   Leader can have a maximum warrior score of 10\n";
                errors++;
            }
            if(tempSalary < 0) {
                cout << "\n   Salary cannot be less than zero\n";
                errors++;
            }

            if (errors > 0) {
                // leader not added if there are any errors
                cout << "LEADER NOT ADDED\n";
            } else {
                // stores the leader to the game
                Leader tempLeader(tempRegNum, tempLeaderName, tempWarrior, tempLoyalty, tempSalary);
                leaders[tempRegNum - 1] = tempLeader;
                numLeaders++;
                cout << "SUCCESS\n";
            }
        }
        file.close(); // closes the file
        return numLeaders;
    }
}

// reads a txt file of regions
int Game::readRegions(string filename){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "File could not be opened.\n";
        return -1;
    }
    else {
        cout << "--- Loading regions file ---\n";
        string line;
        string arr[3];
        int lineCount = 0;
        while(getline(file, line) && numRegions <= 7) 
        {
            lineCount++;
            int errors = 0, matchedName = 0, matchedNum = 0;

            // stores the components of each line into an array
            split(line, ',', arr, 3);
            int tempRegNum = stoi(arr[0]);
            string tempRegName = arr[1];
            int tempArmy = stoi(arr[2]);
            
            cout << "Line " << lineCount << ": ";

            string search = toUpper(tempRegName);

            // searches the current regions for duplicates
            for(int i = 0; i < 7; i++) {
                if(toUpper(regions[i].getRegionName()) == search) {
                    matchedName++;
                }
                if(regions[i].getRegionNum() == tempRegNum) {
                    matchedNum++;
                }
            }

            if(matchedName > 0) {
                cout << "\n   A region with this name alreasy exists\n";
                errors++;
            }
            if(matchedNum > 0) {
                cout << "\n   A region with this number already exists\n";
                errors++;
            }
            if(tempRegNum < 1 || tempRegNum > 7) {
                cout << "\n   Region numbers must take value from 1-7\n";
                errors++;
            }
            if(tempArmy < 0) {
                cout << "\n    Army size cannot be less than zero\n";
                errors++;
            }

            if(errors > 0) {
                // leader not added if there are any errors
                cout << "REGION WAS NOT ADDED\n";
            } else {
                // stores the leader to the game
                Region temp(tempRegNum, tempRegName, tempArmy);
                regions[tempRegNum -1] = temp;
                numRegions++;
                cout << "SUCCESS\n";
            }
            
        }
        file.close(); // closes the file
        return numRegions;
    }
}

// this function removes a user from the game
void Game::removeUserAt(int userNum) {
    if(userNum < 1 || userNum > 4) {
        cout << "NO USER REMOVED: User number must take values from one to four\n";
    } else if (users[userNum - 1].getName() == "") {
        cout << "There is no user to remove\n";
    } else {
        Hero empty;
        users[userNum - 1] = empty;
    }
}

// removes a hero from the heroes library
void Game::removeHeroAt(int heroNum) {
    if(heroNum < 1 || heroNum > 20) {
        cout << "NO HERO REMOVED FROM LIBRARY: The library can hold up to 20 leaders\n";
    } else if (library[heroNum -1].getName() == "") {
        cout << "There is no hero to remove\n";
    } else {
        // stores an empty hero to the remove location
        Hero empty;
        library[heroNum - 1] = empty;
    }
}

// removes a leader from the game
void Game::removeLeaderAt(int leaderNum) {
    if(leaderNum < 1 || leaderNum > 7) {
        cout << "LEADER NOT REMOVED: There are only seven leaders\n";
    } else if (leaders[leaderNum - 1].getLeaderName() == "") {
        cout << "There is no leader to remove\n";
    } else {
        // stores an empty leader at the remove location
        Leader empty;
        leaders[leaderNum - 1] = empty;
    }
}

// removes a region from the game
void Game::removeRegionAt(int regionPos) {
    if(regionPos < 1 || regionPos > 7) {
        cout << "REGION NOT REMOVED: There are only seven regions\n";
    } else if (regions[regionPos - 1].getRegionName() == "") {
        cout << "There is no region to remove\n";
    } else {
        // stores an empty region at the remove location
        Region empty;
        regions[regionPos - 1] = empty;
    }
}

// outpus inital stats for a hero in the library
void Game::viewHero(int heroNum) {
    if(heroNum >= 1 && heroNum <= sizeLibrary) {
        int i = heroNum - 1;
        
        // if the hero exists in the library
        if(library[i].getName() != "") {
            cout << "------------------------------\n" << endl;
            Hero temp = library[i];
            cout << heroNum << ". " << temp.getName() << endl;
            int tempBase = library[i].getBase();
            cout << "   Base region: (" << tempBase << ") " << regions[tempBase - 1].getRegionName() << endl;
            cout << "   Wealth: $" << library[i].getWealth() << endl;
            cout << "   Company size: " << library[i].getCompany() << endl;
            cout << "   Warrior score: " << library[i].getWarrior() << endl;
            cout << "   Charimsa score: " << library[i].getCharisma() << endl;
        }
    }
    
}

// This function outputs the game stats for a user
void Game::viewUser(int userNum) {
    int i = userNum - 1;
    if(userNum < 1 || userNum > 4) {
        cout << "ERROR: There are only four users\n";
    } else {
        cout << "Player " << userNum << ": ";
        if(users[i].getName() == "") {
            // if the user doesn't exist
            cout << "EMPTY\n";
        } else {
            Hero temp = users[i];
            cout << temp.getName();

            // if the user has been defeated
            if(temp.getDefeated() == 1) {
                cout << " - DEFEATED";
            }
            int territories = 0;
            int leaders = 0;

            // counts the number of leaders and territories that the user controls
            for(int j = 0; j < 7; j++) {
                int tempRegNum = j + 1;
                territories += users[i].getTerritoryAt(tempRegNum);
                leaders += users[i].getPayrollAt(tempRegNum);
            }

            int tempBase = users[i].getBase();
            cout << "\n\n       Base region: (" << tempBase << ") " << regions[tempBase - 1].getRegionName() << endl;
            cout << "       Clout: " << users[i].getClout() << endl;
            cout << "       Number of territories: " << territories << endl;
            cout << "       Number of leaders on payroll: " << leaders << endl;
            cout << "       Wealth: $" << users[i].getWealth() << endl;
            cout << "       Company size: " << users[i].getCompany() << " soldiers" << endl;
            cout << "       Warrior score: " << users[i].getWarrior() << endl;
            cout << "       Charimsa score: " << users[i].getCharisma() << endl;
            cout << "       Bounty: $" << users[i].getBounty() << endl;
            cout << "       Payroll: $" << getUserPayroll(userNum) << endl;
        }
    }
}

// This function outpus the game stats of a leader
void Game::viewLeader(int regNum) {
    int i = regNum - 1;
    if(regNum < 1 || regNum > 7) {
        cout << "ERROR: There are only seven leaders\n";
    } else {
        cout << regNum << ". ";

        if(leaders[i].getLeaderName() == "") {
            // if the leader doesn't exist in the game
            cout << "EMPTY\n";
        } else {
            Leader temp = leaders[i];
            int tempAlly = temp.getAlly();
            
            cout << temp.getLeaderName() << endl;
            cout << "       Region: " << regions[i].getRegionName() << endl;
            cout << "       Warrior score: " << leaders[i].getWarrior() << endl;
            cout << "       Loyalty: " << leaders[i].getLoyalty() << endl;
            cout << "       Salary: $" << leaders[i].getSalary() << endl;
            cout << "       Allegiance: ";

            if(tempAlly == 0) {
                // if ally = 0, the leader is neutral
                cout << "NEUTRAL\n";
            } else {
                // outputs the leader's ally
                string allyName = users[tempAlly - 1].getName();
                cout << tempAlly << ") " << toUpper(allyName) << endl;
            }
        }
    }
}

// Outputs the game stats for a region
void Game::viewRegion(int regNum) {
    int i = regNum - 1;
    if(regNum < 1 || regNum > 7) {
        cout << "ERROR: There are only seven regions\n";
    } else {
        cout << regNum << ". ";
        if(regions[i].getRegionName() == "") {
            // if the region doesn't exist in the game
            cout << "EMPTY\n";
        } else {
            Region temp = regions[i];
            int tempAlly = temp.getAlly();
            
            cout << temp.getRegionName() << endl;
            cout << "       Army: " << regions[i].getArmy() << " soldiers\n";
            cout << "       Allegiance: ";
            if(tempAlly == 0) {
                // if ally = 0, the region is neutral
                cout << "NEUTRAL\n";
            } else {
                // outputs the ally name
                string allyName = users[tempAlly - 1].getName();
                cout << tempAlly << ") " << toUpper(allyName) << endl;
            }
        }
    }
}

// This function initiates a battle between a leader and a user
bool Game::battleLeader(int userNum, int regNum) {
    int userIndex = userNum - 1;
    int regIndex = regNum - 1;
    int errors = 0;
    Leader tempLeader = leaders[regIndex];
    
    if(userNum < 1 || userNum > 4) {
        cout << "ERROR: There are only four players\n";
        errors++;
    } 
    if (regNum < 1 || regNum > 7) {
        cout << "ERROR: There are only seven leaders\n";
        errors++;
    } 
    if(tempLeader.getAlly() == userNum) {
        // users cannot battle leaders on the payroll
        cout << "ERROR: This leader is already on your payroll\n";
        errors++;
    }
    if (errors > 0) {
        // function does not execute if there are any errors
        cout << "Battle not initiated\n";
        return 0;
    } else {
        Hero tempUser = users[userIndex];
        string userName = tempUser.getName();
        string leaderName = tempLeader.getLeaderName();

        cout << " --- INITIATING BATTLE ---\n";
        cout << "   " << userName << " (Player" << userNum << ")\n";
        cout << "       Warrior score: " << tempUser.getWarrior() << endl;
        cout << "           vs.\n";
        cout << "   " << leaderName << endl;
        cout << "       Warrior Score: " << tempLeader.getWarrior() << endl;
        cout << "---------------------------\n";

        // The difference between the warrior scores of the leader and the user is added 1o 10 to produce a key value
        int value =  10 + users[userIndex].getWarrior() - leaders[regIndex].getWarrior();

        // users must roll the key value or lower to win the battle
        cout << endl << userName << " needs to roll a "<< value << " or lower to win.\n";
        if(verify()) {
            cout << "Rolling a 20 sided die ... \n";
            int result = random(0, 20);
            cout << result << endl;

            if(result <= value) {
                // Winning user gains 1 clout and 2 warrior 
                cout << toUpper(userName) << " WINS!\n";
                cout << "   +1 Clout\n";
                cout << "   +2 Warrior\n";
                tempUser.addWarrior(2);
                tempUser.addToPayroll(regNum); // +1 clout and leader is added to the payroll

                // leader is removed from other users' payrolls
                int oldAlly = tempLeader.getAlly();
                if(oldAlly != 0) {
                    Hero allyOld = users[oldAlly - 1];
                    allyOld.removeFromPayroll(regNum);
                    users[oldAlly - 1] = allyOld;
                }

                tempLeader.setAlly(userNum); // updates the leader's ally
            } else {
                // if the user loses, they lose 2 warrior
                cout << toUpper(userName) << " LOSES.\n";
                cout <<"    -1 Clout\n";
                cout << "   -2 Warrior\n";
                tempUser.addClout(-1);
                tempUser.addWarrior(-2);
            }

            // updated user and leader to game
            users[userIndex] = tempUser;
            leaders[regIndex] = tempLeader;  
            return 1;
        } else {
            return 0;
        }

    } 
}

// This fucntion initiates a battle between two users
bool Game::battleUsers(int atk, int def) {
    int atkIndex = atk - 1;
    int defIndex = def - 1;
  
    if(def < 1 || def > 4 || atk < 1 || atk > 4) {
        // if user numbers are out of bounds
        cout << "ERROR: There are only four players\n";
        return 0;
    } else {
        Hero tempAtk = users[atkIndex];
        Hero tempDef = users[defIndex];
        string atkName = tempAtk.getName();

        cout << " --- INITIATING BATTLE ---\n";
        cout << "   " << tempAtk.getName() << " (Player " << atk << ")\n";
        cout << "       Warrior score: " << tempAtk.getWarrior() << endl;
        cout << "           vs.\n";
        cout << "   " << tempDef.getName() << " (Player " << def << ")\n";
        cout << "       Warrior Score: " << tempDef.getWarrior() << endl;
        cout << "---------------------------\n";

        // The difference of the users' warrior scores is added to 10 to determine a key value. 
        // Aggressors must roll the key value or lower on a 20 sided die to win
        int value =  10 + tempAtk.getWarrior() - tempDef.getWarrior();
        cout << endl << atkName << " needs to roll a "<< value << " or lower to win.\n";
        if(verify()) {
            cout << "Rolling a 20 sided die ... \n";
            int result = random(0, 20);
            cout << result << endl;
            
            cout << toUpper(atkName);
            if(result <= value) {
                // if the aggressor wins
                cout << " WINS!\n";
                // aggressor gains 1 clout, 2 warrior, and the bounty on the defending user is added to the aggressor's wealth
                cout << "   +1 Clout\n";
                cout << "   +2 Warrior\n";
                int tempBounty = tempDef.getBounty();
                cout << "   +$" << tempBounty << " Wealth" << endl;
                tempAtk.addClout(1);
                tempAtk.addWarrior(2); 
                tempAtk.addWealth(tempBounty);

                // the defending user is eliminated from the game
                cout << tempDef.getName() << " has been defeated\n";
                tempDef.eliminate();
            } else {
                // if the aggressor loses, they also lose 1 clout and 2 warrior
                cout << " LOSES.\n";
                cout << "   -1 Clout\n";
                cout << "   -2 Warrior\n";
                tempAtk.addClout(-1);
                tempAtk.addWarrior(-2);

                // The defending user gains 1 clout and 2 warrior
                cout << tempDef.getName() << " has successfully defended themselves\n";
                cout << "   +1 Clout\n";
                cout << "   +2 Warrior\n";
                tempDef.addClout(1);
                tempDef.addWarrior(2);

                // no users are eliminated
            }

            // updates users
            users[atkIndex] = tempAtk;
            users[defIndex] = tempDef;  
            return 1;
        } else {
            return 0;
        }
    } 
}

// This fucntion takes a user number and region number and attemps to bribe the leader at that region
bool Game::bribeLeader(int userNum, int regNum) {
    Hero tempUser = users[userNum - 1];
    int tempBase = tempUser.getBase();
    Leader tempLeader = leaders[regNum -1];
    int tempRegNum = tempLeader.getRegionNum();
    int errors = 0;

    if(tempRegNum == 0 || tempBase == 0) {
        errors++;
    }
    if(tempLeader.getAlly() == userNum) {
        cout << "ERROR: This leader is already on your payroll\n";
        errors++;
    }
    if (errors > 0) {
        // function does not execute if there are any errors
        cout << "Bribe not initiated\n";
        return 0;
    } else {
        cout << "You are attempting to bribe " << tempLeader.getLeaderName() << endl;
        cout << "(Note: If you succeed, this leader's salary will increase by 50% and the leader will be added to your payroll)\n";

        int newSal = tempLeader.getSalary() * 1.5; // successful bribes increase the leader salary by 50%
        cout << "New salary: $" << newSal << endl;

        // The difference between the charisma and loyalty is added to 10 to produce a key value
        int dif = 10 + tempUser.getCharisma() - tempLeader.getLoyalty();
        cout << tempUser.getName() << " needs to roll a " << dif << " or lower to bribe.\n";

        if(verify()) {
            // The result is determined by rolling a 20 sided die. If the user rolls the key value or lower, they win
            cout << "Rolling a 20 sided die ...\n";
            int value = random(0, 20);
            cout << value << endl;

            if(value <= dif) {
                // If the user succeeds
                tempLeader.setSalary(newSal);
                cout << "BRIBE SUCCESSFUL\n";
                cout << tempUser.getName() << endl;

                // User earns 1 clout and 2 charisma
                cout << "   +1 Clout\n";
                cout << "   +2 Charisma\n";
                tempUser.addCharisma(2); 
                tempUser.addToPayroll(regNum); // +1 clout and leader is added to the payroll

                // Leader loses 1 loyalty
                cout << tempLeader.getLeaderName() << endl;
                cout << "   -1 Loyalty\n";
                tempLeader.addLoyalty(-1);
                int allyOld = tempLeader.getAlly();
                if(allyOld != 0) {
                    // removes the leader from other users' payroll
                    Hero oldAlly = users[allyOld -1];
                    oldAlly.removeFromPayroll(regNum);
                    users[allyOld -1] = oldAlly; 
                } 
                tempLeader.setAlly(userNum); // changes the leader's ally to the current user
            } else {
                // If user fails

                cout << "BRIBE FAILED\n";
                cout << tempUser.getName() << endl;

                // User loses 2 charimsa 
                cout << "   -2 Charisma\n";
                tempUser.addCharisma(-2);

                // leader gains 1 charisma
                cout << tempLeader.getLeaderName() << endl;
                cout << "   +1 Loyalty\n";
                tempLeader.addLoyalty(1);
                 
            }

            // update user and leader
            users[userNum - 1] = tempUser; 
            leaders[regNum - 1] = tempLeader;
            return 1;
        } else {
            return 0;
        }
    }
}

// This function determines if a user conquers a given region
bool Game::conquer(int userNum, int regNum) {
    int userIndex = userNum -1;
    int regIndex = regNum - 1;
    Hero tempUser = users[userIndex];
    Region tempReg = regions[regIndex];

    int errors = 0;
    if(tempReg.getRegionNum() == 0 || tempUser.getBase() == 0) {
        errors++;
    }
    if(tempReg.getAlly() == userNum) {
        cout << "ERROR: You already control this region\n";
        errors++;
    }

    if(errors > 0) {
        cout << "No action taken\n";
        return 0;
    } else {
        int userComp = tempUser.getCompany();
        int regArmy = tempReg.getArmy();
        // The winner is determined by whoever has the most soldiers, unless, the company size and region army are within 100 of each other
        cout << "You are attempting to conquer " << tempReg.getRegionName() << endl;
        cout << "(If your company size is within 100 of this region's army, the result will be determined by a filp of a coin.\n";
        cout << "   Otherwise, the winner is determined by whoever has the most soldiers.)\n";
        cout << "\nYour company size: " << userComp << endl;
        cout << "Region army size: " << regArmy << endl;

        if(verify()) {
            bool win = 0;
            if(regArmy - 100 <= userComp && userComp <= regArmy + 100) {
                cout << "Flipping a coin ...\n";
                
                win = random(0, 1);
            } else if(userComp > regArmy){
                win = 1;
            } else {
                win = 0;
            }

            if(win) {
                // Player gains 1 clout and 200 soldiers for successful takeovers
                cout << tempUser.getName() << " WINS!\n";
                tempUser.addTerritory(regNum);
                cout << "   + 1 Clout\n";
                cout << "   + 200 soldiers\n";
                tempUser.addCompany(200);
                
                // territory's allegiance is changed 
                int oldAlly = tempReg.getAlly();
                if(oldAlly != 0) {
                    Hero allyOld = users[oldAlly -1];
                    allyOld.removeTerritory(regNum);
                    users[oldAlly -1] = allyOld;
                }
                tempReg.setAlly(userNum);

                
            } else {
                // If the player fails, they lose 1 clout and 200 soldiers
                cout << tempUser.getName() << " LOSES.\n";
                cout << "   -1 Clout\n";
                tempUser.addClout(-1);
                cout << "   -200 soldiers\n";
                tempUser.addCompany(-200);
            }
            users[userIndex] = tempUser;
            regions[regIndex] = tempReg;
            return 1;
        } else {
            return 0;
        }
    }
}

// this member function begins a conquest
int Game::conquest(int userNum) {
    int userIndex = userNum - 1;
    Hero tempUser = users[userIndex];
    int userArmy = users[userIndex].getCompany();
    int defendingArmy = 0;
   
    for(int i = 0; i < 7; i++) {
        if(tempUser.getTerritoryAt(i+1)) {
            // Adds the armies from user territories to the user army
            userArmy += regions[i].getArmy();
        } else {
            // Other armies are added to the 
            defendingArmy += regions[i].getArmy();
        }
    }

    // Adds user companies to the defending army
    for(int j = 0; j < 4; j++) {
        if(j != userIndex && users[j].getDefeated() == 0) {
            defendingArmy += users[j].getCompany();
        }
    }

    // the ratio of user's army to total soldiers in the realm determines the value that the user needs to roll
    int sum = defendingArmy + userArmy;
    double ratio = userArmy / (sum * 1.0);
    int value = ratio * 20;
    string tempName = tempUser.getName();

    cout << "*************************\n";
    cout << "======= CONQUEST! =======\n";
    cout << tempName << endl;
    cout << "   Army: " << userArmy << endl;
    cout << "       vs.\n";
    cout << "The Realm\n";
    cout << "   Army: " << defendingArmy << endl;
    cout << "-------------------------\n";
    cout << "Player " << userNum << " needs to roll a " << value << " or lower to win the conquest\n";
    
    if(verify()) {
        cout << "Rolling a 20 sided die ... \n";
        int result = random(0, 20);
        cout << result << endl;
        cout << "Player " << userNum; 
        if(result <= value) {
            cout << " WINS!\n";
            cout << tempName << " has defeated all other contenders and conquered the realm!\n";

            // eliminates all other users
            for(int l = 0; l < 4; l++) {
                if(l != userIndex) {
                    users[l].eliminate();
                }
            }
            winner = userNum;
            return 3;
        } else {
            // if the agressor loses conquest, they also lose 6 clout and 1000 soldiers
            cout << " LOSES.\n";
            cout << tempName << ":\n";
            cout << "   -6 Clout\n";
            tempUser.addClout(-6);
            cout << "   -1000 soldiers\n";
            tempUser.addCompany(-1000);
            users[userIndex] = tempUser;

            cout << "Remaining contenders:\n";
            cout << "   +2 Clout\n";
            // all remaining contenders get 2 clout
            for(int m = 0; m < 4; m++) {
                if(users[m].getDefeated() == 0 && m != userIndex) {
                    users[m].addClout(2);
                }
            }
        }
    } 
    return 0;
}

// checks if a player has met any criteria to win the game
int Game::checkWinner(int userNum) {
    int index = userNum - 1;
    int activeUsers = 0;
    // checks for other active users
    for(int i = 0; i < 4; i++) {
        if(index != i) {
            if(users[index].getDefeated() == 0) {
                activeUsers++;
            }
        }
    }
    string userName = users[index].getName();
    // if no other active users, the player wins the game
    if(activeUsers == 0 && users[index].getDefeated() == 0) {
        cout << userName << " IS THE ONLY REMAINING CONTENDER!\n";
        winner = userNum;
        return 1;
    } else {
        // If the player dominates District 1, they win
        if(users[index].getPayrollAt(1) && users[index].getTerritoryAt(1)) {
            cout << userName << " HAS SUCCESSFULLY DOMINATED THE CAPITAL!\n";
            winner = userNum;
            return 2;
        } 
    }
    return 0;
}
// If players control the same region where they have a leader on the payroll, players recieve a 1 clout bonus
void Game::checkBonus(int userNum) {
    int index = userNum -1;
    if(userNum < 1 || userNum > 4) {
        cout << "ERROR: There are only four players\n";
    } else {
        cout << "Player " << userNum << " bonuses:\n";
        int bonuses = 0;
        for(int i = 0; i < 7; i++) {
            int pos = i + 1;
            Hero tempUser = users[index];
            // if user controls the territory and leader of a single district
            if(tempUser.getTerritoryAt(pos) && tempUser.getPayrollAt(pos)) {
                cout << "   District " << pos << ": " << regions[i].getRegionName() << endl;
                tempUser.addClout(1); // bonus clout point
                bonuses++;
            }
            users[index] = tempUser;
        }
        if(bonuses == 0) {
            cout << "   NONE\n";
        }
    }
}

// This function resets the regions and leaders alligned with eliminated users
void Game::clearUser(int userNum) {
    int userIndex = userNum -1;
    Hero tempUser = users[userIndex];
    for(int i = 0; i < 7; i++) {
        int tempRegNum = i + 1;
        // removes leader allegiances
        if(tempUser.getPayrollAt(tempRegNum)) {
            leaders[i].setAlly(0);
            tempUser.removeFromPayroll(tempRegNum);
        } 

        // removes terriory allegiances
        if(tempUser.getTerritoryAt(tempRegNum)) {
            regions[i].setAlly(0);
            tempUser.removeTerritory(tempRegNum);
        }
    }
    users[userIndex] = tempUser;
}

// checks that all conditions are met to bein the game
bool Game::startGame() {
    int errors = 0;
    // There must be four players
    if(numUsers != 4) {
        cout << "Four players are needed to begin the game\n";
        errors++;
    }
    // There must be 7 regions
    if(numRegions != 7) {
        cout << "Seven regions are required to begin the game\n";
        errors++;
    }
    // There must be 7 leaders
    if(numLeaders != 7) {
        cout << "Seven leaders are required to begin the game\n";
        errors++;
    }
    if (errors > 0) {
        return 0;
    } else {
        // If all conditions are met, return true
        return 1;
    }
}