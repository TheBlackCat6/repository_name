// HomeWork_5.cpp : Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

/*Написать функцию которая выводит массив double чисел на экран. 
Параметры функции это сам массив и его размер. 
Вызвать эту функцию из main.*/

bool somearray(double arr1[], const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr1[i] << " ";
	}
	return true;
}

/*Задать целочисленный массив, состоящий из элементов 0 и 1.
Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, 
заменяющую в принятом массиве 0 на 1, 1 на 0. 
Выводить на экран массив до изменений и после.*/

void somearray(int *parr2, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << parr2[i] << " ";
	}
	cout << endl;
}

void changeling(int arr2[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr2[i] = (arr2[i] == 1) ? 0 : 1;
	}

}

/*Задать пустой целочисленный массив размером 8. 
Написать функцию, которая с помощью цикла заполнит его значениями
1 4 7 10 13 16 19 22. Вывести массив на экран.*/

bool fib(int arr3[], size_t fibsize)
{
	int num = 1;
	const int step = 3;
	for (size_t i = 0; i < fibsize; i++)
	{
		arr3[i] = num;
		num += step;
	}
	return true;
}

int main()
{
	//1====================================================
	const int arrsize = 7;
	double arr1[arrsize] = { 15.5, 20.7, 40.04, 99.99, 35.43, 7.654, 123.321 };
	if (somearray(arr1, arrsize))
	{
		cout << "Array was successfuly printed" << endl;
	}

	//2====================================================
	const size_t size = 10;
	int arr2[size] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

	somearray(arr2, size);
	changeling(arr2, size);
	somearray(arr2, size);

	//3====================================================
	const size_t fibsize = 8;
	int arr3[fibsize];
	fib(arr3, fibsize);
	somearray(arr3, fibsize);
    return 0;
}

