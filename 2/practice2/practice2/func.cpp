#include <iostream>
#include "func.h"
#include <math.h>

double lagrange1(double* x, double* y, short n, double _x)
{
	double L = 0.0;
	for (short i = 0; i < n; i++)
	{
		double P = 1.0;
		for (short j = 0; j < n; j++) 
		{
			if (j != i)
			{
				P *= (_x - x[j]) / (x[i] - x[j]);
			}
		}
		L += P * y[i];
	}

	return L;
}
void gauss(int changing, int equations)
{
	changing += 1;

	float **matrix = new float *[equations];//��������� �����
	for (int i = 0; i < equations; i++)
	{
		matrix[i] = new float[changing];
	}

	//���� ������
	for (int i = 0; i < equations; i++)

		for (int j = 0; j < changing; j++)
		{
			std::cout << " �������� " << "[" << i + 1 << " , " << j + 1 << "]: ";
			std::cin >> matrix[i][j];
		}


	//�������� �����
	std::cout << "����� ��������: " << std::endl;
	for (int i = 0; i < equations; i++)
	{
		for (int j = 0; j < changing; j++)
		{
			std::cout <<  matrix[i][j] << "	";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	float  tmp;
	int k;
	float *xx = new float[changing-1];

	for (int i = 0; i < equations; i++)
	{
		tmp = matrix[i][i];
		for (int j = equations; j >= i; j--)
		{
			matrix[i][j] /= tmp;
		}
		for (int j = i + 1; j < equations; j++)
		{
			tmp = matrix[j][i];
			for (int k = equations; k >= i; k--)
			{
				matrix[j][k] -= tmp*matrix[i][k];
			}
		}
	}
	//�������� ���
	xx[equations - 1] = matrix[equations - 1][equations];
	for (int i = equations - 2; i >= 0; i--)
	{
		xx[i] = matrix[i][equations];
		for (int j = i + 1; j < equations; j++)
		{
			xx[i] -= matrix[i][j] * xx[j];
		}
	}
	
	//���� ������
	std::cout << "����� �������� �� �����: " << std::endl;
	for (int i = 0; i < changing-1; i++)
	{
		std::cout << "x" << i << " = " << xx[i] << std::endl;
	}
	std::cout << std::endl;

	delete[] matrix;
}


double function1(double x)
{
	return sin(x);
}
double function2(double x)
{
	return tan(x);
}
double function3(double x)
{
	return x*x + 2 * x + 1;
}
double function4(double x)
{
	return x*x*x + 1;
}
double function5(double x)
{
	return x*x;
}



double input_a()
{
	double a;
	std::cout << "������ ��� �������:  ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! ��������� ����. n ������ ���� �����" << std::endl;
		std::cout << std::endl;
		std::cout << "������ ��� �������: ";
	}
	return a;
}
double input_b()
{
	double b;
	std::cout << "������ ����� �������:  ";
	while (!(std::cin >> b) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! ��������� ����. n ������ ���� �����" << std::endl;
		std::cout << std::endl;
		std::cout << "������ ����� �������: ";
	}

	return b;
}
double input_x(double a, double b)
{
	double _x;
	std::cout << "������ ����� _� � �������:  ";
	while (!(std::cin >> _x) || (std::cin.peek() != '\n') || (_x < a) || (_x > b)) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! ����� _x ������ ���� ������ ������ �� ������� � �������." << std::endl;
		std::cout << std::endl;
		std::cout << "������ ����� _� � �������: ";
	};

	return _x;
}
int input_quantity_equations()
{
	double equations;
	std::cout << "ʳ������ ������:  ";
	while (!(std::cin >> equations) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! ��������� ����. ʳ������ ������ ������ ���� ����� ������" << std::endl;
		std::cout << std::endl;
		std::cout << "ʳ������ ������: ";
	}

	return equations;
}
int input_quantity_changing()
{
	double changing;
	std::cout << "ʳ������ �����:  ";
	while (!(std::cin >> changing) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "������� �����! ��������� ����. ʳ������ ����� ������ ���� ����� ������" << std::endl;
		std::cout << std::endl;
		std::cout << "ʳ������ �����: ";
	}

	return changing;
}