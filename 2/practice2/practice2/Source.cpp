#include <iostream>
#include <Windows.h>
#include "func.h"
#include <math.h>


int main() 
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number_fun, number_metod;
	pointFunction mf; pointFunction mP1;pointFunction mP2;
	mf = 0;
	do
	{
		system("cls");

		std::cout << "За методом Лангранджа(всі наведені приклади):" << std::endl;
		std::cout << "1. sin(x)" << std::endl;
		std::cout << "2. tan(x)" << std::endl;
		std::cout << "3. x*x + 2 * x + 1" << std::endl;
		std::cout << "4. x*x*x + 1" << std::endl;
		std::cout << "5. x*x" << std::endl;
		std::cout << "6. Розв'язання системи алгебраїчних рівнянь" << std::endl;
		std::cout << "7. Вихід" << std::endl;
		std::cin >> number_fun;


		switch (number_fun)
		{
		case 1:
		{
			mf = function1;
		}
		break;
		case 2:
		{
			mf = function2;
		}
		break;
		case 3:
		{
			mf = function3;
		}
		break;
		case 4:
		{
			mf = function4;
		}
		break;
		case 5:
		{
			mf = function5;
		}
		break;
		case 6:
		{
			system("cls");

			int equations, changing;

			equations = input_quantity_equations();
			changing = input_quantity_changing();

			gauss(changing, equations);

			system("pause");
		}
		break;
		default:
			break;
		}

		if ((number_fun >= 1) && (number_fun <= 5))
		{

			system("cls");
			double x[10], y[10];
			double a, b, _x, n, L, h;

			a = input_a();
			b = input_b();

			n = (b - a) / 10;

			_x = input_x(a, b);

			std::cout << "";
			for (int i = 0; i < 10; i++)
			{
				x[i] = a + i*n;
				y[i] = mf(x[i]);
			};

			L = lagrange1(x, y, 10, _x);

			std::cout << "Поліндром Лагранжа L(x) равен: " << L << std::endl;

			h = (b - a) / (4 * n);
			std::cout << "x " << "\t" << "L(x) " << std::endl;
			for (_x = a; _x <= b;_x = _x + h)
			{
				std::cout << _x << "\t" << lagrange1(x, y, 10, _x) << std::endl;
			}
			system("pause");
		}

	} while (number_fun != 7);

	return 0;
}

