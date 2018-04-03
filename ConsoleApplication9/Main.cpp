#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Header.h"
void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	short int w;
	printf("Введите номер задания: ");
	scanf("%hu", &w);
	switch (w)
	{
	case 1:
	{
		/*2.	В прямоугольной матрице найти наибольший из
			минимальных элементов строк матрицы*/
		int *mass = NULL;
		int *mass1 = NULL;

		mass = (int*)malloc(sizeof(int) * 4 * 5);
		fillMatrix(mass, 4, 5);
		printMatrix(mass, 4, 5);
		SearchMax(mass, mass1, 4, 5);
		free(mass);
	}
	break;
	case 2:
	{
		/*3.	Ввести массив, состоящий из 15 - ти элементов(двузначные целые числа).
			Изменить разрядность цифр, образующих элементы исходного массива и, таким образом,
			сформировать новый массив.Например, исходный массив : 25 71 84…,
			новый массив : 52 17 48….*/
		int *mass = NULL;
		mass = (int*)malloc(sizeof(int) * 15);
		int *mass1 = NULL;
		mass1 = (int*)malloc(sizeof(int) * 15);
		fillArray(mass, 15);
		printArray(mass, 15);
		ReversNumber(mass, mass1, 15);
		printArray(mass1, 15);
		free(mass);
		free(mass1);
	}
	break;
	case 3:
	{
		/*6.	Задан целочисленный массив.Вывести индексы тех элементов,
			значения которых больше, чем у стоящих справа от него.
			Определить количество таких чисел*/
		int *mass = NULL;
		int *index = NULL;
		index = (int*)calloc(1, sizeof(int));
		mass = (int*)malloc(sizeof(int) * 15);
		fillArray(mass, 15);
		printArray(mass, 15);
		int count = 0;
		for (int i = 0; i < 14; i++)
		{
			if (*(mass + i) > *(mass + i + 1))
			{
				*(index + count) = i;
				count++;
				index = (int*)realloc(index, sizeof(int)*(count + 1));
			}
		}
		for (int i = 0; i < count; i++)
		{
			printf("%d\t", *(index + i));
		}
		printf("\n");
		free(index);
		free(mass);

	}
	break;
	case 7:
	{
		//7.Задан целочисленный массив. Определить, образуют ли значения его элементов 
		//арифметическую прогрессию. Если «да» – вывести разность прогрессии, 
		//если «нет» – ответ «не образуют».
		int *mass = NULL, length = 10;
		mass = (int*)malloc(sizeof(int) * 10);
		fillArray(mass, length);
		printArray(mass, length);
		int *mass1 = NULL;
		mass1 = (int*)malloc(sizeof(int) * 10);
		for (short int i = 0; i < length; i++)
		{
			*(mass1 + i) = *(mass + i);
		}
		for (short int i = 0; i < length; i++)
			printf("%d\t", *(mass1 + i));
		printf("\n");
		ArifmProgres(mass1, length);
		free(mass);
		free(mass1);
	}
	break;
	case 8:
	{
		//8.Дан массив вещественных чисел. Определить элемент массива(значение и индекс), 
		//который наиболее близок к заданному вещественному числу R.
		int *mass = NULL, length = 10;
		mass = (int*)malloc(sizeof(int) * 10);
		fillArray(mass, length);
		printArray(mass, length);
		Neighbor(mass, length);
		free(mass);
	}
	break;
	case 10:
	{
		//10.Дан двухмерный массив 7×7. Найти сумму модулей отрицательных нечётных элементов.
		int *mass = NULL, length = 7, row = 7;
		mass = (int*)malloc(sizeof(int) * 49);
		fillMatrix(mass, length, row);
		printMatrix(mass, length, row);
		Pure(mass, length, row);
		SortOpredStolbca(mass, length, row);
		free(mass);
	}
	}
}
