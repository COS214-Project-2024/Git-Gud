#include <iostream>
#include <thread>

void promptPlayer();
void displayHeading(int = 1);
void displayTowers();
void createBuilding();
void createUtility();
void upgradeBuilding();
void viewCityGrid();
void displayRecources();
void collectTax();
void copyBuilding();
void displayKey();
using namespace std;

/* string ASCII_Numbers[4][10] = {
    {"   _ ", "   ___ ", "   ___ ", "   ___ ", "   ___ ", "   ___ ", "   ___ ", "   ___ ", "   ___ ", "   ___ "},
    {"  | |", "  |_  |", "  |_  |", "  | | |", "  |  _|", "  |  _|", "  |_  |", "  | . |", "  | . |", "  |   |"},
    {"  | |", "  |  _|", "  |_  |", "  |_  |", "  |_  |", "  | . |", "    | |", "  | . |", "  |_  |", "  | | |"},
    {"  |_|", "  |___|", "  |___|", "    |_|", "  |___|", "  |___|", "    |_|", "  |___|", "  |___|", "  |___|"}
}; */

int main() {
    cout << "\e[H\e[2J";    // Clear the screen
    cout << "\e[?1049h"; // Alternate screen buffer
    /* for (int i = 32; i > 0; i--)
    {
        displayHeading(i);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    this_thread::sleep_for(chrono::milliseconds(2000)); */

    cout << "\e[?1049l"; // Restore screen buffer
    displayHeading();
    displayTowers();
    promptPlayer();
                                                                                        
    return 0;    
}

void displayHeading(int xPos) {
    cout << "\e[1J";    // Clear the screen
    cout << "\e[" << xPos << ";1H"; // Move cursor to row x, column 1
    cout << "\e[0;32m_________________________\e[0m/\\\\\\\\\\\\\\\\\\\e[0;32m_____________________________________\e[0m/\\\\\\\\\\\\\\\\\\\\\\\\\\\e[0;32m________________________\e[0m/\\\\\\\\\\\\\e[0;32m____________\e[0m/\\\\\\\e[0;32m________________________________________________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m_______________________\e[0m/\\\\\\////////\e[0;32m_____________________________________\e[0m\\/\\\\\\/////////\\\\\\\e[0;32m_____________________\e[0m\\////\\\\\\\e[0;32m___________\e[0m\\/\\\\\\\e[0;32m_______________________________________________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m______________________\e[0m/\\\\\\/\e[0;32m____________\e[0m/\\\\\\\e[0;32m_____\e[0m/\\\\\\\e[0;32m_________\e[0m/\\\\\\\e[0;32m__\e[0m/\\\\\\\e[0;32m__\e[0m\\/\\\\\\\e[0;32m_______\e[0m\\/\\\\\\\e[0;32m________________\e[0m/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m___________\e[0m\\/\\\\\\\e[0;32m______________________________________________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m______________________\e[0m/\\\\\\\e[0;32m_____________\e[0m\\///\e[0;32m___\e[0m/\\\\\\\\\\\\\\\\\\\\\\\e[0;32m___\e[0m\\//\\\\\\/\\\\\\\e[0;32m___\e[0m\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\e[0;32m___\e[0m/\\\\\\\e[0;32m____\e[0m/\\\\\\\e[0;32m_\e[0m\\///\e[0;32m_____\e[0m\\/\\\\\\\e[0;32m___________\e[0m\\/\\\\\\\e[0;32m______\e[0m/\\\\\\\\\\\\\\\\\e[0;32m___\e[0m/\\\\/\\\\\\\\\\\\\\\e[0;32m________________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m______________________\e[0m\\/\\\\\\\e[0;32m______________\e[0m/\\\\\\\e[0;32m_\e[0m\\////\\\\\\////\e[0;32m_____\e[0m\\//\\\\\\\\\\\e[0;32m____\e[0m\\/\\\\\\/////////\\\\\\\e[0;32m_\e[0m\\/\\\\\\\e[0;32m___\e[0m\\/\\\\\\\e[0;32m__\e[0m/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m______\e[0m/\\\\\\\\\\\\\\\\\\\e[0;32m____\e[0m/\\\\\\/////\\\\\\\e[0;32m_\e[0m\\/\\\\\\/////\\\\\\\e[0;32m______________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m_______________________\e[0m\\//\\\\\\\e[0;32m____________\e[0m\\/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m__________\e[0m\\//\\\\\\\e[0;32m_____\e[0m\\/\\\\\\\e[0;32m_______\e[0m\\/\\\\\\\e[0;32m_\e[0m\\/\\\\\\\e[0;32m___\e[0m\\/\\\\\\\e[0;32m_\e[0m\\/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m_____\e[0m/\\\\\\////\\\\\\\e[0;32m___\e[0m/\\\\\\\\\\\\\\\\\\\\\\\e[0;32m__\e[0m\\/\\\\\\\e[0;32m___\e[0m\\///\e[0;32m______________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m_________________________\e[0m\\///\\\\\\\e[0;32m__________\e[0m\\/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m_\e[0m/\\\\\e[0;32m___\e[0m/\\\\\e[0;32m_\e[0m/\\\\\\\e[0;32m______\e[0m\\/\\\\\\\e[0;32m_______\e[0m\\/\\\\\\\e[0;32m_\e[0m\\/\\\\\\\e[0;32m___\e[0m\\/\\\\\\\e[0;32m_\e[0m\\/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m____\e[0m\\/\\\\\\\e[0;32m__\e[0m\\/\\\\\\\e[0;32m__\e[0m\\//\\\\///////\e[0;32m___\e[0m\\/\\\\\\\e[0;32m____________________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m____________________________\e[0m\\////\\\\\\\\\\\\\\\\\\\e[0;32m_\e[0m\\/\\\\\\\e[0;32m____\e[0m\\//\\\\\\\\\\\e[0;32m___\e[0m\\//\\\\\\\\/\e[0;32m_______\e[0m\\/\\\\\\\\\\\\\\\\\\\\\\\\\\/\e[0;32m__\e[0m\\//\\\\\\\\\\\\\\\\\\\e[0;32m__\e[0m\\/\\\\\\\e[0;32m__\e[0m/\\\\\\\\\\\\\\\\\\\e[0;32m_\e[0m\\//\\\\\\\\\\\\\\/\\\e[0;32m__\e[0m\\//\\\\\\\\\\\\\\\\\\\\\e[0;32m__\e[0m\\/\\\\\\\e[0;32m___________________________\e[0m\e[0m" << endl;
    cout << "\e[0;32m________________________________\e[0m\\/////////\e[0;32m__\e[0m\\///\e[0;32m_____\e[0m\\/////\e[0;32m_____\e[0m\\////\e[0;32m__________\e[0m\\/////////////\e[0;32m_____\e[0m\\/////////\e[0;32m___\e[0m\\///\e[0;32m__\e[0m\\/////////\e[0;32m__\e[0m\\///////\\//\e[0;32m___\e[0m\\//////////\e[0;32m____\e[0m\\///\e[0;32m___________________________\e[0m\e[0m" << endl;
    cout << endl;  
}

void displayTowers() {
    cout << "\e[0;34m                |                                                                                                                                                           |               " << endl;
    cout << "                |                                                                                                                                                           |               " << endl;
    cout << "                |                                                                                                                                                           |               " << endl;
    cout << "              _/^\\_                                                                                                                                                       _/^\\_            " << endl;
    cout << "             //^^^\\\\                                                                                                                                                     //^^^\\\\          " << endl;
    cout << "            //^^^^^\\\\                                                                                                                                                   //^^^^^\\\\         " << endl;
    cout << "            ||.:::.||                                                                                                                                                   ||.:::.||           " << endl;
    cout << "           //.:::::.\\\\                                                                                                                                                 //.:::::.\\\\        " << endl;
    cout << "           ||:::::::||                                                                                                                                                 ||:::::::||          " << endl;
    cout << "         __||_ ::: _||__                                                                                                                                             __||_ ::: _||__        " << endl;
    cout << "         |.::|.:::.|::.|                                                                                                                                             |.::|.:::.|::.|        " << endl;
    cout << "        _|:::|:::::|:::|_                                                                                                                                           _|:::|:::::|:::|_       " << endl;
    cout << "       |\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|                                                                                                                                         |\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"|      " << endl;
    cout << "       |= .:::::::::::. =|                                                                                                                                         |= .:::::::::::. =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "       |= ::::::::::::: =|                                                                                                                                         |= ::::::::::::: =|      " << endl;
    cout << "      _|_ ::::::::::::: _|_                                                                                                                                       _|_ ::::::::::::: _|_     " << endl;
    cout << "     |:::|:::::::::::::|:::|                                                                                                                                     |:::|:::::::::::::|:::|    " << endl;
    cout << "    _|___|_:::::::::::_|___|_                                                                                                                                   _|___|_:::::::::::_|___|_   " << endl;
    cout << "   |:::::::|:::::::::|:::::::|                                                                                                                                 |:::::::|:::::::::|:::::::|  " << endl;
    cout << "  _|_::::::|:::::::::|::::::_|_                                                                                                                               _|_::::::|:::::::::|::::::_|_ " << endl;
    cout << " |:::|:::::|:::::::::|:::::|:::|                                                                                                                             |:::|:::::|:::::::::|:::::|:::|" << endl;
    cout << " |:::|=:=:=•=:=:=:=:=•=:=:=|:::|                                                                                                                             |:::|=:=:=•=:=:=:=:=•=:=:=|:::|" << endl;
    cout << " |=:=|II:II|:II:I:II:|II:II|=:=|                                                                                                                             |=:=|II:II|:II:I:II:|II:II|=:=|" << endl;
    cout << " |III|----'/.\"\"\"\"\"\"\".\\'----|III|                                                                                                                             |III|----'/.\"\"\"\"\"\"\".\\'----|III|" << endl;
    cout << " \"\"\"\"\"    //         \\\\    \"\"\"\"\"                                                                                                                             \"\"\"\"\"    //         \\\\    \"\"\"\"\"" << endl;
    cout << "---------'/           \\'---------                                                                                                                           ---------'/           \\'---------" << endl;
    cout << "---------'             '---------                                                                                                                           ---------'             '---------" << endl;
    cout << "=  =  =  =  =  =  =  =  =  =  = =                                                                                                                           =  =  =  =  =  =  =  =  =  =  = =\e[0m" << endl;
}

void promptPlayer() {  
    cout << "\e[40;1H" << endl;  // Move cursor to row 40, column 1 
    cout << "\e[0;33m==============================================================================================================================================================================================\e[0m" << endl;
    cout << "\033[s";    // Save cursor position
    cout << "•[1] Create Building (Note your desired coordinates before continuing)" << endl;
    cout << "•[2] Create Utility (Note your desired coordinates before continuing)" << endl;
    cout << "•[3] Upgrade Building (Note your desired coordinates before continuing)" << endl;
    cout << "•[4] Copy Building (Note your desired coordinates before continuing)" << endl;
    cout << "•[5] View City Grid" << endl;
    cout << "•[6] Display Recources" << endl;
    cout << "•[7] Collect Tax" << endl;
    
    cout << "•[Any] Exit" << endl;
    cout << endl;

    displayKey();

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            createBuilding();
            break;
        case 2:
            createUtility();
            break;
        case 3:
            upgradeBuilding();
            break;
        case 4:
            copyBuilding();
            break;
        case 5:
            viewCityGrid();
            break;
        case 6:
            displayRecources();
            break;
        case 7:
            collectTax();
            break;
        default:
            terminate();
            break;
    }

    //cout << "\e[46;1H" << endl;  // Move cursor to row 31, column 1
    promptPlayer();
}

void createBuilding(){ 
    int x, y;
    cout << "\e[?1049h"; // Alternate screen buffer     
    cout << "\e[H";    // Move cursor to row 1, column 1
    displayHeading();

    cout << "Enter Coordinates: (x enter y)\n";
    cin >> x >> y;
    cout << "\nWich type of building do you want to create:" << endl;
    cout << "•[1] Residential Building" << endl;
    cout << "•[2] Commercial Building" << endl;
    cout << "•[3] Industrial Building" << endl;
    cout << "•[4] Landscape" << endl;
    cout << "•[5] Road" << endl;
    cout << "•[Any] Cancel" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:

            break;
        default:
            break;
    }
    cout << "\e[?1049l"; // Restore screen buffer    
}

void createUtility(){
    int x, y;
    cout << "\e[?1049h"; // Alternate screen buffer     
    cout << "\e[H";    // Move cursor to row 1, column 1
    displayHeading();

    cout << "Enter Coordinates: (x enter y)\n";
    cin >> x >> y;

    cout << "\nWich type of Utility do you want to create:" << endl;
    cout << "•[1] Sewerage Facility" << endl;
    cout << "•[2] Power Plant" << endl;
    cout << "•[3] Water Supply" << endl;
    cout << "•[4] Waste Disposal Site" << endl;
    cout << "•[5] Hospital" << endl;
    cout << "•[6] Police Station" << endl;
    cout << "•[7] School" << endl;
    cout << "•[Any] Cancel" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:

            break;
        case 6:
            
            break;
        case 7:

            break;
        default:
            break;
    }
    cout << "\e[?1049l"; // Restore screen buffer   
}

void upgradeBuilding(){
    int x, y;
    cout << "\e[?1049h"; // Alternate screen buffer     
    cout << "\e[H";    // Move cursor to row 1, column 1
    displayHeading();

    cout << "Enter Coordinates: (x enter y)\n";
    cin >> x >> y;

    cout << "\nSpecify the type of upgrade:" << endl;
    cout << "•[1] Coffee Shop" << endl;
    cout << "•[2] Parking Lot" << endl;
    cout << "•[Any] Cancel" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            
            break;
        case 2:
            
            break;
        default:
            break;
    }
    cout << "\e[?1049l"; // Restore screen buffer   
}

void viewCityGrid(){
    cout << "\e[2J";    // Clear the screen
    displayHeading();
    displayTowers();
    int offset = 4;
    cout << "\e[" << offset << ";33H";    // Move cursor to row 11, column 33   
    cout << "\e[0;31m |01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901|";     
    cout << "\e[" << offset+1 << ";33H";    // Move cursor to row 11, column 33    
    cout << " |•====0====•====10===•====20===•====30===•====40===•====50===•====60===•====70===•====80===•====90===•====100==•====110==•=|";
    for (int i = 2; i < 36; i++)
    {
        cout << "\e[" << i+offset << ";33H";
        cout << "\e[0;31m" << (i-2)%10;
        if ((i-2)%10 == 0)  
        {
           cout << "|¦---------¦---------¦---------¦---------¦---------¦---------¦---------¦---------¦---------¦---------¦---------¦---------¦-|";
        }
        else
        cout << "|¦·········¦·········¦·········¦·········¦·········¦·········¦·········¦·········¦·········¦·········¦·········¦·········¦·|";
    }
    cout << "\e[" << offset+36 << ";33H\e[0;31m=============================================================================================================================";
}

void displayRecources(){
    int movey, wood, steel, concrete, electricity, water;
    cout << "\e[0;36m==============================================================================================================================================================================================\e[0m" << endl;

    cout << "\e[0;95mRecources:\n";

    cout << "   __  _______  _  ________  __" << endl;
    cout << "  /  |/  / __ \\/ |/ / __/\\ \\/ /" << endl;
    cout << " / /|_/ / /_/ /    / _/   \\  / " << endl;
    cout << "/_/  /_/\\____/_/|_/___/   /_/  ";
    cout << "\t$" << movey << endl;

    cout << " _      ______  ____  ___ " << endl;
    cout << "| | /| / / __ \\/ __ \\/ _ \\" << endl;
    cout << "| |/ |/ / /_/ / /_/ / / //" << endl;
    cout << "|__/|__/\\____/\\____/____/ ";
    cout << "\t" << wood << endl;

    cout << "   ____________________ " << endl;
    cout << "  / __/_  __/ __/ __/ / " << endl;
    cout << " _\\ \\  / / / _// _// /__" << endl;
    cout << "/___/ /_/ /___/___/____/";
    cout << "\t" << steel << endl;

    cout << "  _________  _  __________  ______________" << endl;
    cout << " / ___/ __ \\/ |/ / ___/ _ \\/ __/_  __/ __/" << endl;
    cout << "/ /__/ /_/ /    / /__/ , _/ _/  / / / _/  " << endl;
    cout << "\\___/\\____/_/|_/\\___/_/|_/___/ /_/ /___/  ";
    cout << "\t" << concrete << endl;

    cout << "   ______   __________________  _____________________  __" << endl;
    cout << "  / __/ /  / __/ ___/_  __/ _ \\/  _/ ___/  _/_  __/\\ \\/ /" << endl;
    cout << " / _// /__/ _// /__  / / / , _// // /___/ /  / /    \\  / " << endl;
    cout << "/___/____/___/\\___/ /_/ /_/|_/___/\\___/___/ /_/     /_/  ";
    cout << "\t" << electricity << endl;

    cout << " _      _____ _____________ " << endl;
    cout << "| | /| / / _ /_  __/ __/ _ \\" << endl;
    cout << "| |/ |/ / __ |/ / / _// , _/" << endl;
    cout << "|__/|__/_/ |_/_/ /___/_/|_| }";
    cout << "\t" << water << endl;
}

void collectTax(){

    cout << "Tax has been collected\nDisplay recourses to view new Budget:" << endl;
}

void copyBuilding(){
    int x, y, newx, newy;
    cout << "\e[?1049h"; // Alternate screen buffer     
    cout << "\e[H";    // Move cursor to row 1, column 1
    displayHeading();

    cout << "Enter Coordinates: (x enter y)\n";
    cin >> x >> y;

    cout << "\nWhere would you like to place this building:  (x enter y)" << endl;
    cin >> newx >> newy;


    cout << "\e[?1049l"; // Restore screen buffer
}

void displayKey(){
    int startRow = 40;
    int firstColumn = 120;

    cout << "\033[u";   // Restore cursor position
    cout << "\e[9A";    // Move cursor up 9
    cout << "\e[" << firstColumn << "C";    // Move cursor to right 100
    
    //cout << "\e[" << startRow << ";100H";    // Move cursor to row 11, column 33   
    cout << "\e[0;43mKey:"; // Set background color to yellow
    cout << "\033[s";    // Save cursor position  
    
    cout << "\033[u";   // Restore cursor position    
    cout << "\e[1B\e[" << firstColumn << "G" << "Road = '#'\t\t\tSewage Treatment Plant= 'S'";
    cout << "\e[1B\e[" << firstColumn << "G" << "Commercial Building = 'C'\tPower Station = 'P'";
    cout << "\e[1B\e[" << firstColumn << "G" << "Residential Building = 'R'\tWater Supply = 'W'";
    cout << "\e[1B\e[" << firstColumn << "G" << "Industrial BUilding = 'I'\tHealth Care = 'H'";
    cout << "\e[1B\e[" << firstColumn << "G" << "Landmark = '¤'\t\t\tLaw Enforcement = 'L'";
    cout << "\e[1B\e[" << firstColumn << "G" << "Transport Building= 'T'\t\tSchool = '$'";

    cout << "\e[0m" << endl;
}

/*
                     |
                     |
                     |
                   _\e[0m/^\\e[0;32m_
                  //^^^\\
                 //^^^^^\\
                 ||.:::.||
                //.:::::.\\
                ||:::::::||
              __||_ ::: _||__
              |.::|.:::.|::.|
             _|:::|:::::|:::|_
            |"""""""""""""""""|
            |= .:::::::::::. =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
            |= ::::::::::::: =|
           _|_ ::::::::::::: _|_
          |:::|:::::::::::::|:::|
         _|___|_:::::::::::_|___|_
        |:::::::|:::::::::|:::::::|
       _|_::::::|:::::::::|::::::_|_
      |:::|:::::|:::::::::|:::::|:::|
      |:::|=:=:=•=:=:=:=:=•=:=:=|:::|
      |=:=|II:II|:II:I:II:|II:II|=:=|
      |III|----'/.""""""".\`----|III|
      """""    //         \\    """""
--------------'/           \`--------------
--------------'             `--------------
=  =  =  =  =  =  =  =  =  =  =  =  =  =  =
*/
/*
________\e[0m/\\\\\\\\\\e[0;32m_____________________________________\e[0m/\\\\\\\\\\\\\\e[0;32m________________________\e[0m/\\\\\\\e[0;32m____________\e[0m/\\\\e[0;32m_______________________________________
______\e[0m/\\\////////\e[0;32m_____________________________________\e[0m\/\\\/////////\\\\e[0;32m_____________________\e[0m\////\\\\e[0;32m___________\e[0m\/\\\\e[0;32m______________________________________
_____\e[0m/\\\/\e[0;32m____________\e[0m/\\\\e[0;32m_____\e[0m/\\\\e[0;32m_________\e[0m/\\\\e[0;32m__\e[0m/\\\\e[0;32m__\e[0m\/\\\\e[0;32m_______\e[0m\/\\\\e[0;32m________________\e[0m/\\\\e[0;32m____\e[0m\/\\\\e[0;32m___________\e[0m\/\\\\e[0;32m_____________________________________
_____\e[0m/\\\\e[0;32m_____________\e[0m\///\e[0;32m___\e[0m/\\\\\\\\\\\\e[0;32m___\e[0m\//\\\/\\\\e[0;32m___\e[0m\/\\\\\\\\\\\\\\\e[0;32m___\e[0m/\\\\e[0;32m____\e[0m/\\\\e[0;32m_\e[0m\///\e[0;32m_____\e[0m\/\\\\e[0;32m___________\e[0m\/\\\\e[0;32m______\e[0m/\\\\\\\\\e[0;32m___\e[0m/\\/\\\\\\\\e[0;32m_______
_____\e[0m\/\\\\e[0;32m______________\e[0m/\\\\e[0;32m_\e[0m\////\\\////\e[0;32m_____\e[0m\//\\\\\\e[0;32m____\e[0m\/\\\/////////\\\\e[0;32m_\e[0m\/\\\\e[0;32m___\e[0m\/\\\\e[0;32m__\e[0m/\\\\e[0;32m____\e[0m\/\\\\e[0;32m______\e[0m/\\\\\\\\\\e[0;32m____\e[0m/\\\/////\\\\e[0;32m_\e[0m\/\\\/////\\\\e[0;32m_____
______\e[0m\//\\\\e[0;32m____________\e[0m\/\\\\e[0;32m____\e[0m\/\\\\e[0;32m__________\e[0m\//\\\\e[0;32m_____\e[0m\/\\\\e[0;32m_______\e[0m\/\\\\e[0;32m_\e[0m\/\\\\e[0;32m___\e[0m\/\\\\e[0;32m_\e[0m\/\\\\e[0;32m____\e[0m\/\\\\e[0;32m_____\e[0m/\\\////\\\\e[0;32m___\e[0m/\\\\\\\\\\\\e[0;32m__\e[0m\/\\\\e[0;32m___\e[0m\///\e[0;32m_____
________\e[0m\///\\\\e[0;32m__________\e[0m\/\\\\e[0;32m____\e[0m\/\\\\e[0;32m_\e[0m/\\\e[0;32m___\e[0m/\\\e[0;32m_\e[0m/\\\\e[0;32m______\e[0m\/\\\\e[0;32m_______\e[0m\/\\\\e[0;32m_\e[0m\/\\\\e[0;32m___\e[0m\/\\\\e[0;32m_\e[0m\/\\\\e[0;32m____\e[0m\/\\\\e[0;32m____\e[0m\/\\\\e[0;32m__\e[0m\/\\\\e[0;32m__\e[0m\//\\///////\e[0;32m___\e[0m\/\\\\e[0;32m___________
___________\e[0m\////\\\\\\\\\\e[0;32m_\e[0m\/\\\\e[0;32m____\e[0m\//\\\\\\e[0;32m___\e[0m\//\\\\/\e[0;32m_______\e[0m\/\\\\\\\\\\\\\/\e[0;32m__\e[0m\//\\\\\\\\\\e[0;32m__\e[0m\/\\\\e[0;32m__\e[0m/\\\\\\\\\\e[0;32m_\e[0m\//\\\\\\\/\\e[0;32m__\e[0m\//\\\\\\\\\\\e[0;32m__\e[0m\/\\\\e[0;32m__________
_______________\e[0m\/////////\e[0;32m__\e[0m\///\e[0;32m_____\e[0m\/////\e[0;32m_____\e[0m\////\e[0;32m__________\e[0m\/////////////\e[0;32m_____\e[0m\/////////\e[0;32m___\e[0m\///\e[0;32m__\e[0m\/////////\e[0;32m__\e[0m\///////\//\e[0;32m___\e[0m\//////////\e[0;32m____\e[0m\///\e[0;32m__________
*/
/* 
   _    ___    ___    ___    ___    ___    ___    ___    ___    ___ 
  | |  |_  |  |_  |  | | |  |  _|  |  _|  |_  |  | . |  | . |  |   |
  | |  |  _|  |_  |  |_  |  |_  |  | . |    | |  | . |  |_  |  | | |
  |_|  |___|  |___|    |_|  |___|  |___|    |_|  |___|  |___|  |___|
*/
//cout << "\033[s";    // Save cursor position
//cout << "\e[?1049l"; // Restore screen buffer
//cout << "\033[u";   // Restore cursor position