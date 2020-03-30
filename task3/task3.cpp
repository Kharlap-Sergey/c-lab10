// Лабораторная работа № 10. Указатель на функцию
// Задание 3
// Вариант 3.
// Студента группы 10701219 Харлапа Сергея Александровича

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

double Parser(char* boof) {
    double integer = 0;
    double remainder = 0;
    double divider = 10;
    bool pointFlag = false();

    int i = 0;
    while (('0' <= boof[i]  && boof[i] <= '9') || boof[i] == '.') {
        if (boof[i] == '.') {
            pointFlag = true;
            i++;
            continue;
        }
        if (!pointFlag) {
            integer *= 10;
            integer += int(boof[i] - '0');
        }
        else {
            remainder += int(boof[i] - '0');
            remainder *= 10;
            divider *= 10;
        }
        i++;
    }

    return integer + remainder/divider;
}

int main(int argc, char **argv)
{
   
    double (*pToSin)(double) = Sin;
    double (*pToKv)(double) = Kv;
    double (*pToGip)(double, double) = Gip;
    double (*pToExp)(double, double) = EXP;

    while (true) {
        char* boof = new char[10];
        boof = argv[1];
        if (strcmp(boof, "sin") == 0) {
            double x = Parser(argv[2]);
            cout << "sin(x) - " << pToSin(x);
        }
        else if (strcmp(boof, "kv") == 0) {
            double x = Parser(argv[2]);
            cout << "x^2 - " << pToKv(x);
        }
        else if(strcmp(boof, "gip") == 0) {
            double a = Parser(argv[2]), b = Parser(argv[3]);
            cout << "gip(a,b) - " << pToGip(a, b);
        }
        else if (strcmp(boof, "exp") == 0) {
            double x = Parser(argv[2]), y = Parser(argv[3]);
            cout << "x^y - " << pToExp(x, y);
        }
        else {
            cout << "incorrect";
        }
        break;
    }

    return 0;
}