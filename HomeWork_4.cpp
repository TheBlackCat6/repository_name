﻿// HomeWork_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
/*Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел
лежит в пределах от 10 до 20 (включительно),
если да – вывести строку "true", в противном случае – "false";*/
{
	int a = 0, b = 0;
	std::cout << "Enter a couple of numbers:";
	std::cin >> a, b;

	if (a + b >= 10 && a + b <= 20)
	{
		std::cout << "True";
	}

	else
	{
		std::cout << "False";
	}
	/*Написать программу, выводящую на экран строку “true”,
	если две целочисленные константы, объявленные в её начале 
	либо обе равны десяти сами по себе, либо их сумма равна десяти. Иначе "false".*/

	int c = 5, d = 5;
	
	if (c + d == 10 || (c==10) & (d==10))
	{
		std::cout << "True";
	}

	else
	{
		std::cout << "False";
	}
	/*Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50.
	Например: "Your numbers: 1 3 5 7 9 11 13 …". 
	Для решения используйте любой С++ цикл.*/
	int i;
	for (i = 1; i <= 50; i=i +2)
	{
		std::cout << i << " ";
	}
	return 0;
}


