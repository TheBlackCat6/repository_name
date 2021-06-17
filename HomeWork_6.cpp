#include <iostream>
#include <fstream>
#include <string>

/*Выделить в памяти динамический одномерный массив типа int. 
Размер массива запросить у пользователя. Инициализировать его числами степенями двойки:
1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =)
Разбить программу на функции.*/

using namespace std;

void square(int *parr, int size)
{
	int num = 1;
	for (int i = 0; i < size; i++)
	{
		parr[0] = num;
		num *= 2;
		cout << parr[0] << " ";
	}
}


/*Динамически выделить матрицу 4х4 типа int.
Инициализировать ее псевдослучайными числами через функцию rand.
Вывести на экран.Разбейте вашу программу на функции которые вызываются из main.*/

void printarray(int** ptrArr, size_t size1, size_t size2)
{
	for (size_t m = 0; m < size1; m++)
	{

		for (size_t n = 0; n < size2; n++)
		{
			cout << ptrArr[m][n] << " ";
		}
		cout << endl;
	}
}

void array_4x4()
{
	int** ptrArr;
	const size_t arrsize = 4;
	ptrArr = new int* [arrsize];
	for (size_t i = 0; i < arrsize; i++)
	{
		ptrArr[i] = new int[arrsize];
	}

	for (size_t m = 0; m < arrsize; m++)
	{
		for (size_t n = 0; n < arrsize; n++)
		{
			ptrArr[m][n] = rand() % 99;
		}
	}

	printarray(ptrArr, arrsize, arrsize);

	for (size_t i = 0; i < arrsize; i++)
	{
		delete[] ptrArr[i];
	}
	delete[] ptrArr;
	ptrArr = nullptr;
}

/*Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt),
примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
Имена файлов запросить у пользователя.*/

void writetofile(ofstream& out, const string& fn, const string& text)
{
	out.open(fn);
	if (out.is_open())
	{
		out << text;
		out.close();
	}
}
void exercise_3()
{
	cout << " Enter a file name 1:  ";
	string fn1, fn2;
	cin >> fn1;
	cout << " Enter a file name 2:  ";
	cin >> fn2;

	ofstream fout1;
	const string text1 = "Полетели коптеры, Полетели сизые По полю, по полюшку, Ой, да по небу сызнова. Ой, железная ты птица, Не понять тебе меня -Всё летает над землицей Коптер - птица без гнезда. ";
	writetofile(fout1, fn1, text1);

	ofstream fout2;
	const string text2 = "На земле сидел андроид, Опустивший голову. От чего тоскует робот ? Да от апгрейда нового. Ой, да ты кака система! Как с тобой управиться ? О тебе ни чё не знаем, Только нам всё нравится. ";
	writetofile(fout2, fn2, text2);
}

int main()
{
	int * parr;
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	if (size > 0)
	{
		parr = new (std::nothrow) int[size];
		if (parr != nullptr)
		{
			square(parr,size);
			delete[] parr;
			parr = nullptr;
		}
		else
		{
			cout << "Error! Try again later!=)";
		}
		cout << endl;
	}
	
	int** ptrArr;
	const size_t arrsize = 4;
	array_4x4();
	exercise_3();
	return 0;
}