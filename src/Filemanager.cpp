#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

void listDirectory(const fs::path& currentPath) 
{
    cout << "directory: " << currentPath << endl;
    for (const auto& entry : fs::directory_iterator(currentPath))
        cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << endl;
}

void createFile(const fs::path& filePath) 
{
    ofstream file(filePath);
    if (file) 
    {
        cout << "file created: " << filePath << endl;
    }
    else 
    {
        cerr << "error creating file: " << filePath << endl;
    }
}

void createDirectory(const fs::path& dirPath) 
{
    if (fs::create_directory(dirPath)) 
    {
        cout << "directory created: " << dirPath << endl;
    }
    else 
    {
        cerr << "error creating directory: " << dirPath << endl;
    }
}

void runFileManager() 
{
    fs::path currentPath = fs::current_path();
    string command;

    system("cls");

    cout << "Simple File Manager\n";
    cout << "Commands: ls, cd <path>, mkdir <name>, touch <name>, exit\n";

    while (true)
    {
        cout << currentPath.string() << " > ";
        getline(cin, command);

        if (command == "exit")
        {
            break;
        }
        else if (command == "ls")
        {
            listDirectory(currentPath);
        }
        else if (command.starts_with("cd ")) 
        {
            string path = command.substr(3);
            fs::path newPath = currentPath / path;
            if (fs::exists(newPath) && fs::is_directory(newPath)) 
            {
                currentPath = fs::canonical(newPath);
            }
            else 
            {
                cerr << "directory not found: " << path << endl;
            }
        }
        else if (command.starts_with("mkdir ")) 
        {
            string dirName = command.substr(6);
            createDirectory(currentPath / dirName);
        }
        else if (command.starts_with("touch ")) 
        {
            string fileName = command.substr(6);
            createFile(currentPath / fileName);
        }
        else {
            cerr << "unknown command: " << command << endl;
        }
    }

    cout << endl;
    system("pause");
    system("cls");
}
