#ifndef metodH
#define metodH
typedef double(*pointFunction)(double);
typedef double(*pointfunction_derivative1)(double);
typedef double(*pointfunction_derivative2)(double);


double function1(double x);
double function_derivative1(double x);
double function_derivative2(double x);

double function2(double x);
double function2_derivative1(double x);
double function2_derivative2(double x);

double function3(double x);
double function3_derivative1(double x);
double function3_derivative2(double x);


//double function3(double x);


int input_a();
int input_b();

double metod_golden(double a, double b, pointFunction mf);
double metod_parabol(double a, double b, pointFunction mf);
double function_root(double a, double b, pointFunction mf, pointfunction_derivative1 mP1, pointfunction_derivative2 mP2);
#endif