// Лабораторная работа № 10. Указатель на функцию
// Задание 1
// Вариант 3.
// Студента группы 10701219 Харлапа Сергея Александровича
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