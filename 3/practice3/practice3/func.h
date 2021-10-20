#ifndef func_H
#define func_H

typedef double(*pointFunction)(double);
typedef double(*pointMetod)(pointFunction, double, double, unsigned);

double left_rectangle(pointFunction mf, double a, double b, unsigned n);
double right_rectangle(pointFunction mf, double a, double b, unsigned n);
double middle_rectangle(pointFunction mf, double a, double b, unsigned n);
void metod_trapeze(pointFunction mf, double a, double b, unsigned n);
double metod_parabol(pointFunction mf, double a, double b, unsigned n, double eps);
double Integral(pointFunction mf, pointMetod Metod, double a, double b, double eps, unsigned &n);

double function1(double x);
double function2(double x);
double function3(double x);
double function4(double x);
double function5(double x);


double input_a();
double input_b();
double input_epsilon();
double input_quantity_n();

#endif