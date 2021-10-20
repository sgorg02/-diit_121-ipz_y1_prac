#include <iostream>
#include <Windows.h>
#include "func.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	double a, b, epsilon, Integ;
	double n; //��������� ����� �����
	int number_fun, number_metod;
	pointFunction mf;
	mf = 0;
	
	do
	{
		system("cls");

		std::cout << "������� �������: \n";
		std::cout << "1. 1 / log(x);\n";
		std::cout << "2. log(1 + x);\n";
		std::cout << "3. -3*x*x + 2*x + 9;\n";
		std::cout << "4. 2*pow(x, 3) - 7*x +4;\n";
		std::cout << "5. pow(x, 3) * 12 - 5;\n";
		std::cout << "6. �����.\n";
		std::cin >> number_fun;
		switch (number_fun)
		{
		case 1:
			mf = function1;
			break;
		case 2:
			mf = function2;
			break;
		case 3:
			mf = function3;
			break;
		case 4:
			mf = function4;
			break;
		case 5:
			mf = function5;
			break;
		default:
			std::cout << "You entered an invalid menu item!" << std::endl;
			break;
		}
		if (number_fun != 6)
		{
			do
			{

				system("cls");
				std::cout << "������� �����: \n";
				std::cout << "1. ����� ���� ������������\n";
				std::cout << "2. ����� ������ ������������.\n";
				std::cout << "3. ����� ������� ������������.\n";
				std::cout << "4. ����� ��������.\n";
				std::cout << "5. ����� ������� (����� ѳ������).\n";
				std::cout << "6. ����� � ���� �������\n";
				std::cout << "7. ����� � ��������\n";
				std::cin >> number_metod;
				switch (number_metod)
				{
				case 1:
				{
					system("cls");

					a = input_a();
					b = input_b();
					n = input_quantity_n();
					Integ = left_rectangle(mf, a, b, n);
					std::cout << "�������� ��������� (����� �.����.) �����: " << Integ << std::endl;

					system("pause");
				}
				break;
				case 2:
				{
					system("cls");

					a = input_a();
					b = input_b();
					n = input_quantity_n();
					Integ = right_rectangle(mf, a, b, n);
					std::cout << "�������� ��������� (����� �.����.) �����: " << Integ << std::endl;
					
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");

					a = input_a();
					b = input_b();
					n = input_quantity_n();
					Integ = middle_rectangle(mf, a, b, n);
					std::cout << "�������� ��������� (����� ��.����.) �����: " << Integ << std::endl;

					system("pause");
				}
				break;
				case 4:
				{
					system("cls");

					a = input_a();
					b = input_b();
					n = input_quantity_n();
					metod_trapeze(mf, a, b, n);

					system("pause");
				}
				break;
				case 5:
				{
					system("cls");

					a = input_a();
					b = input_b();
					n = input_quantity_n();
					epsilon = input_epsilon();
					Integ = metod_parabol(mf, a, b, n, epsilon);
					std::cout << "�������� ��������� �����:" << Integ << std::endl;

					system("pause");
				}
				break;
				case 7:
					return 0;
				default:
					break;					
				}
			} while (number_metod != 6);
		}
	} while (number_fun != 6);

}

