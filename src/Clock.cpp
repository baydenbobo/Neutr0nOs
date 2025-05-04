#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void DisplayTime() 
{
    system("cls");

    while (true) 
    {
        system("cls");
        time_t now = time(0);
        tm* localTime = localtime(&now);

        cout << "Current Time: "
            << (localTime->tm_hour < 10 ? "0" : "") << localTime->tm_hour << ":"
            << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << ":"
            << (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec << endl;

        Sleep(1000);
    }

    cout << endl;
    system("pause");
    system("cls");
}


