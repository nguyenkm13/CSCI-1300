// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 3

#include <iostream>
#include "Leader.cpp"
#include "Hero.cpp"
#include "Region.cpp"
#include "Game.cpp"
using namespace std;

// This function sets the characters for every user
Game selectPlayers(Game game_) {
    int choice = 0;
    int init = 0;
    string input = "";
    for(int i = 0; i < 4; i++) {
        do {
            cout << "=== Player " << i + 1 << " ===\n";
            cout << "1. View Heroes\n";
            cout << "2. Select Contender\n";
            cout << "3. Next Player\n";
            cout << "======================\n";
            cin >> choice;

            switch(choice) {
                case 1: {
                    // lists all heroes in the library
                    for(int j = 0; j < game_.getSizeLibrary(); j++) {
                        game_.viewHero(j);
                    }
                    break;
                }
                case 2: {
                    int champ = 0;
                    int matches = 0;
                    cout << "Select a Champion: ";
                    cin >> champ;

                    Hero newUser = game_.getHeroAt(champ);
                    string userName = newUser.getName();

                    if(userName != "") {
                        cout << "User " << i + 1 << " has selected " << userName << '.' << endl; 
                        if(verify()) {
                            // sets the user
                            game_.setUserAt(i + 1, newUser);
                            if(toUpper(game_.getUserAt(i+1).getName()) == toUpper(userName)) {
                                choice = 3;
                            }
                        } else {
                            cout << "User was not updated\n";
                        }
                    }
                    break;
                }
                case 3: 
                    break; 
                default: {
                    cout << "Invalid Choice\n";
                    break;
                }
            }
        } while(choice != 3);
    }
    return game_;
}

// This is the primary game function
void beginConquest(Game gamma) {

    // Initialize the game
    for(int i = 0; i < 4; i ++) {
        Hero temp = gamma.getUserAt(i+1);
        for(int j = 0; j < 7; j++) {
            Region reg1 = gamma.getRegionAt(j + 1);
            Leader leader1 = gamma.getLeaderAt(j + 1);

            // sets the base for each player
            if(reg1.getRegionNum() == temp.getBase()) {
                reg1.setAlly(i + 1);
                gamma.setRegionAt(j + 1, reg1);
                temp.addTerritory(j + 1);  
            }

            // sets the ally for each leader
            if(leader1.getRegionNum() == temp.getBase()) {
                leader1.setAlly(i + 1);
                gamma.setLeaderAt(j + 1, leader1);
                temp.addToPayroll(j + 1);
            }
            gamma.setRegionAt(j+1, reg1);
            gamma.setLeaderAt(j+1, leader1);
        }
        gamma.setUserAt(i+1, temp);
    }

    int round = 1;
    int winner = 0;
    int method = 0;
    bool conquest[4];
    
    do {
        cout << "================ ROUND "<< round << " =================\n";
        cout << "***************************************************\n";
        for(int a = 0; a < 4; a++) {
            conquest[a] = 0;
        } // resets the conquest marker

        // rounds
        for(int j = 0; j < 4; j++) {
            int userNum = j + 1;
            Hero active = gamma.getUserAt(userNum);
            string activeName = active.getName();
            
            if(active.getDefeated()) {
                // If the user is defeated, they to not get a turn
                cout << activeName << " (Player " << userNum << ") was eliminated\n";
            } else {
                // Adds $1000 wealth to each active user at the beginning of each round
                if(round > 1) {
                    // The user that is dominating district 4 (Vitrusia) recieves an additional $1000 each round
                    if(active.getTerritoryAt(4) && active.getPayrollAt(4)) {
                        cout << active.getName() << " is dominating the clergy (District 4: Vitrusia)\n";
                        cout << "   + $2000 wealth\n";
                        active.addWealth(2000);

                    } else {
                        cout << active.getName() << endl;
                        cout << "   + $1000 wealth\n";
                        active.addWealth(1000);
                    }
                    gamma.setUserAt(userNum, active);
                }

                bool endTurn;
                int choice;
                bool addBounty = 0;
                do {
                    endTurn = 0;
                    choice = 0;
                    cout << "=== " << activeName << " (P" << userNum << "): Make a Selection ===\n";
                    cout << "Clout: " << active.getClout() << " | Wealth: $" << active.getWealth();
                    cout << " | Company: " << active.getCompany() << " soldiers\n";
                    cout << "1. Challenge leader *\n";
                    cout << "2. Conquer territory *\n";
                    cout << "3. View bounties\n";
                    cout << "4. Edit payroll\n";
                    cout << "5. Move soldiers\n";
                    cout << "6. View game stats\n";
                    cout << "7. Black Market\n";
                    cout << "8. Declare a conquest *\n";
                    cout << "9. Forfeit turn * \n";
                    cout << "(Executing actions with a * will end your turn)\n";
                    cout << "=================================\n";
                    cin >> choice;

                    switch(choice) {
                        case 1: {
                            int regNum = 0;
                            // lists all leaders and thier alliances
                            cout << " --- LEADERS ---\n";
                            for(int k = 0; k < 7; k++) {
                                cout << "------------------------------\n";
                                gamma.viewLeader(k + 1);
                                cout << endl;
                            }

                            do {  
                                cout << "=== CHALLENGE LEADER ===\n";
                                cout << active.getName() << endl;
                                cout << "Warrior score: " << active.getWarrior() << endl;
                                cout << "Charisma score: " << active.getCharisma() << endl;
                                cout << "------------------------------\n";
                                cout << "Select leader or enter '0' to return: ";
                                cin >> regNum;

   
                                Leader tempLeader = gamma.getLeaderAt(regNum);

                                if(tempLeader.getRegionNum() != 0) {
                                    cout << "You selected " << tempLeader.getLeaderName() << endl;
                                    if(verify()) { 
                                        int contest = 0;
                                        // Players can either bribe or battle leaders
                                        cout << "=== BRIBE OR BATTLE ===\n";
                                        cout << "1. Bribe\n";
                                        cout << "2. Battle\n";
                                        cout << "3. Return\n";
                                        cout << "-----------------------\n";
                                        cin >> contest;

                                        int bribe = 0, x = 0;
                                        switch(contest) {
                                            case 1: {
                                                bribe = gamma.bribeLeader(userNum, regNum);
                                                break;
                                            }
                                            case 2: {
                                                x = gamma.battleLeader(userNum, regNum);
                                                break;
                                            }
                                            case 3: {
                                                break;
                                            }
                                            default: {
                                                cout << "Invalid Option\n";
                                                break;
                                            }
                                        }
                                        if(bribe || x) {
                                            regNum = 0;
                                            endTurn = 1;
                                        }
                                    } else {
                                        cout << "Battle not initiated\n";
                                    }
                                }
                            } while (regNum != 0);
                            break;
                        }
                        case 2: {
                            // lists all regions and their alliances
                            for(int l = 0; l < 7; l++) {
                                gamma.viewRegion(l + 1);
                            }
                            int regNum2;
                            cout << "=== CONQUER TERRITORY ===\n";
                            cout << "Enter region number to conquer or 0 to return: ";
                            cin >> regNum2;
                            
                            if(regNum2 != 0) {
                                Region tempReg = gamma.getRegionAt(regNum2);
                                bool success = 0;
                                success = gamma.conquer(userNum, regNum2); 

                                // If the action conpleted, the user ends their turn
                                if(success) {
                                    endTurn = 1;
                                }
                            }
                            break;
                        }                       
                        case 3: {
                            cout << " === BOUNTIES === \n";
                            for(int m = 1; m < 5; m++) {
                                Hero temp2 = gamma.getUserAt(m);
                                cout << "Player " << m << ": " << temp2.getName() << endl;
                                cout << "   Bounty: $";
                                if(temp2.getDefeated() == 1) {
                                    cout << " - DEFEATED\n";
                                } else {
                                    cout << temp2.getBounty() <<  endl;
                                }
                            }
                            int bountyNum = 0;
                            cout << "Select a user or enter '0' to return: ";
                            cin >> bountyNum;  

                            if(bountyNum != 0) {
                                Hero bountyUser = gamma.getUserAt(bountyNum);
                                if(bountyUser.getBase() != 0) {
                                    int menu3 = 0;
                                    do {      
                                        if(bountyNum == userNum) {
                                            cout << "ERROR: You cannot edit your own bounty\n";
                                            menu3 = 3;;
                                        } else if(bountyUser.getBase() != 0) {
                                            cout << "=== Make a Selection ===\n";
                                            cout << bountyUser.getName() << endl;
                                            cout << "Bounty: $" << bountyUser.getBounty() << endl;
                                            cout << "1. Add to bounty\n";
                                            if(!addBounty) {
                                                cout << "2. Complete bounty contract * \n";
                                            }
                                            cout << "3. Return\n";
                                            cout << "------------------------------\n";
                                            cin >> menu3;

                                            switch(menu3) {
                                                case 1: {  
                                                    // Players can place bounties on other users
                                                    int incBounty = 0;
                                                    cout << "Current Bounty: " << bountyUser.getBounty() << endl;
                                                    cout << "How much would you like to increase the bounty by?\n";
                                                    int activeWealth = active.getWealth();
                                                    cout << "Current wealth: $" << activeWealth << endl;
                                                    cin >> incBounty;

                                                    if(incBounty < 0) {
                                                        cout << "ERROR: You cannot decrease a bounty\n";
                                                        menu3 = 3;
                                                    } else if (incBounty > activeWealth){
                                                        cout << "ERROR: Insufficient funds\n";
                                                        menu3 = 3;
                                                    } else {
                                                        cout << "You are increasing "<< bountyUser.getName() <<"'s bounty to $" << bountyUser.getBounty() + incBounty << endl;
                                                        cout << "NOTE: This action will decrease your wealth by $" << incBounty << endl;
                                                        if(verify()) {
                                                            bountyUser.addBounty(incBounty);
                                                            active.addWealth(-1 * incBounty);
                                                            menu3 = 3;
                                                            gamma.setUserAt(bountyNum, bountyUser);
                                                            gamma.setUserAt(userNum, active);
                                                            addBounty = 1;
                                                        }
                                                    }
                                                    break;
                                                }   
                                                case 2: {
                                                    //Players cannot add a bounty and complete a bounty contract in the same turn
                                                    if(!addBounty) {
                                                        // Players can only battle other users when they have a larger company
                                                        if(bountyUser.getBounty() > 0) {
                                                        if(active.getCompany() < bountyUser.getCompany()) {
                                                            cout << bountyUser.getName() << " is heavily protected. You cannot complete the contract at this time.\n";
                                                            cout << "NOTE: You can only battle leaders whose company size is smaller than yours.\n";
                                                        } else {
                                                            if(gamma.battleUsers(userNum, bountyNum)) {
                                                                endTurn = 1;
                                                                menu3 = 3;
                                                            }
                                                        }   
                                                        } else {
                                                            cout << "You cannot complete a contract without a bounty\n";
                                                        }

                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    break;
                                                }
                                                default: {
                                                    cout << "Invalid option\n";
                                                    break;
                                                }
                                            }
                                        }
                                    } while(menu3 != 3);
                                }
                            }
                            break;
                        }
                        case 4: {
                            int sum = 0;
                            // lists all the leaders on the payroll
                            for(int n = 0; n < 7; n++) {
                                int num = n + 1;
                                if(active.getPayrollAt(n + 1) == 1) {
                                    Leader tempLeader = gamma.getLeaderAt(num);
                                    cout << num << ". " << tempLeader.getLeaderName() << endl;
                                    int salary = tempLeader.getSalary();
                                    sum = sum + salary;
                                    cout << "       Salary: $" << salary << endl;
                                }
                            }
                            cout << "Total payroll: $" << sum << endl;

                            int menu4 = 0;
                            // Players can edit their payroll
                            do {
                                cout << "=== PAYROLL ===\n";
                                cout << "1. Remove a leader from the payroll\n";
                                cout << "2. Clear Payroll\n";
                                cout << "3. Return\n";
                                cout << "---------------\n";
                                cout << "Enter your selection: ";
                                cin >> menu4;
                                switch(menu4) {
                                    case 1: {
                                        int remove = 0;
                                        cout << "Select leader to remove: ";
                                        cin >> remove;
                                        if(active.getPayrollAt(remove) == 1) {
                                            Leader tempLeader = gamma.getLeaderAt(remove); 
                                            cout << "You are removing " << tempLeader.getLeaderName() << " from the payroll\n";
                                            cout << "You will not be required to pay this leader's $" << tempLeader.getSalary() << endl;
                                            cout << "You will lose one clout\n";

                                            // removes the leader from the payroll
                                            if(verify()) {
                                                active.removeFromPayroll(remove);
                                                tempLeader.setAlly(0);
                                                gamma.setLeaderAt(remove, tempLeader);
                                            }
                                        } else {
                                            cout << "ERROR: This leader is not on the payroll\n";
                                        }
                                        break;
                                    }
                                    case 2: {
                                        
                                        cout << "You are clearing the payroll\n";
                                        cout << "You will not be required to pay any salaries at the end of the round\n";
                                        cout << "You will lose all clout associated with the leaders on your payroll\n";
                                        // removes all leaders from the payroll
                                        if(verify()) {
                                            for(int j = 0; j < 7; j++) {
                                                int num2 = j + 1;
                                                if(active.getPayrollAt(num2) == 1) {
                                                    active.removeFromPayroll(num2);
                                                    Leader tempLeader = gamma.getLeaderAt(num2);
                                                    tempLeader.setAlly(0);
                                                    gamma.setLeaderAt(num2, tempLeader);
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    case 3: {
                                        break;
                                    }
                                    default: {
                                        cout << "Invalid option\n";
                                        break;
                                    }
                                } 
                                gamma.setUserAt(userNum, active);
                            } while(menu4 != 3);
                            break;
                        }
                        case 5: {
                            // lists all of the regions that the user controls along with army sizes
                            for(int o = 1; o < 8; o++) {
                                if(active.getTerritoryAt(o)) {
                                    Region temp = gamma.getRegionAt(o);
                                    cout << o << ". " << temp.getRegionName() << endl;
                                    cout << "       Army: " << temp.getArmy() << " soldiers\n";
                                }
                            }
                            int tempRegNum = 0;
                            cout << "Select region:";
                            cin >> tempRegNum;
                            if(active.getTerritoryAt(tempRegNum) == 1) {
                                Region tempReg = gamma.getRegionAt(tempRegNum);
                                int menu5 = 0;
                                do {
                                    // Players can move soldiers between their personal company and regional armies
                                    cout << " === Player" << userNum << ": Make a Selection ===\n";
                                    cout << tempReg.getRegionName() << endl;
                                    cout << "   Army: " << tempReg.getArmy() << " soldiers\n";
                                    cout << "1. Add soldiers to region\n";
                                    cout << "2. Remove soldiers from region\n";
                                    cout << "3. Return\n";
                                    cout << "=================================\n";
                                    cout << "Enter selection: ";
                                    cin >> menu5;

                                    switch(menu5) {
                                        case 1: {
                                            int numSoldiers = 0;
                                            int tempCompany = active.getCompany();
                                            cout << "Company size: " << tempCompany << endl;
                                            cout << "How many soldiers would you like to add to this region?\n (Current: " << tempReg.getArmy() << ")\n";
                                            cin >> numSoldiers;

                                            //Players can only add a positive number
                                            if(numSoldiers > 0) {
                                                cout << "New region army size: " << tempReg.getArmy() + numSoldiers << " soldiers\n";
                                                cout << "New personal company size : " << tempCompany - numSoldiers << " soldiers\n";

                                                if(verify()) { 
                                                    if(numSoldiers <= tempCompany) {
                                                        tempReg.addToArmy(numSoldiers); // add to region
                                                        active.addCompany(-1 * numSoldiers); // subtract from company
                                                    } else {
                                                        cout << "ERROR: You only have " << tempCompany << " soldiers in your personal company\n";
                                                    }
                                                }
                                            } else {
                                                cout << "ERROR: You cannot add a negative number of soldiers\n";
                                            }
                                            break;
                                        }
                                        case 2: {
                                            int numSoldiers2 = 0;
                                            cout << "How many soldiers would you like to add to your personal company?\n (Current: " << active.getCompany() << ")\n";
                                            cin >> numSoldiers2;

                                            if(numSoldiers2 <= tempReg.getArmy()) {
                                                if(numSoldiers2 > 0) {
                                                    cout << "New personal company size: " << active.getCompany() + numSoldiers2 <<" soldiers\n";
                                                    cout << "New regional army size: " << tempReg.getArmy() - numSoldiers2 << " soldiers\n";

                                                    if(verify()) {
                                                        active.addCompany(numSoldiers2); // add to company
                                                        tempReg.addToArmy(-1 * numSoldiers2); // subtract from region
                                                    }
                                                } else {
                                                    cout << "ERROR: You cannot add a negaitve number of soldiers\n";
                                                }
                                            } else {
                                                cout << "ERROR: There are only " << tempReg.getArmy() << " soldiers stationed in this region\n";
                                            }
                                            break;
                                        }
                                        case 3: {
                                            break;
                                        }
                                        default: {
                                            cout << "Invalid option\n";
                                            break;  
                                        }    
                                    }


                                } while(menu5 != 3);

                                gamma.setUserAt(userNum, active); // saves user to game
                                gamma.setRegionAt(tempRegNum, tempReg); // save region to game

                            } else {
                                cout << "You do not control this region\n";
                            }
                            break;
                        }
                        case 6: {
                            int menu6;
                            do {
                                menu6 = 0;
                                cout << "=== VIEW GAME STATS ===\n";
                                cout << "1. Users\n";
                                cout << "2. Regions\n";
                                cout << "3. Leaders\n";
                                cout << "=======================\n";
                                cout << "Make a selection or enter '0' to return: ";
                                cin >> menu6;

                                switch(menu6) {
                                    case 0: {
                                        break;
                                    }
                                    case 1: {
                                        for(int p = 0; p < 4; p++) {
                                            gamma.viewUser(p + 1);
                                            cout << endl;
                                        }
                                        break;
                                    }
                                    case 2: {
                                        for(int q = 0; q < 7; q++) {
                                            gamma.viewRegion(q + 1);
                                            cout << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        for(int r = 0; r < 7; r++) {
                                            gamma.viewLeader(r + 1);
                                            cout << endl;
                                        }
                                        break;
                                    }
                                    default: {
                                        cout << "Invalid option\n";
                                        break;
                                    }
                                }
 
                            } while(menu6 != 0);
                            break;
                        }
                        case 7: {
                            bool discount = 0;

                            //Players that dominate district 5 recieve 50% off all purchases
                            if(active.getTerritoryAt(5) && active.getPayrollAt(5)) {
                                cout << activeName << " is currently dominating the Financial District\n";
                                cout << "(50% off all purchases)\n";
                                discount = 1;
                            }
                            int menu7;
                            do {
                                menu7 = 0;
                                cout << "=== Black Market ===\n";
                                cout << "Current Wealth: $" << active.getWealth() << endl;
                                cout << "1. Increase warrior score ($1000 per point [$500 with discount])\n";
                                cout << "2. Increase charisma score ($1000 per point [$500 with discount])\n";
                                cout << "3. Add mercenaries ($10 per soldier [$5 with discount])\n";
                                cout << "4. Sell Clout (+$5000 per point)\n";
                                cout << "=================================================================\n";
                                cout << "Make selction or enter '0' to return: ";
                                cin >> menu7;

                                int cost = 0;
                                switch(menu7) {
                                    case 0: {
                                        break;
                                    }
                                    case 1: {
                                        // Players can buy warrior points
                                        int tempWarrior = 0;
                                        cout << "Current warrior score: " << active.getWarrior() << endl;
                                        cout << "How points would you like to increase this attribute by? ";
                                        cin >> tempWarrior;

                                        // Discount for players that dominate district 5
                                        if(discount) {
                                            cost = tempWarrior * 500;
                                        } else {
                                            cost = tempWarrior * 1000;
                                        }

                                        if(cost > active.getWealth()) {
                                            cout << "ERROR: You do not have enough money to make this purchase\n";
                                            menu7 = 0;
                                        } else {
                                            cout << "You are increasing your warrior score to " << active.getWarrior() + tempWarrior << endl;
                                            cout << "(This action will cost you $" << cost << ")\n";
                                            cout << "New warrior score: " << tempWarrior + active.getWarrior() << " | " << "New wealth: $" << active.getWealth() - cost << endl;
                                            
                                            if(verify()) {
                                                active.addWarrior(tempWarrior);
                                                active.addWealth(-1 * cost);
                                                gamma.setUserAt(userNum, active);
                                            } 
                                        }

                                        break;
                                    }
                                    case 2: {
                                        // Players can buy charisma points
                                        int tempCharisma = 0;
                                        cout << "Current charisma score: " << active.getCharisma() << endl;
                                        cout << "How points would you like to increase this attribute by?";
                                        cin >> tempCharisma;
                                        
                                        // Discount for players that dominate district 5
                                        if(discount) {
                                            cost = tempCharisma * 500;
                                        } else {
                                            cost = tempCharisma * 1000;
                                        }
                                        if(cost > active.getWealth()) {
                                            cout << "ERROR: You do not have enough money to make this purchase\n";
                                            menu7 = 0;
                                        } else {
                                            cout << "You are increasing your warrior score by " << tempCharisma << endl;
                                            cout << "(This action will cost you $" << cost << ")\n";
                                            cout << "New charisma score: " << tempCharisma + active.getCharisma() << " | " << "New wealth: $" << active.getWealth() - cost << endl;
                                            
                                            if(verify()) {
                                                active.addCharisma(tempCharisma);
                                                active.addWealth(-1 * cost);
                                                gamma.setUserAt(userNum, active);
                                            } 
                                        }
                                        break;
                                    }
                                    case 3: {
                                        // Players can buy soldiers to add to their company
                                        int tempCompany = 0;
                                        cout << "Current company size: " << active.getCompany() << " soldiers\n";
                                        cout << "How points would you like to increase your company by?";
                                        cin >> tempCompany;

                                        // Players that dominate district 5 recieve a 50% discount
                                        if(discount) {
                                            cost = tempCompany * 5;
                                        } else {
                                            cost = tempCompany * 10;
                                        }
                                        if(cost > active.getWealth()) {
                                            cout << "ERROR: You do not have enough money to make this purchase\n";
                                            menu7 = 0;
                                        } else {
                                            cout << "You are increasing your company by " << tempCompany << endl;
                                            cout << "(This action will cost you $" << cost << ")\n";
                                            cout << "New company size: " << tempCompany + active.getCompany() << " | " << "New wealth: $" << active.getWealth() - cost << endl;
                                            
                                            if(verify()) {
                                                active.addCompany(tempCompany);
                                                active.addWealth(-1 * cost);
                                                gamma.setUserAt(userNum, active);
                                            } 
                                        }
                                        break;
                                    }
                                    case 4: {
                                        // Players can sell clout for $5000
                                        int tempClout = 0;
                                        cout << "Current clout: " << active.getClout() << endl;
                                        cout << "How much clout would you like to sell? ";
                                        cin >> tempClout;

                                        cost = tempClout * 5000; //total $ amount to be traded for clout
                                        
                                        if(tempClout > active.getClout()) {
                                            // If the player doesn't have enough clout
                                            cout << "ERROR: You do not have enough clout complete this transaction\n";
                                            menu7 = 0;
                                        } else {
                                            cout << "You are decreasing your clout by " << tempClout << endl;
                                            cout << "(This action will increase your wealth by $" << cost << ")\n";
                                            cout << "New clout: " << active.getClout() - tempClout << " | " << "New wealth: $" << active.getWealth() + cost << endl;
                                            
                                            if(verify()) {
                                                active.addClout(-1 * tempClout);
                                                active.addWealth(cost);
                                                gamma.setUserAt(userNum, active); // updates user in game
                                            } 
                                        }
                                        break;
                                    }
                                    default: {
                                        cout << "Invalid option\n";
                                        break;
                                    }
                                }
                            } while (menu7 != 0);

                            break;
                        }
                        case 8: {
                            // Players can only declare a conquest if they have 12 or more clout points
                            int tempClout = active.getClout();
                            if(tempClout < 12) {
                                cout << "ERROR: You cannot declare a conquest until you have acculmated 12 clout points\n";
                                cout << "You currently have " << tempClout << " clout points\n";
                            } else {
                                cout << "You are declaring a conquest\n";
                                if(verify()) {
                                    cout << "Your conquest will begin at the end of the round\n";
                                    conquest[userNum - 1] = 1; // conquest will execute at the end of the round
                                    endTurn = 1;
                                }   
                            }
                            break;
                        }
                        case 9: {
                            // Players are allowed to pass their turn without executing an action
                            cout << "YOU ARE FORFEITING YOUR TURN.\n";
                            if(!verify()) {
                                choice = 0;
                            }
                            break;
                        }
                        default: {
                            cout << "Invalid Option\n";
                            break;
                        }
                    } 

                    // Manually ends the user's turn
                    if(endTurn) {
                        choice = 9;
                    }
                } while(choice != 9);   
            }
        }  // End of User i's turn

        // End of round actions
        cout << " *** END OF ROUND " << round << " *** \n";
        for(int z = 0; z < 4; z++) {
            int userNum = z + 1;
            int totalPayroll = gamma.getUserPayroll(userNum);
            Hero tempUser = gamma.getUserAt(userNum);

            // The salaries of leaders on the payroll are deducted from the user's wealth at the end of each round
            tempUser.addWealth(-1 * totalPayroll);

            // Players with zero wealth lose 1 clout each round
            if(tempUser.getWealth() == 0) {
                cout << tempUser.getName() << endl;
                tempUser.addClout(-1);
                cout << "Wealth: $0\n";
                cout << "   - 1 Clout\n";
            }
            
            // Players who have negative clout are eliminated
            if(tempUser.getClout() < 0) {
                tempUser.eliminate();
                cout << "PLAYER " << userNum << " HAS BEEN ELIMINATED FROM THE GAME\n";
            }
            if(tempUser.getDefeated()) {
                // resets regions and leaders formerly alligned with eliminated users
                gamma.clearUser(userNum);
            } else {
                gamma.checkBonus(userNum); // players gain 1 clout by for each district are dominating
                // if one or more players declare a conquest
                if(conquest[z]) {
                   method = gamma.conquest(userNum); // executes conquests 
                }
                if(method == 0) {
                    method = gamma.checkWinner(userNum);
                }
                
                cout << endl;
            }
        }  

        winner = gamma.getWinner();
        round++;   
    } while (!winner); // End of the round

    // Writes the winner to a file as well as the final game stats
    if(winner) {
        ofstream myFile;
        myFile.open("game_results.txt");

        Hero champion = gamma.getUserAt(winner);
        myFile << "========== GAME RESULTS ==========\n";
        myFile << "Rounds: " << round << endl;
        myFile << "Winner: " << champion.getName() << "(Player " << winner << ")\n";
        myFile <<  "    Method: ";
        switch(method) {
            case 1: {
                myFile << "Only remaining contender\n";
                break;
            }
            case 2: {
                Region tempReg = gamma.getRegionAt(1);
                myFile << "Dominated District 1: " << tempReg.getRegionName() << endl;
                break;
            }
            case 3: {
                myFile << "Victorious Conquest\n";
                break;
            }
        }
        myFile << "----------- Players ------------\n";
        for(int y = 0; y < 4; y++) {
            int tempNum = y + 1;
            Hero temp = gamma.getUserAt(tempNum);
            myFile << temp.getName();
            if(temp.getDefeated() == 1) {
                myFile << " - DEFEATED";
            }
            int territories = 0;
            int leaders = 0;
            for(int j = 0; j < 7; j++) {
                int tempIndex = j + 1;
                territories += temp.getTerritoryAt(tempIndex);
                leaders += temp.getPayrollAt(tempIndex);
            }

            int tempBase = temp.getBase();
            Region regFinal = gamma.getRegionAt(tempBase);
            myFile << "\n       Base region: (" << tempBase << ") " << regFinal.getRegionName() << endl;
            myFile << "       Clout: " << temp.getClout() << endl;
            myFile << "       Number of territories: " << territories << endl;
            myFile << "       Number of leaders on payroll: " << leaders << endl;
            myFile << "       Wealth: $" << temp.getWealth() << endl;
            myFile << "       Company size: " << temp.getCompany() << " soldiers" << endl;
            myFile << "       Warrior score: " << temp.getWarrior() << endl;
            myFile << "       Charimsa score: " << temp.getCharisma() << endl;
            myFile << "       Bounty: $" << temp.getBounty() << endl;
            myFile << "       Payroll: $" << gamma.getUserPayroll(tempNum) << endl << endl; 
        }
    }
}

// Main menu function
int main() {
    cout << "****** WELCOME TO CONQUEST! ******\n";
    Game game1;

    string file;
    int selection = 0, temp = 0;
    bool userFile = 0, regionsFile = 0, leadersFile = 0;
    do  
    {
        cout << "======== Make a Selection ========\n";
        cout << "Number of Users: " << game1.getNumUsers() << endl;
        cout << "1. Load Heroes\n";
        cout << "2. Load Regions\n";
        cout << "3. Load Leaders\n";
        cout << "4. Select Contenders (All Players)\n";
        cout << "5. Change Contender (One Player)\n";
        cout << "6. View Contenders\n";
        cout << "7. Begin Conquest\n";
        cout << "8. Exit\n";
        cout << "==================================\n";
        cin >> selection;

        switch (selection)
        {
            case 1:
                // reads hero file
                cout << "Enter a filename: ";
                cin.ignore();
                cin >> file;
                temp = game1.readHeroes(file);
                break;
            case 2:
                // reads regions file
                cout << "Enter a filename: ";
                cin.ignore();
                cin >> file;
                temp = game1.readRegions(file);
                break;
            case 3:
                // reads leaders file
                cout << "Enter a filename: ";
                cin.ignore();
                cin >> file;
                temp = game1.readLeaders(file);
                break;
            case 4:
                // Allows each player to choose their character
                game1 = selectPlayers(game1);
                break;
            case 5:
                // allows an individual character to choose/change their character
                int userNum;
                cout << "Enter user number: \n";
                cin >>userNum;
                if(userNum < 1 || userNum > 4) {
                    cout << "ERROR: User number must be between one and four\n";
                } else {
                    cout << "You selected Player " << userNum << endl;
                    if(verify()) {
                        int menu2 = 0;
                        do { 
                            cout << "--- User " << userNum << "---\n";
                            cout << "1. View heroes\n";
                            cout << "2. Select contender\n";
                            cout << "3. Return\n";
                            cout << "------------------------\n";
                            cin >> menu2;

                            switch(menu2) {
                                case 1: 
                                    // list of heroes in the library
                                    for(int j = 0; j < game1.getSizeLibrary(); j++) {
                                        game1.viewHero(j);
                                    }
                                    break;
                                case 2: {
                                    int heroNum_ = 0;
                                    cout << "Enter hero number: \n";
                                    cin >> heroNum_;

                                    Hero newUser = game1.getHeroAt(heroNum_);
                                    if(newUser.getName() != "") {
                                        cout << "You selected " << newUser.getName() << endl;
                                        if(verify()) {
                                            game1.setUserAt(userNum, newUser);
                                            menu2 = 3;
                                        }
                                    }
                                    break;
                                }
                                case 3:
                                    break;
                                default:
                                    cout << "Invalid option\n";
                                    break;
                            }
                        }while (menu2 != 3);
                    }
                }
                break;
            case 6:
                // lists all users
                for(int i = 0; i < 4; i++) {
                    game1.viewUser(i + 1);
                    cout << endl;
                }
                break;
            case 7:
                // begins the game
                if(game1.startGame()) {
                    beginConquest(game1);
                }
                break;
            case 8:
                cout << "Good Bye!\n";
                break;
            default: {
                cout << "Error: Invaid option.\n";
                break;
            }
        } 
    } while(selection != 8);

    // Game theta;
    // theta.readHeroes("heroes.txt");

    // for(int i = 0; i < 3; i++) {
    //     int userNum = i +1;
    //     Hero temp = theta.getHeroAt(userNum);
    //     theta.setUserAt(userNum, temp);
    // }
    // Hero temp = theta.getHeroAt(5);
    // temp.setClout(12);
    // theta.setUserAt(4, temp);

    
    // theta.readLeaders("leaders.txt");
    // theta.readRegions("regions.txt");

    



    // beginConquest(theta);
    

    return 0;
}