#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "Header.h"
int * GetMemory(int *length)
{
	int *mas = NULL;
	printf("Введите длину массива: ");
	scanf("%d", length);
	mas = (int*)calloc(*length, sizeof(int));
	if (mas == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return mas;
}
void fillArray(int *mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(mass + i) = 10 + rand() % 90;
	}
}
void printArray(int *mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("[%d]", *(mass + i));
	}
	printf("\n");
}
void fillMatrix(int *mass, int length, int row)
{
	for (short int i = 0; i < length; i++)
		for (int j = 0; j < row; j++)
		{
			*(mass + i * length + j) = -40 + rand() % 90;
		}
}
void printMatrix(int *mass, int length, int row)
{
	for (short int i = 0; i < length; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d\t", *(mass + i*length + j));
		}
		printf("\n");
	}
}
void SearchMax(int *mass, int *mass1, int length, int row)
{
	mass1 = (int*)malloc(sizeof(int)*length);
	int max = 0;
	int i = 0;
	for (i = 0; i < length; i++)
	{
		max = 0;
		for (int j = 0; j < row; j++)
		{
			if (*(mass + i*length + j) > max)
			{
				max = *(mass + i*length + j);
			}
		}
		*(mass1 + i) = max;
		//mass1 = (int*)realloc(mass1, i+1);*/
	}
	//mass1 = (int*)realloc(mass1, i - 1);
	for (i = 0; i < 4; i++)
	{
		printf("%d\t", *(mass1 + i));
	}
	printf("\n");
	SearchMin(mass1, length);
}
void SearchMin(int *mass1, int length)
{
	int min = *mass1;
	for (int i = 0; i < length; i++)
	{
		if (*(mass1 + i) < min)
			min = *(mass1 + i);
	}
	printf("%d\n", min);
}
void ReversNumber(int *mass, int *mass1, int length)
{
	int a, b;
	for (int i = 0; i < length; i++)
	{
		a = *(mass + i) / 10;
		b = *(mass + i) % 10;
		*(mass1 + i) = b * 10 + a;
	}
}
void ArifmProgres(int *mass1, int length)
{
	int d;
	for (short int i = 0; i < length; i++)
	{
		if (*(mass1 + i) == (*mass1 + i * (*(mass1 + i) - *(mass1 + i - 1))))
		{
			d = *(mass1 + i) - *(mass1 + i - 1);
			printf("Числа образует арифм. прогрессию, её разность = %d\n", d);
		}
		else
			printf("Not образует. \n");
	}

}
int SearchSecondPositivElement(int *mass, int length)
{
	int counter = 0;
	for (short int i = 0; i < length; i++)
	{
		if (*(mass + i) > 0)
		{
			counter++;
			if (counter == 2)
			{
				return i;
			}
		}
	}
}
void ReverseElements(int *mas, int length)
{
	int check = length - 1, m;
	for (short int i = 0; i < length / 2; i++)
	{
		m = *(mas + i);
		*(mas + i) = *(mas + check);
		*(mas + check) = m;
		check--;
	}
}
void ElementNeKrat3(int *mass, int length)
{
	double summa = 0, sr = 0;
	for (short int i = 0; i < length; i++)
		if (*(mass + i) % 3 != 0)
		{
			summa += *(mass + i);
			sr++;
		}
	printf("Сумма элементов, не кратных 3 = %lf\n", summa);
	printf("Среднее арифметическое элеметов, не кратных 3 = %lf\n", summa / sr);
}
void SwitchMinAndLastElement(int *mass, int length)
{
	int min = *mass, s = 0, m;
	for (short int i = 0; i < length; i++)
	{
		if (min > *(mass + i))
		{
			s = i;
			min = *(mass + i);
		}
	}
	printf("\n");
	printf("Минимальный элемент массива = %d\n", min);
	m = *(mass + length - 1);
	*(mass + length - 1) = min;
	*(mass + s) = m;
}
long int TwoTo8(int *mass)
{
	long int proizv = 1;
	for (short int i = 2; i <= 8; i++)
	{
		proizv *= *(mass + i);
	}
	return proizv;
}
void ChetOrNechet(int *mas, int length)
{
	int counter1 = 0, counter2 = 0;
	printf("Массив, созданный из чётных элементов предыдущего: \n");
	for (short int i = 0; i < length; i++)
	{
		if (*(mas + i) % 2 == 0)
		{
			counter1++;
			printf("%d\t", *(mas + i));
		}
	}
	printf("\n");
	printf("Массив, созданный из нечётных элементов предыдущего: \n");
	for (short int i = 0; i < length; i++)
	{
		if (*(mas + i) % 2 != 0)
		{
			counter2++;
			printf("%d\t", *(mas + i));
		}
	}
	printf("\n");
	printf("Чётных элементов %d.\n", counter1);
	printf("Нечётных элементов %d.\n", counter2);
	if (counter1 < counter2)
		printf("Чётных элементов меньше, чем нечётных.\n");
	else if (counter1 > counter2)
		printf("Чётных элементов больше, чем нечётных.\n");
	else if (counter1 == counter2)
		printf("Одинаковое количество чётных и нечётных элементов.\n");
}
void NotBiggerThan10(int *mas, int length)
{
	int counter = 0;
	for (short int i = 0; i < length; i++)
		if (*(mas + i) > 0 && *(mas + i) > 10)
			counter++;

	int *MASSSS = (int*)calloc(counter, sizeof(int));
	int k = 0;
	for (short int i = 0; i < length; i++)
	{
		if (*(mas + i) > 0 && *(mas + i) > 10)
		{

			*(MASSSS + k) = *(mas + i);
			k++;
		}
	}
	//printArray(MASSSS, counter);
	printf("Кол-во положительных элементов = %d\n", counter);
	free(MASSSS);
}
void Neighbor(int *mass, int length)
{
	int num, min = *mass, index = 0;
	printf("Введите число: ");
	scanf("%d", &num);
	for (short int i = 0; i < length; i++)
	{
		if (num < 0)
		{
			if (abs(*(mass + i) - num) <= min)
			{
				min = abs(*(mass + i) - num);
				index = i;
			}
		}
		else
			if ((*(mass + i) - num) <= min)
			{
				min = (*(mass + i) - num);
				index = i;
			}
	}
	printf("Значение = %d; Индекс = %d\n", min, index);
}
void SortOpredStolbca(int *mass, int column, int row)
{
	int ROW, temp = 0, length = column;
	printf("Введите столбец массива, который хотите отсортировать: ");
	scanf("%d", &ROW);
	for (int i = 0; i < column; i++)
	{
		for (int j = row - 1; j > i; j--)
		{
			int k = j - 1;
			if (*(mass + j * column + ROW) > *(mass + k * column + ROW))
			{
				temp = *(mass + j * column + ROW);
				*(mass + j * column + ROW) = *(mass + k * column + ROW);
				*(mass + k * column + ROW) = temp;
			}
		}
	}
	printMatrix(mass, length, row);
}
void Pure(int *mass, int column, int row)
{
	int sum = 0;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (*(mass + i * column + j) % 2 != 0 && *(mass + i * column + j) < 0)
			{
				sum += abs(*(mass + i * column + j));
			}
		}
	}
	printf("Сумма по модулю отриц., нечётных элементов = %d\n", sum);
}