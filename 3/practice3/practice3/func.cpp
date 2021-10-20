#include <iostream>
#include "func.h"
#include <math.h>


double function1(double x)
{
	return 1 / log(x);
}
double function2(double x)
{
	return log(1 + x);
}
double function3(double x)
{
	return -3 * x*x + 2 * x + 9;
}
double function4(double x)
{
	return 2 * pow(x, 3) - 7 * x + 4;
}
double function5(double x)
{
	return pow(x, 3) * 12 - 5;
}


double I(double a, double b, unsigned n, double y)
{
	return ((b - a) / (2 * n)*y);
}


double left_rectangle(pointFunction mf, double a, double b, unsigned n)
{
	double Res = 0.0;
	double h = (b - a) / n;
	for (double x = a; x <= b; x += h)
		Res += (*mf)(x);
	return Res*h;
}
double right_rectangle(pointFunction mf, double a, double b, unsigned n)
{
	double Res = 0.0;
	double h = (b - a) / n;
	for (double x = a + h; x <= b;x += h)
		Res += (*mf)(x);
	return Res*h;
}
double middle_rectangle(pointFunction mf, double a, double b, unsigned n)
{
	double s = (mf(a) + mf(b)) / 2;
	double h = (b - a) / n;
	for (int i = 1; i <= (n - 1); i++)
	{
		s += mf(a + i * h);
	}
	double I = h*s;

	return I;
}
void metod_trapeze(pointFunction mf, double a, double b, unsigned n)
{
	double y, dy, In;

	dy = (b - a) / n;
	y = 0.0;
	y += mf(a) + mf(b);
	for (int i = 1; i <= n; i++)
	{
		y += 2 * (mf(a + dy * i));
	}
	In = I(a, b, n, y);
	std::cout << "Значення інтеграла: " << In << std::endl;

}
double metod_parabol(pointFunction mf, double a, double b, unsigned n, double eps)
{
	double I = eps + 1, I1 = 0;//I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
	for (int N = 2; (N <= 4) || (fabs(I1 - I)>eps); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N);//Шаг интегрирования.
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += mf(a + h*i);//Значения с нечётными индексами, которые нужно умножить на 4.
			sum2 += mf(a + h*(i + 1));//Значения с чётными индексами, которые нужно умножить на 2.
		}
		sum = mf(a) + 4 * sum4 + 2 * sum2 - mf(b);//Отнимаем значение f(b) так как ранее прибавили его дважды. 
		I = I1;
		I1 = (h / 3)*sum;
	}
	return I1;
}
double Integral(pointFunction mf, pointMetod Metod, double a, double b, double eps, unsigned &n)
{
	double Integral_old, Integral_new = 0.0;
	Integral_old = (*Metod)(mf, a, b, n);
	while (fabs(Integral_old - Integral_new)>eps)
	{
		Integral_new = Integral_old;
		n *= 2;
		Integral_old = (*Metod)(mf, a, b, n);
	}
	return Integral_old;
}


double input_a()
{
	double a;
	std::cout << "Введіть ліву межу інтегрування a = ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! a повино бути дійсним числом" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть ліву межу інтегрування a = ";
	}
	return a;
}
double input_b()
{
	double b;
	std::cout << "Введіть праву межу інтегрування b = ";
	while (!(std::cin >> b) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! b повино бути дійсним числом" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть праву межу інтегрування b = ";
	}

	return b;
}
double input_epsilon()
{
	double epsilon;
	std::cout << "Введіть необхідну точність epsilon = ";
	while (!(std::cin >> epsilon) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! epsilon повино бути дійсним числом" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть необхідну точність epsilon = ";
	}

	return epsilon;
}
double input_quantity_n()
{
double n;
std::cout << "Введіть кількість розбиття = ";
while (!(std::cin >> n) || (std::cin.peek() != '\n') || !(n > 1)) // цикл для перевірки введеної зміної на символи
{
//std::system("cls");
std::cin.clear();
while (std::cin.get() != '\n');
std::cerr << "Помилка вводу! n повино бути цілим числом та більшим за 1." << std::endl;
std::cout << std::endl;
std::cout << "Введіть кількість розбиття = ";
}

return n;
}
