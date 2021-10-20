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

	float **matrix = new float *[equations];//створюємо масив
	for (int i = 0; i < equations; i++)
	{
		matrix[i] = new float[changing];
	}

	//ввод масива
	for (int i = 0; i < equations; i++)

		for (int j = 0; j < changing; j++)
		{
			std::cout << " Елементи " << "[" << i + 1 << " , " << j + 1 << "]: ";
			std::cin >> matrix[i][j];
		}


	//виводимо масив
	std::cout << "Масив елементів: " << std::endl;
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
	//обратный ход
	xx[equations - 1] = matrix[equations - 1][equations];
	for (int i = equations - 2; i >= 0; i--)
	{
		xx[i] = matrix[i][equations];
		for (int j = i + 1; j < equations; j++)
		{
			xx[i] -= matrix[i][j] * xx[j];
		}
	}
	
	//вивід масива
	std::cout << "Масив елемантів із зміною: " << std::endl;
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
	std::cout << "Введіть ліву границю:  ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Повторить ввод. n повино бути цілим" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть ліву границю: ";
	}
	return a;
}
double input_b()
{
	double b;
	std::cout << "Введіть праву границю:  ";
	while (!(std::cin >> b) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Повторить ввод. n повино бути цілим" << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть праву границю: ";
	}

	return b;
}
double input_x(double a, double b)
{
	double _x;
	std::cout << "Введіть точку _х з проміжка:  ";
	while (!(std::cin >> _x) || (std::cin.peek() != '\n') || (_x < a) || (_x > b)) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Точка _x повина бути дійсним числом та вхадити у проміжок." << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть точку _х з проміжка: ";
	};

	return _x;
}
int input_quantity_equations()
{
	double equations;
	std::cout << "Кількість рівнянь:  ";
	while (!(std::cin >> equations) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Повторить ввод. Кількість рівнянь повино бути цілим числом" << std::endl;
		std::cout << std::endl;
		std::cout << "Кількість рівнянь: ";
	}

	return equations;
}
int input_quantity_changing()
{
	double changing;
	std::cout << "Кількість зміних:  ";
	while (!(std::cin >> changing) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		//std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "Помилка вводу! Повторить ввод. Кількість зміних повино бути цілим числом" << std::endl;
		std::cout << std::endl;
		std::cout << "Кількість зміних: ";
	}

	return changing;
}