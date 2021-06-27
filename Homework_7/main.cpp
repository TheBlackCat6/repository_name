#include <iostream>
#include <fstream>
#include "Mylib.h"

/*Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) 
в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, 
вывести на экран «true» или «false».*/

#define in_range(x,y) ((x >= 0 && x < y) ? "True" : "False")

	inline void task_2()
	{
		int num;
		std::cout << "Enter a number: " << std::endl;
		std::cin >> num;
		std::cout << in_range(num, 10) << std::endl;
		std::cout << std::endl;
	}

#define arr_size 10

	/*Задайте массив типа int.Пусть его размер задается через директиву препроцессора #define.
	Инициализируйте его через ввод с клавиатуры.Напишите для него свою функцию сортировки(например Пузырьком).
	Реализуйте перестановку элементов как макрокоманду SwapINT(a, b).Вызывайте ее из цикла сортировки.*/

inline void task_3()
{
	int* arr = new (std::nothrow) int[arr_size];

	if (arr != nullptr)
	{
		std::cout << "Enter " << arr_size << " numbers: " << std::endl;
		for (size_t i = 0; i < arr_size; i++)
		{
			std::cin >> arr[i];
		}

		mylib::sort_arr(arr, arr_size);
		mylib::print_arr(arr, arr_size);

		delete[] arr;
	}

}

/*Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
Вызывайте эти 3-и функции из main для работы с массивом.*/

	int main()
	{
		const short size = 10;
		float* arr = mylib::Array(size);

		if (arr != nullptr)
		{
			mylib::print_arr(arr, size);
			mylib::printPosNeg(arr, size);
			delete[] arr;
		}
		std::cout << std::endl;
		task_2();
		task_3();
		return 0;
	}
