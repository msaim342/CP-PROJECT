/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    string playerClass;
    int health;
    int experiencePoints;
};

void createCharacter(Player& player) {
    cout << "Enter character name: ";
    getline(cin, player.name);

    bool validClass = false;
    while (!validClass) {
        cout << "Choose a class (Warrior, Mage, Rogue): ";
        getline(cin, player.playerClass);

        // Initialize health and experience points based on the chosen class
        if (player.playerClass == "Warrior" || player.playerClass == "Mage" || player.playerClass == "Rogue") {
            player.health = 100;
            player.experiencePoints = 0;
            validClass = true;
        }
        else {
            cout << "Invalid class! Please choose a valid class" << endl;
        }
    }
}

void displayPlayerInfo(const Player& player) {
    cout << "Player Information\n";
    cout << "Name: " << player.name << "\n";
    cout << "Class: " << player.playerClass << "\n";
    cout << "Health: " << player.health << "\n";
    cout << "Experience Points: " << player.experiencePoints << "\n";
}

int main()
{
    Player player1;
    createCharacter(player1);
    displayPlayerInfo(player1);
    string playAgain = "Y";
    int level = 1;
    int highMoves = 0;
    int mediumMoves = 0;
    int exp = 0;
    string difficulty;
    cout << "\t\t\tChoose  Difficulty   level   of   GAME! " << endl;
    for (int i = 1; i < 136; i++) {
        cout << "-";
    }
    cout << "\n\t\t\tEasy" << "\t\t" << "Medium" << "\t\t" << "Hard" << endl;
    getline(cin, difficulty);
    if (difficulty == "e" || difficulty == "E")
    {
        for (int i = 0; i <= 50; i++)
        {
            cout << "*";
        }
        cout << "\n\t\tEASY!" << endl;
        for (int j = 0; j <= 50; j++)
        {
            cout << "*";
        }
        cout << "\n\tIn a mystical land known as Eldoria \nwhere the forces of magic and technology coexist, an ancient prophecy foretells of a \nhero destined to restore balance to the realms. \nAs darkness looms, a young adventurer embarks on a journey to n\nfulfill their destiny and become the legendary Elemental Master." << endl;
        cout << "\tHere comes the Monsters! ";
        while (playAgain == "Y" || playAgain == "y")
        {
            string b;
            int ehealth;
            if (level == 2) {
                cout << "Please help civilan are under attack by the monsters  " << endl;
            }
            if (level == 3) {
                cout << "help our child the are in the house! Please I am begging You !" << endl;
            }
            if (level == 4) {
                cout << "King is calling you in the Castle to Save him and whole town from these Monsters! Please Hurry !! " << endl;
                ehealth = 230;
            }
            else {
                ehealth = 100 + (level - 1) * 8;
            }
            int health = 100;
            int playerDamageBase = 10 + (level - 1) * 3;
            cout << "\n L for LOW " << "\t\t" << "M for Medium" << "\t\t" << "H for High" << endl;
            while (ehealth > 0 && health > 0) {
                cout << "\tMedium moves" << "\t" << 6 - mediumMoves << "\tHigh moves " << 4 - highMoves << endl;

                getline(cin, b);
                int playerdamage = 0;
                if (b == "l" || b == "L") {
                    playerdamage = rand() % 12 + playerDamageBase;
                }
                else if (b == "m" || b == "M") {
                    if (mediumMoves >= 6) {
                        cout << "You have exhausted your medium moves!" << endl;
                        continue;
                    }
                    else {
                        mediumMoves++;
                        playerdamage = rand() % 16 + playerDamageBase + 2;
                    }
                }
                else if (b == "h" || b == "H") {
                    if (highMoves >= 4) {
                        cout << "You have exhausted your high moves!" << endl;
                        continue;
                    }
                    else {
                        highMoves++;
                        playerdamage = rand() % 22 + playerDamageBase + 10;
                    }
                }
                else {
                    cout << "Invalid input!" << endl;
                    continue;
                }

                ehealth -= playerdamage;

                if (ehealth <= 0) {
                    cout << "Monster health reached 0. You win!" << endl;
                    level++;
                    exp += 12;
                    cout << "\tYou defeated the Monster and reached Level " << level << "!" << endl;
                    highMoves = 0;
                    mediumMoves = 0;
                    break;
                }

                int enemyDamage = rand() % 3 + 3;
                health -= enemyDamage;

                if (health <= 0) {
                    cout << "\tYour health reached 0. Monster Wins!" << endl;
                    break;
                }

                cout << "Player's health: " << health << " Monster health: " << ehealth << endl;
            }
            if (level > 4) {
                cout << "\tCongratulations! You've completed the game. Goodbye!" << endl;
                break;
            }
            if (ehealth > 0) {
                cout << "\tYou couldn't defeat the Monster. GAME OVER!" << endl;
                highMoves = 0;
                mediumMoves = 0;
            }

            cout << "Experience Points: " << exp << endl;

            string choice;
            do {
                cout << "Do you want to play again? (Y/N): ";
                getline(cin, choice);
                if (choice != "Y" && choice != "y" && choice != "N" && choice != "n")
                {
                    cout << "Invalid input! Please enter Y/y for Yes or N/n for No." << endl;
                }
            } while (choice != "Y" && choice != "y" && choice != "N" && choice != "n");

            playAgain = choice;
        }

    }


    else if (difficulty == "m" || difficulty == "M")
    {
        for (int k = 0; k <= 50; k++)
        {
            cout << "*";
        }
        cout << "\n\t\tMEDIUM!" << endl;
        for (int l = 0; l <= 50; l++)
        {
            cout << "*";
        }

        cout << "\n\tIn a mystical land known as Eldoria \nwhere the forces of magic and technology coexist, an ancient prophecy foretells of a \nhero destined to restore balance to the realms. \nAs darkness looms, a young adventurer embarks on a journey to n\nfulfill their destiny and become the legendary Elemental Master." << endl;
        cout << "oohoo no ! Here comes the Deadly monsters who are Attacking the city Please Help the Civilians!";
        while (playAgain == "Y" || playAgain == "y")
        {
            if (level == 2) {
                cout << "\n\tplease save the our childs from these Dangerous monsters !";

            }

            string b;
            int ehealth;

            if (level == 3) {
                cout << "Here comes the evil and deadly Malificent , be safe!" << endl;
                ehealth = 250;
            }
            else if (level == 6) {
                cout << "Ghidora has arrived! You have to defeat him to save the Eldoria. Please try your best !." << endl;
                ehealth = 400;
            }
            else {
                ehealth = 100 + (level - 1) * 20;
            }

            int health = 100;
            int playerDamageBase = 5 + (level - 1) * 3;
            cout << "\n L for LOW " << "\t\t" << "M for Medium" << "\t\t" << "H for High" << endl;
            while (ehealth > 0 && health > 0) {
                cout << "\tMedium moves" << "\t" << 6 - mediumMoves << "\tHigh moves " << 3 - highMoves << endl;
                getline(cin, b);
                int playerdamage = 0;

                if (b == "l" || b == "L") {
                    playerdamage = rand() % 6 + playerDamageBase;
                }
                else if (b == "m" || b == "M") {
                    if (mediumMoves >= 6)
                    {
                        cout << "You have exhausted your medium moves!" << endl;
                        continue;
                    }
                    else {
                        mediumMoves++;
                        playerdamage = rand() % 9 + playerDamageBase + 4;
                    }
                }
                else if (b == "h" || b == "H") {
                    if (highMoves >= 3) {
                        cout << "You have exhausted your high moves!" << endl;
                        continue;
                    }
                    else {
                        highMoves++;
                        playerdamage = rand() % 12 + playerDamageBase + 10;
                    }
                }
                else {
                    cout << "Invalid input!" << endl;
                    continue;
                }

                ehealth -= playerdamage;

                if (ehealth <= 0) {
                    cout << "Monster health reached 0. You win!" << endl;
                    level++;
                    exp += 10;
                    cout << "You defeated the Monster and reached Level " << level << "!" << endl;
                    highMoves = 0;
                    mediumMoves = 0;
                    break;
                }

                int enemyDamage = rand() % 5 + 3;
                health -= enemyDamage;

                if (health <= 0) {
                    cout << "Your health reached 0. Monsters Wins!" << endl;
                    break;
                }

                cout << "Player's health: " << health << "Monsters health: " << ehealth << endl;
            }
            if (level > 6) {
                cout << "Congratulations! You've completed the game. Goodbye!" << endl;
                break;
            }
            if (ehealth > 0) {
                cout << "You couldn't defeat the Monsters. GAME OVER!" << endl;
                highMoves = 0;
                mediumMoves = 0;
            }

            cout << "Experience Points: " << exp << endl;
            string choice;
            do {
                cout << "Do you want to play again? (Y/N): ";
                getline(cin, choice);
                if (choice != "Y" && choice != "y" && choice != "N" && choice != "n")
                {
                    cout << "Invalid input! Please enter Y/y for Yes or N/n for No." << endl;
                }
            } while (choice != "Y" && choice != "y" && choice != "N" && choice != "n");

            playAgain = choice;
        }
    }
    else if (difficulty == "h" || difficulty == "H")
    {
        for (int o = 0; o <= 50; o++)
        {
            cout << "*";
        }
        cout << "\n\t\tHARD!" << endl;
        for (int p = 0; p <= 50; p++)
        {
            cout << "*";
        }
        cout << "\n\tIn a mystical land known as Eldoria \nwhere the forces of magic and technology coexist, an ancient prophecy foretells of a \nhero destined to restore balance to the realms. \nAs darkness looms, a young adventurer embarks on a journey to n\nfulfill their destiny and become the legendary Elemental Master." << endl;
        cout << "oohoo no ! Here comes the Deadly monsters who are Attacking the city Please Help the Civilians!";
        while (playAgain == "Y" || playAgain == "y")
        {
            string b;
            int ehealth;

            if (level == 2) {
                cout << "\tHere Comes the Flying Dragon Be safe!" << endl;
                ehealth = 180;
            }
            if (level == 3) {
                cout << "\tOH My God Our childer are under Attack! WE are begging you Please save our Childs!";
            }
            else if (level == 4) {
                cout << "\tMONSTER Falkor has arrived ! BE SAFE ! " << endl;
                ehealth = 300;
            }
            else if (level == 7) {
                cout << "\nHere comes THE Tyrent Head of all Monsters ! " << endl;
                ehealth = 300;
            }
            else {
                ehealth = 100 + (level - 1) * 25;
            }

            int health = 100;
            int playerDamageBase = 5 + (level - 1) * 3;
            cout << "\n L for LOW " << "\t\t" << "M for Medium" << "\t\t" << "H for High" << endl;
            while (ehealth > 0 && health > 0) {
                cout << "\tMedium moves" << "\t" << 4 - mediumMoves << "\tHigh moves " << 2 - highMoves << endl;
                getline(cin, b);
                int playerdamage = 0;

                if (b == "l" || b == "L") {
                    playerdamage = rand() % 6 + playerDamageBase;
                }
                else if (b == "m" || b == "M") {
                    if (mediumMoves >= 4) {
                        cout << "You have exhausted your medium moves!" << endl;
                        continue;
                    }
                    else {
                        mediumMoves++;
                        playerdamage = rand() % 12 + playerDamageBase + 5;
                    }
                }
                else if (b == "h" || b == "H") {
                    if (highMoves >= 2) {
                        cout << "You have exhausted your high moves!" << endl;
                        continue;
                    }
                    else {
                        highMoves++;
                        playerdamage = rand() % 14 + playerDamageBase + 5;
                    }
                }
                else {
                    cout << "Invalid input!" << endl;
                    continue;
                }

                ehealth -= playerdamage;

                if (ehealth <= 0) {
                    cout << "\tMonster health reached 0. You Win!" << endl;
                    level++;
                    exp += 7;
                    cout << "\tYou defeated the Monster and reached Level " << level << "!" << endl;
                    highMoves = 0;
                    mediumMoves = 0;
                    break;
                }

                int enemyDamage = rand() % 3 + 7;
                health -= enemyDamage;

                if (health <= 0) {
                    cout << "\tYour health reached 0.Monsters Wins!" << endl;
                    break;
                }

                cout << "Players health: " << health << " Monsters health: " << ehealth << endl;
            }
            if (level > 7) {
                cout << "Congratulations! You've completed the game. Goodbye!" << endl;
                break;
            }
            if (ehealth > 0) {
                cout << "You couldn't defeat the Monsters. GAME OVER!" << endl;
                highMoves = 0;
                mediumMoves = 0;
            }

            cout << "Experience Points: " << exp << endl;
            string choice;
            do {
                cout << "Do you want to play again? (Y/N): ";
                getline(cin, choice);
                if (choice != "Y" && choice != "y" && choice != "N" && choice != "n")
                {
                    cout << "Invalid input! Please enter Y/y for Yes or N/n for No." << endl;
                }
            } while (choice != "Y" && choice != "y" && choice != "N" && choice != "n");

            playAgain = choice;
        }


    }
    else
        cout << "wrong input press e for easy m for medium and h for hard " << endl;
    return 0;
}
