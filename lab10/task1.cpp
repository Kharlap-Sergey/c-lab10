// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Len(char* string) {
    int len = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int FirstSpaseID(char* string) {
    int pos = -1;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            pos = i;
            break;
        }
    }

    return pos;
}

int SpaceAmount(char* string) {
    int counter = -0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            counter++;
        }
    }

    return counter;
}

void DoFunction(int(*functions)(char*)){
    char string[100];
    getchar();
    cout << "enter string ";
    cin.getline(string, 100);
    cout << functions(string) << endl;
}
int main()
{
    int (*functions[3])(char* );

    functions[0] = Len;
    functions[1] = FirstSpaseID;
    functions[2] = SpaceAmount;

    while (true) {
        int chooser;
        bool breakFlag = false;
        cout << "enter 0 for getstringline\nenter 1 for finde first space\nenter 2 for find amount spaces\n\
else programm will stoped ";
        cin >> chooser;
        switch (chooser) {
        case 0: {
            DoFunction(functions[0]);
            break;
        }
        case 1: {
            DoFunction(functions[1]);
            break;
        }
        case 2: {
            DoFunction(functions[2]);
            break;
        }
        default: breakFlag = true;
        }

        if (breakFlag) {
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
