#include <iostream>
#include <Windows.h>
#include <cmath>
#include <math.h>
#include "metod.h"

const double golden_number = (1 + sqrt(5)) / 2;
const double epsilon = 0.000001;



void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number_fun, number_metod;
	double a, b, o, f_initial_approach;
	pointFunction mf; pointFunction mP1;pointFunction mP2;
	mf = 0;
	do
	{
		system("cls");

		std::cout << "1. 10*(x*x*x) + 5*(x*x) + 10" << std::endl;
		std::cout << "2. (x*x*x*) + (4*x)-3" << std::endl;
		std::cout << "3. 11*(x*x*x) - 5*x + 9" << std::endl;
		std::cout << "4. Вихід" << std::endl;
		std::cin >> number_fun;


		switch (number_fun)
		{
		case 1:
		{
			mf = function1;
			mP1 = function_derivative1;
			mP2 = function_derivative2;
		}
		break;
		case 2:
		{
			mf = function2;
			mP1 = function2_derivative1;
			mP2 = function2_derivative2;
		}
		break;
		case 3:
		{
			mf = function3;
			mP1 = function3_derivative1;
			mP2 = function3_derivative2;
		}
		break;
		default:
			break;
		}
		if(number_fun != 4)
		{
			do
			{
				system("cls");
				std::cout << "1. Метод золотого сечения" << std::endl;
				std::cout << "2. Метод парабол" << std::endl;
				std::cout << "3. Mетод дотичних" << std::endl;
				std::cout << "4. Вихід" << std::endl;
				std::cin >> number_metod;

				switch (number_metod)
				{
				case 1:
				{
					system("cls");

					a = input_a();
					b = input_b();
					o = metod_golden(a, b, mf);
					std::cout << "Відповідь: " << o << ", " << mf(o) << std::endl;
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");

					a = input_a();
					b = input_b();
					o = metod_parabol(a, b, mf);

					std::cout << "Відповідь: " << o << ", " << mf(o) << std::endl;
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");

					a = input_a();
					b = input_b();
					f_initial_approach = function_root(a, b, mf, mP1, mP2);
					std::cout << "Відповідь: " << f_initial_approach << std::endl;
					system("pause");
				}
				break;
				default:
					break;
				}
			} while (number_metod != 4);
		}


	} while (number_fun != 4);
		return;
	}