#include <iostream>
#include <Windows.h>
#include "Usermenu.h"

using namespace std;

void helpUser() {
    string command;
    cout << "---------------------- Welcome to Neutr0n Operating System! ---------------------" << endl;
    Sleep(2500);
    system("cls");

    cout << "Available commands:" << endl;
    cout << "'calc' - Run calculator" << endl;
    cout << "'exit' - Shut down the system" << endl;

    cout << "enter your command: ";
    cin >> command;

    if (command == "setup") {
        displayMenu();
    }
    else if (command == "exit") {
        cout << "System shutting down..." << endl;
        exit(0);
    }
    else {
        cout << "Unknown command!" << endl;
    }
}

int main() {
    while (true)
    {
        helpUser();
    }
}
