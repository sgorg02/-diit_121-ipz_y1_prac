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
	std::cout << "�������� ���������: " << In << std::endl;

}
double metod_parabol(pointFunction mf, double a, double b, unsigned n, double eps)
{
	double I = eps + 1, I1 = 0;//I-���������� ����������� �������� ���������, I1-�����, � ������� N.
	for (int N = 2; (N <= 4) || (fabs(I1 - I)>eps); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N);//��� ��������������.
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += mf(a + h*i);//�������� � ��������� ���������, ������� ����� �������� �� 4.
			sum2 += mf(a + h*(i + 1));//�������� � ������� ���������, ������� ����� �������� �� 2.
		}
		sum = mf(a) + 4 * sum4 + 2 * sum2 - mf(b);//�������� �������� f(b) ��� ��� ����� ��������� ��� ������. 
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
	std::cout << "������ ��� ���� ������������ a = ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! a ������ ���� ������ ������" << std::endl;
		std::cout << std::endl;
		std::cout << "������ ��� ���� ������������ a = ";
	}
	return a;
}
double input_b()
{
	double b;
	std::cout << "������ ����� ���� ������������ b = ";
	while (!(std::cin >> b) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! b ������ ���� ������ ������" << std::endl;
		std::cout << std::endl;
		std::cout << "������ ����� ���� ������������ b = ";
	}

	return b;
}
double input_epsilon()
{
	double epsilon;
	std::cout << "������ ��������� ������� epsilon = ";
	while (!(std::cin >> epsilon) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! epsilon ������ ���� ������ ������" << std::endl;
		std::cout << std::endl;
		std::cout << "������ ��������� ������� epsilon = ";
	}

	return epsilon;
}
double input_quantity_n()
{
double n;
std::cout << "������ ������� �������� = ";
while (!(std::cin >> n) || (std::cin.peek() != '\n') || !(n > 1)) // ���� ��� �������� ������� ���� �� �������
{
//std::system("cls");
std::cin.clear();
while (std::cin.get() != '\n');
std::cerr << "������� �����! n ������ ���� ����� ������ �� ������ �� 1." << std::endl;
std::cout << std::endl;
std::cout << "������ ������� �������� = ";
}

return n;
}
