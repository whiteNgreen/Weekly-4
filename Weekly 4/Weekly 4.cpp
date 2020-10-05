// Weekly 4

#include <iostream>
#include <string>
#include <vector>

#include <conio.h>
#include <stdio.h>
#include <windows.h>    

#include <random>
#include <ctime>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

#define KEY_W 0x57
#define KEY_A 0x41
#define KEY_S 0x53
#define KEY_D 0x44

char t3Input;

std::vector <bool> ifHold(5);
std::vector <int> dice(5);
std::vector <int> diceCount(6);

namespace MyRandom {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

void clickToContinue() {
    std::cout << "Press any button to continue" << std::endl;
    _getch();
}

int rollDice() {

    std::uniform_int_distribution <> die{ 1,6 };
    return die(MyRandom::mersenne);
}

void task1();
void task2() {
    system("cls");
    const int num = 10;
    
    unsigned char enArray[num][num]{
    {'-','-','-','-','-','-','-','-','-','-',}, 
    {'-','-','-','-','-','-','G','-','-','-',}, //  'G' TERMINATE
    {'-','-','-','-','-','-','-','-','-','-',},
    {'-','-','-','/','-','-','-','-','-','-',}, // '/' to go 1 DOWN
    {'-','-','-','-','-','-','-','-','-','-',},
    {'-','-','-','-','-','-','-','-','-','-',},
    {'-','-','\\','-','-','-','-','-','-','-',}, // \'' to go 1 UP
    {'-','-','-','-','-','-','-','-','-','-',},
    {'-','-','-','-','-','-','-','-','-','-',},
    {'-','-','-','-','-','-','-','-','-','-',},
    };
    char input = 0;
    int posX = 0, posY = 0;
    char player = { 1 };
    
    while (input != KEY_ESC)    //esc key code is 27
    {
        std::cout << "Use w-a-s-d to move around. \n\\ moves you UP. \n/ moves you DOWN. \nG takes you back to the main menu. \nESC to exit" << "\n\n";

        enArray[posY][posX] = player;
    
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                std::cout << enArray[i][j] << ' ';
            }
            std::cout << '\n';
        }
        
        input = _getch();
        //keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);   //  Code found online to turn on CapsLock since my input is case 
        //keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    
        int prevPosX = posX;
        int prevPosY = posY;
        unsigned char space = { '-' };
    
        switch (input)
        {
    
        case 'w': case'W':
        //case KEY_W: //  Going UP
            if (enArray[posY - 1][posX] == '/') {
                posY;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY - 1][posX] == '\\') {
                posY--;
                posY--;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY - 1][posX] == 'G') {
                std::cout << "The End" << std::endl;
                clickToContinue();
                return;
            }
            else {
                posY--;
                enArray[prevPosY][prevPosX] = space;
            }
            break;
        case 'a': case'A':
        //case KEY_A: //  Going LEFT 
            if (enArray[posY][posX - 1] == '/') {
                posX--;
                posY++;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY][posX - 1] == '\\') {
                posX--;
                posY--;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY][posX - 1] == 'G') {
                std::cout << "The End" << std::endl;
                clickToContinue();
                return;
            }
            else {
                posX--;
                enArray[prevPosY][prevPosX] = space;
            }
            break;
        case 's': case'S':
        //case KEY_S: //  Going DOWN
            if (enArray[posY + 1][posX] == '/') {
                posY++;
                posY++;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY + 1][posX] == '\\') {
                posY;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY + 1][posX] == 'G') {
                std::cout << "The End" << std::endl;
                clickToContinue();
                return;
            }
            else {
                posY++;
                enArray[prevPosY][prevPosX] = space;
            }
            break;
        case 'd': case'D':
        //case KEY_D: //  Going RIGHT
            if (enArray[posY][posX + 1] == '/') {
                posX++;
                posY++;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY][posX + 1] == '\\') {
                posX++;
                posY--;
                enArray[prevPosY][prevPosX] = space;
            }
            else if (enArray[posY][posX + 1] == 'G') {
                std::cout << "The End" << std::endl;
                clickToContinue();
                return;
            }
            else {
                posX++;
                enArray[prevPosY][prevPosX] = space;
            }
            break;
        default:
            std::cout << std::endl << "Invalid input!" << std::endl;
            break;
    
        }
        system("cls");
    }

}
///  Task 3
int per = 10;

struct people {
    std::string name;
    int tlfNum;
};

std::vector <people> pep(per);

void printInfoTask3(int num) {
    pep.at(num).name[0] = toupper(pep.at(num).name[0]);

    for (int i = 0; i < pep.at(num).name.size(); i++) {
        if (pep.at(num).name[i] == ' ') {
            pep.at(num).name[i + 1] = toupper(pep.at(num).name[i + 1]);
        }
    }
    std::cout << "Name: " << pep.at(num).name << "\nPhone number: " << pep.at(num).tlfNum << "\n\n";
}
void task3() {
    std::cout << "How many people would you like to write the names and phonenumber of?\n";
    std::cin >> per;
    std::cout << '\n';

    if (per > 10) {
        std::cout << "You cannot list more than 10 people\n";
        std::cin >> per;
        std::cout << '\n';
    }

    pep.resize(per);

    for (int i = 0; i < pep.size(); i++) {
        std::cin.get();
        std::cout << "Write a name for person " << i + 1 << std::endl;
        std::getline(std::cin, pep.at(i).name);
    
        std::cout << "Please enter their phonenumber " << std::endl;
        std::cin >> pep.at(i).tlfNum;
        std::cout << '\n';
    }
    
    for (int i = 0; i < pep.size(); i++) {
        printInfoTask3(i);
    }

    clickToContinue();
}

void task4Print() {
    for (int i = 0; i < ifHold.size(); i++) {
        if (ifHold.at(i) == false) {
            std::cout << "Dice " << i + 1 << " = " << dice.at(i) << '\n';
        }
        else {
            std::cout << "Dice " << i + 1 << " = " << dice.at(i) << "\tHeld" << '\n';
        }
    }
}
void task4() {
    system("cls");
    do {
        /// Resetter Verdier
        int t3_6FCounter = 0;
        int pairCounter = 0;
        int thripleCounter = 0;
        int fourOfaKind = 0;
        int yatziCount = 0;
        bool pairPrint = true;
        for (int i = 0; i < diceCount.size(); i++) {
            diceCount.at(i) = 0;
        }

        std::cout << "Press R to roll dice\n";
        std::cout << "Press Q to quit\n";
        std::cout << "1-5 to withold a dice from rolling\n\n";

        t3Input = _getch();
        system("cls");

        switch (t3Input)
        {
        case 'r':case 'R':
            for (int i = 0; i < ifHold.size(); i++) {
                if (ifHold.at(i) == false) {
                    dice.at(i) = rollDice();
                }
                else {

                }
            }
            task4Print();

            std::cout << '\n';
            for (int i = 0; i < ifHold.size(); i++) {
                if (dice.at(i) == 6) {
                    t3_6FCounter++;
                }
            }
            if (t3_6FCounter == 1) {
                std::cout << "You got " << t3_6FCounter << " Dice that rolled 6\n";
            }
            else {
                std::cout << "You got " << t3_6FCounter << " Dices that rolled 6\n";
            }

            for (int i = 0; i < ifHold.size(); i++) {
                for (int j = 0; j < diceCount.size(); j++) {
                    if (dice.at(i) == j + 1) {
                        diceCount.at(j)++;
                    }
                }
            }

            for (int i = 0; i < diceCount.size(); i++) {
                if (diceCount.at(i) == 2) {
                    pairCounter++;
                }
                if (diceCount.at(i) == 3) {
                    thripleCounter++;
                }
                if (diceCount.at(i) == 4) {
                    fourOfaKind++;
                }
                if (diceCount.at(i) == 5) {
                    yatziCount++;
                }
            }

            do {
                if (yatziCount == 1) {
                    std::cout << "YATZI!\n\n";
                    pairPrint = false;
                }
                else if (fourOfaKind == 1) {
                    std::cout << "You got 4 of one kind\n\n";
                    pairPrint = false;
                }
                else if (thripleCounter == 1) {
                    if (pairCounter == 1) {
                        std::cout << "You built a House (3+2)\n\n";
                        pairPrint = false;
                    }
                    else {
                        std::cout << "You got 3 of one kind\n\n";
                        pairPrint = false;
                    }
                }
                else if (pairCounter >= 1) {
                    if (pairCounter == 2) {
                        std::cout << "You got 2 pairs\n\n";
                        pairPrint = false;
                    }
                    else if (pairCounter == 1) {
                        std::cout << "You got 1 pair\n\n";
                        pairPrint = false;
                    }
                }
                else {
                    std::cout << "No pairs no nothing\n\n";
                    pairPrint = false;
                }
            } while (pairPrint == true);

            std::cout << '\n';

            break;
        case '1':
            if (ifHold.at(0) == true) {
                ifHold.at(0) = false;
                task4Print();
                std::cout << "Dice 1 is no longer witheld\n";
                break;
            }
            ifHold.at(0) = true;
            task4Print();
            std::cout << "Dice 1 is witheld from rolling\n";
            break;

        case '2':
            if (ifHold.at(1) == true) {
                ifHold.at(1) = false;
                task4Print();
                std::cout << "Dice 2 is no longer witheld\n";
                break;
            }
            ifHold.at(1) = true;
            task4Print();
            std::cout << "Dice 2 is witheld from rolling\n";
            break;

        case '3':
            if (ifHold.at(2) == true) {
                ifHold.at(2) = false;
                task4Print();
                std::cout << "Dice 3 is no longer witheld\n";
                break;
            }
            ifHold.at(2) = true;
            task4Print();
            std::cout << "Dice 3 is witheld from rolling\n";
            break;

        case '4':
            if (ifHold.at(3) == true) {
                ifHold.at(3) = false;
                task4Print();
                std::cout << "Dice 4 is no longer witheld\n";
                break;
            }
            ifHold.at(3) = true;
            task4Print();
            std::cout << "Dice 4 is witheld from rolling\n";
            break;

        case '5':
            if (ifHold.at(4) == true) {
                ifHold.at(4) = false;
                task4Print();
                std::cout << "Dice 5 is no longer witheld\n";
                break;
            }
            ifHold.at(4) = true;
            task4Print();
            std::cout << "Dice 5 is witheld from rolling\n";
            break;

        case 'q': case 'Q':
            return;   /// skift til en bool for en while loop
            break;
        default:
            break;
        }
    }while (true);
}

int main()
{
    char taskChoice;

    do {
        
        system("cls");
        std::cout << "Which task would you like to see?\n" << "1. Change lowercase to Uppercase\n" << "2. Moving around in an array\n" << "3. Writing names and phonenumbers into 10 structs\n"
            << "4. Playing with dice\n" << "5. Exit" << std::endl;
        
        taskChoice = _getch();
        std::cout << '\n';
        
        switch (taskChoice) {
        case '1':          
            //task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            task3();
            break;
        case '4':
            task4();
            break;
        case '5':
            //exit = true;
            return 0;
        default:
            break;
        }
    } while (true);
}

void task1() {
    system("cls");
    char userIn[80];
    std::cin.get();
    std::cout << "Write a sentence under 80 characters that you would like to be changed to uppercase letters\n" << std::endl;
    std::cin.getline(userIn, 80);
    std::cout << std::endl;

    for (int i = 0; i < strlen(userIn); i++) {
        userIn[i] = toupper(userIn[i]);
    }
    std::cout << userIn << std::endl;
    std::cout << std::endl;

    clickToContinue();
    return;
} 

