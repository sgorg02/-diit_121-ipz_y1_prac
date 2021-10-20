#ifndef func_H
#define func_H

typedef double(*pointFunction)(double);

double lagrange1(double* x, double* y, short n, double _x);
void gauss(int changing, int equations);

double function1(double x);
double function2(double x);
double function3(double x);
double function4(double x);
double function5(double x);

double input_a();
double input_b();
double input_x(double a, double b);


int input_quantity_equations();
int input_quantity_changing();

#endif