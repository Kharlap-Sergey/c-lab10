// task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double Sin(double x) {
    return sin(x);
}
double (Kv)(double x) {
    return x * x;
}
double (Gip)(double a, double b) {
    return sqrt(Kv(a) + Kv(b));
}
double (EXP)(double x, double y) {
    double ans = 1;
    for (int i = 0; i < y; i++) {
        ans *= x;
    }

    return ans;
}

int main(int argc, char **argv)
{
   
    double (*pToSin)(double) = Sin;
    double (*pToKv)(double) = Kv;
    double (*pToGip)(double, double) = Gip;
    double (*pToExp)(double, double) = EXP;

    while (true) {
        char* boof = new char[10];
        boof = *(++argv);
        cout << boof << "\n";
        if (strcmp(boof, "sin") == 0) {
            cout << "enter x- ";
            double x;
            cin >> x;
            cout << "sin(x) - " << pToSin(x);
        }
        else if (strcmp(boof, "kv") == 0) {
            cout << "enter x- ";
            double x;
            cin >> x;
            cout << "x^2 - " << pToKv(x);
        }
        else if(strcmp(boof, "gip") == 0) {
            cout << "enter(a, b)- ";
            double a, b;
            cin >> a >> b;
            cout << "gip(a,b) - " << pToGip(a, b);
        }
        else if (strcmp(boof, "exp") == 0) {
            double x, y;
            cout << "enter x, y -";
            cin >> x >> y;
            cout << "x^y - " << pToExp(x, y);
        }
        else {
            cout << "incorrect";
        }
        break;
    }

    return 0;
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
