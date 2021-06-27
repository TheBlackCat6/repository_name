#include <iostream>



namespace mylib
{

	float* Array(short size)
	{
		float* parr = new(std::nothrow) float[size];
		if (parr != nullptr)
		{
			for (size_t i = 0; i < size; i++)
			{
				parr[i] = (rand() % 198) - 99;
			}
		}
		return parr;
	}
	void print_arr(float* array, short size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}
	
	void printPosNeg(float* Array, short size)
	{
		int pos = 0;
		int neg = 0;
		
		for (size_t i = 0; i < size; i++)
		{
			if (Array[i] > 0)
			{
				pos++;
			}
			
			else if (Array[i] < 0)
			{
				neg++;
			}
		}
		std::cout << "Positive numbers: " << pos << std::endl;
		
		std::cout << "Negative numbers: " << neg << std::endl;
	}

#define swap_int(x, y) int temp = x; x=y; y = temp;

	void sort_arr(int* arr, short size)
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap_int(arr[j], arr[j + 1])
				}
			}
		}
	}
	void print_arr(int* arr, short size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}