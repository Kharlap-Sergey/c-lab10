#include <iostream>
#include <cmath>
using namespace std;

double F1(double x) {
	double f_x = 2 * x - sin(5 * x);
	double f__x = 2 - 5 * cos(5 * x);

	return f_x / f__x;
}
double F2(double x) {
	double f_x = x*x - cos(x);
	double f__x = 2*x  + sin(x);

	return f_x / f__x;
}
double F3(double x) {
	double f_x = x * x - sin(5 * x);
	double f__x = 2 * x - 5 * cos(5 * x);

	return f_x / f__x;
}
double F4(double x) {
	double f_x = 2 * sin(x) - cos(x);
	double f__x = 2 * cos(x) + sin(x);

	return f_x / f__x;
}

double const eps = 0.0001;

double CalculateFunctionByConsernLineMethod(double a, double b, double x, double (*functionPatter)(double)) {
	double df = functionPatter(x);
	if (abs(df) < eps) return x;

	return CalculateFunctionByConsernLineMethod(a, b, x - df, functionPatter);
}

int main() {

	cout << CalculateFunctionByConsernLineMethod(0.4, 1, 0.4, F1) << endl;

	cout << CalculateFunctionByConsernLineMethod(0.4, 1, 0.4, F2) << endl;

	cout << CalculateFunctionByConsernLineMethod(0.4, 1, 0.4, F3) << endl;

	cout << CalculateFunctionByConsernLineMethod(0.4, 1, 0.4, F4) << endl;
	return 0;
}