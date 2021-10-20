#include <iostream>
#include "metod.h"
#include <math.h>

const double golden_number = (1 + sqrt(5)) / 2;
const double epsilon = 0.00001;

double function1(double x)
{
	return 10 * (x * x * x) + 5 * (x * x) + 10;
}

double function_derivative1(double x)
{
	return 30 * (x * x) + 10;
}

double function_derivative2(double x)
{
	return 60 * x;
}


double function2(double x)
{
	return ((x * x * x) + (4 * x) - 3);
}

double function2_derivative1(double x)
{
	return ((3 * x * x) + 4);
}

double function2_derivative2(double x)
{
	return (6 * x);
}

double function3(double x) {
	return 11 * (x * x * x) - 5 * x + 9;
}
double function3_derivative1(double x) {
	return 33 * (x * x) + 5;
}
double function3_derivative2(double x) {
	return 66 * x;
}


double metod_golden(double a, double b, pointFunction mf)
{
	double x1, x2;
	double res;

	while (fabs(b - a) > epsilon)
	{
		x1 = b - (b - a) / golden_number;
		x2 = a + (b - a) / golden_number;
		if (mf(x2) <= mf(x1)) // Условие для поиска максимума
			a = x2;
		else
			b = x1;
	}
	res = (a + b) / 2;
	return res;
}

double metod_parabol(double a, double b, pointFunction mf)
{
	double h;
	double x0, x1, x2, x3;
	double xmin, xmin1;
	double d1, d2;
	bool minf;
	h = (fabs(b - a)) / 10;
	x0 = (a - b) / 2;
	if (mf(x0) < mf(x0 + h)) 
	{
		h = -h;
	}
	x1 = x0;
	x2 = x0 + h;
	x3 = x0 + 2 * h;
	xmin = x0; xmin1 = a;
	while ((xmin - xmin1) > epsilon)
	{
		xmin1 = xmin;
		minf = false;
		while (minf = false && x3 >= a && x3 <= b)
		{
			d1 = mf(x1) - mf(x2);
			d2 = mf(x3) - mf(x2);
			if (d1 >= 0 && d2 >= 0 && d1 + d2 >= 0) 
			{
				xmin = x1 + ((h * (d1 - d2)) / (2 * (d1 + d2)));
				minf = true;
			}
			else 
			{
				x1 = x2;
				x2 = x2;
				x3 += 2 * h;
			}
		}
		if (minf == false) 
		{
			xmin = x2;
		}
		h /= 2;
		x1 = xmin;
		x2 = x1 + h;
		x3 = x1 + 2 * h;
		if (mf(x0) < mf(x0 + h)) 
		{
			h = -h;
		}
	}


	
	return xmin;
}

double function_root(double a, double b, pointFunction mf, pointfunction_derivative1 mP1, pointfunction_derivative2 mP2)
{
	double initial_approach;
	double recur_form;
	if ((mf(a) * mP2(a)) > 0) 
	{
		initial_approach = a;
	}
	if ((mf(b) * mP2(b)) > 0) 
	{
		initial_approach = b;
	}
	do 
	{
		recur_form = (mf(initial_approach)) / (mP1(initial_approach));
		initial_approach = initial_approach - recur_form;
	} while ((mf(initial_approach)) / (mP1(initial_approach)) > epsilon);
	return initial_approach;
}


int input_a()
{	
	int a;
	std::cout << "Введіть нижню границю:  ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Повторить ввод. n повино бути цілим" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть нижню границю: ";
	}
	return a;
}

int input_b()
{
	int b;
	std::cout << "Введіть верхня границю:  ";
	while (!(std::cin >> b) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Повторить ввод. n повино бути цілим" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть верхня границю: ";
	}

	return b;
}