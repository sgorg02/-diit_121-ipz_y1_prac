#include <iostream>
#include "Windows.h"
#include <ctime>



void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct matrix
	{
		int rows, cols;
		int N;
		int** items;
		double* personal18;
	};

	matrix arr;

	std::cout << "������ ������� ����� �������:  ";
	while (!(std::cin >> arr.rows) || (std::cin.peek() != '\n') || !(arr.rows > 1)) // ���� ��� �������� ������� ���� �� �������
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		system("cls");
		std::cerr << "������� �����! �������� ����. ʳ������ ����� ������ ���� ����� ������ �� ����� �������." << std::endl;
		std::cout << std::endl;
		std::cout << "������ ������� ����� �������: ";
	}

	std::cout << "������ ������� �������� �������:  ";
	while (!(std::cin >> arr.cols) || (std::cin.peek() != '\n') || !(arr.cols > 1)) // ���� ��� �������� ������� ���� �� �������
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		system("cls");
		std::cerr << "������� �����! �������� ����. ʳ������ �������� ������ ���� ����� ������ �� ����� �������." << std::endl;
		std::cout << std::endl;
		std::cout << "������ ������� �������� �������: ";
	}

	
	
	arr.personal18 = new double [arr.rows];

	arr.items = new int *[arr.rows];
	for (int i = 0; i < arr.rows; i++)
	{
		arr.items[i] = new int[arr.cols];
	}


	int min_1 = 0;
	int max_1 = arr.rows;
	
	int min_2 = 0;
	int max_2 = arr.cols;


	int x, size;
	size = arr.cols * arr.rows;
	x = (size * 30) / 100;


	srand((unsigned int)time(NULL));
	for (int i = 0; i < arr.rows; ++i)
	{
		for (int j = 0; j < arr.cols; ++j)
		{
			arr.items[i][j] = 0;
		}
	}

	int* R;
	R = new int [x];

	for (int i = 0; i < x; i++)
	{
		R[i] = static_cast <int>((rand()) % static_cast <int>((max_1 - min_1) * 1)) + min_1;
	}


	int y = 0;
	int tmp;
	for (int i = x - 1; i >= y; i) //����������
	{
		for (int j = x - 1; j >= y; j--)
		{
			if (R[j] < R[j - 1])
			{
				tmp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = tmp;
			}
		}
		y++;
	}

	
	int* C;
	C = new int[x];

	for (int i = 0; i < x; i++)
	{
		C[i] = static_cast <int>((rand()) % static_cast <int>((max_2 - min_2) * 1)) + min_2;
	}


	int i, j;
	for (int n = 0; n < x; n++)
	{
		i = R[n];
		j = C[n];
		arr.items[i][j] = 1 + rand() % 100;
	}	
	

	int number;
	bool exit = true;
	int f; //���� ��� ������ � ������ ����
	do
	{
		system("cls");

		std::cout << "��������� �������:" << std::endl;
		for (int i = 0; i < arr.rows; i++)
		{
			for (int j = 0; j < arr.cols; j++)
			{
				std::cout << arr.items[i][j] << "\t";
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::cout << "1.��������� �������� �������" << std::endl;
		std::cout << "2.����� �������� ai,j �� ����" << std::endl;
		std::cout << "3.��������� �������� ������� �� �������� ��������� �� �� ��������" << std::endl;
		std::cout << "4.����� �������� ������� �� �������� ���������" << std::endl;
		std::cout << "5.����������� ����� � �������� ������������� ���������� �������� �������� �������" << std::endl;
		std::cout << "6.�����" << std::endl;
		std::cin >> number;
		std::cin.get();

		switch(number)
		{
		case 1:
		{
			system("cls");

			int coordinate_i, coordinate_j, new_number;
			i = 0;
			j = 0;
			exit = true;
			for (int n = 0; exit == true; n++)
			{
				system("cls");
				//std::cout << "��������� �������:" << std::endl;
				for (int i = 0; i < arr.rows; i++)
				{
					for (int j = 0; j < arr.cols; j++)
					{
						std::cout << arr.items[i][j] << "\t";
					}
					std::cout << std::endl;
				}
				std::cout << "������ ��������� ��������: ";
				std::cin >> coordinate_i >> coordinate_j;
				std::cout << "������ ����� �������: ";
				std::cin >> new_number;

				i = coordinate_i;
				j = coordinate_j;
				arr.items[i - 1][j - 1] = new_number;
				std::cout << std::endl;

				std::cout << "����� � ���� (���(1) ��� ͳ(0)): ";
				std::cin >> f;
				if (f == 1)
				{
					exit = false;

					system("cls");
				}
			}
		}
		break;
		case 2:
		{
			system("cls");

			int coordinate_i, coordinate_j, new_number;
			i = 0;
			j = 0;
			exit = true;
			for (int n = 0; exit == true; n++)
			{
				system("cls");
				//std::cout << "��������� �������:" << std::endl;
				for (int i = 0; i < arr.rows; i++)
				{
					for (int j = 0; j < arr.cols; j++)
					{
						std::cout << arr.items[i][j] << "\t";
					}
					std::cout << std::endl;
				}
				std::cout << "������ ��������� ��������: ";
				std::cin >> coordinate_i >> coordinate_j;
				std::cout << "������� ������ �� ��� �����������: " << arr.items[coordinate_i - 1][coordinate_j - 1] << std::endl;
				std::cout << "������ ����� �������: ";
				std::cin >> new_number;

				i = coordinate_i;
				j = coordinate_j;
				arr.items[i - 1][j - 1] = new_number;
				//std::cout << std::endl;

				std::cout << "����� � ���� (���(1) ��� ͳ(0)): ";
				std::cin >> f;
				if (f == 1)
				{
					exit = false;
				}
			}
		}
		break;
		case 3:
		{
			system("cls");

			int coordinate_i, coordinate_j;

			std::cout << "�����: " << std::endl;
			for (int i = 0; i < arr.rows; i++)
			{
				for (int j = 0; j < arr.cols; j++)
				{
					std::cout << arr.items[i][j] << "\t";
				}
				std::cout << std::endl;
			}

			i = 0;
			j = 0;
			std::cout << "������ ��������� ��������: ";
			std::cin >> coordinate_i >> coordinate_j;
			i = coordinate_i - 1;
			j = coordinate_j - 1;
			std::cout << "������� ������ �� ��� �����������: " << arr.items[i][j] << std::endl;


			int m = 0;
			for (; m < arr.cols; m++, j++)
			{
				arr.items[i][j] = arr.items[i][j];
			}

			m = coordinate_i;
			for (; m <= arr.rows; m++, i++)
			{
				for (int n = 0; n < arr.cols; n++)
				{
					arr.items[i][n] = arr.items[i][n + 1];
					arr.items[i][n + 1] = 0;
				}
				if (m != arr.rows)
				{
					arr.items[i][arr.cols - 1] = arr.items[i + 1][0];
					arr.items[i + 1][0] = 0;
				}
			}
			arr.items[arr.rows - 1][arr.cols - 1] = 0;


			std::cout << "�����: " << std::endl;
			for (int i = 0; i < arr.rows; i++)
			{
				for (int j = 0; j < arr.cols; j++)
				{
					std::cout << arr.items[i][j] << "\t";
				}
				std::cout << std::endl;
			}

			system("pause");
		}
		break;
		case 4:
		{
			system("cls");

			std::cout << "�����: " << std::endl;
			for (int i = 0; i < arr.rows; i++)
			{
				for (int j = 0; j < arr.cols; j++)
				{
					std::cout << arr.items[i][j] << "\t";
				}
				std::cout << std::endl;
			}

			int comparison_number;
			bool check = true;
			std::cout << "������ ��������: ";
			std::cin >> comparison_number;

			for (int i = 0; i < arr.rows; i++)
			{
				for (int j = 0; j < arr.cols; j++)
				{
					if (arr.items[i][j] == comparison_number)
					{
						std::cout << "� ����� �������: <" << i << ";" << j << ">" << arr.items[i][j] << std::endl;
						check = false;
					}
				}
			}

			if (check)
			{
				std::cout << "������ �������� ���� � �������" << std::endl;
			}
			system("pause");
		}
		break;
		case 5:
		{
			system("cls");

			double sum = 0;
			double sum_1 = 0;
			double counter = 0;

			for (int m = 0; m < arr.rows; m++)
			{
				for (int n = 0; n < arr.cols; n++)
				{
					if (arr.items[m][n] > 0)
					{
						sum += arr.items[m][n];
						counter++;
					}
				}

				if (counter != 0)
				{
					sum_1 = sum / counter;
					arr.personal18[m] = sum_1;
					sum = 0;
					sum_1 = 0;
					counter = 0;
				}
				else
				{
					arr.personal18[m] = 0;
				}
			}

			std::cout << "����� � �������� ������������ �������� ����� �������:" << std::endl;
			for (int m = 0; m < arr.rows; m++)
			{
				std::cout << arr.personal18[m] << " ";
			}
			std::cout << std::endl << std::endl;

			system("pause");
		}
		break;
		case 6:
		return;
		break;
		default:
			break;
		}

	}while (number != 6);

	return;
}