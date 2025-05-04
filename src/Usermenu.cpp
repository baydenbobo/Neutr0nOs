#include <iostream>
#include <string>
#include <Windows.h>
#include "Calculator.h"
#include "Clock.h"
#include "Snake.h"
#include "Filemanager.h"

using namespace std;

bool running = true;

void displayMenu()
{
    system("cls");
    while (running)
    {
        cout << "$$\\   $$\\                       $$\\                $$$$$$\\                   $$$$$$\\   $$$$$$\\  " << endl; Sleep(75);
        cout << "$$$\\  $$ |                      $$ |              $$$ __$$\\                 $$  __$$\\ $$  __$$\\ " << endl; Sleep(75);
        cout << "$$$$\\ $$ | $$$$$$\\  $$\\   $$\\ $$$$$$\\    $$$$$$\\  $$$$\\ $$ |$$$$$$$\\        $$ /  $$ |$$ /  \\__|" << endl; Sleep(75);
        cout << "$$ $$\\$$ |$$  __$$\\ $$ |  $$ |\\_$$  _|  $$  __$$\\ $$\\$$\\$$ |$$  __$$\\       $$ |  $$ |\\$$$$$$\\  " << endl; Sleep(75);
        cout << "$$ \\$$$$ |$$$$$$$$ |$$ |  $$ |  $$ |    $$ |  \\__|$$ \\$$$$ |$$ |  $$ |      $$ |  $$ | \\____$$\\ " << endl; Sleep(75);
        cout << "$$ |\\$$$ |$$   ____|$$ |  $$ |  $$ |$$\\ $$ |      $$ |\\$$$ |$$ |  $$ |      $$ |  $$ |$$\\   $$ |" << endl; Sleep(75);
        cout << "$$ | \\$$ |\\$$$$$$$\\ \\$$$$$$  |  \\$$$$  |$$ |      \\$$$$$$  /$$ |  $$ |       $$$$$$  |\\$$$$$$  |" << endl; Sleep(75);
        cout << "\\__|  \\__| \\_______| \\______/    \\____/ \\__|       \\______/ \\__|  \\__|       \\______/  \\______/ " << endl; Sleep(75);
        cout << endl; Sleep(75); cout << endl; Sleep(75); cout << endl; Sleep(75); cout << endl; Sleep(75);

        cout << "==================================================\n"; Sleep(75);
        cout << "||           Aviable System Commands            ||\n"; Sleep(75);
        cout << "||    'snake' -- Command to play snake          ||\n"; Sleep(75);
        cout << "||    'file' -- File Manager                    ||\n"; Sleep(75);
        cout << "||    'calc' -- Calculator                      ||\n"; Sleep(75);
        cout << "||    'clock' -- Time                           ||\n"; Sleep(75);
        cout << "||    'exit' -- Shut down system                ||\n"; Sleep(75);
        cout << "==================================================\n"; Sleep(75);

        string user_cmd;
        cout << "Choose command: ";
        cin >> user_cmd;

        if (user_cmd == "SNAKE" || user_cmd == "snake" || user_cmd == "Snake")
            runSnake();
        else if (user_cmd == "file" || user_cmd == "FILE" || user_cmd == "File")
            runFileManager();
        else if (user_cmd == "calc" || user_cmd == "CALC" || user_cmd == "Calc")
            runCalc();
        else if (user_cmd == "clock" || user_cmd == "CLOCK" || user_cmd == "Clock")
            displayTime();
        else if (user_cmd == "exit" || user_cmd == "EXIT" || user_cmd == "Exit")
        {
            running = false;
            exit(0);
        }
        else
        {
            cout << "invalid command, try again.\n";
            return;
        }
    }
}