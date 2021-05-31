// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()

{
	bool A = true;
	char B = 'T';
	short int C = 354;
	int D = 24;
	long long E = 3'000'456'789;
	float F = 3.14;
	double G = 12'345.8006;
	const int H = 33;

	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << D << std::endl;
	std::cout << E << std::endl;
	std::cout << F << std::endl;
	std::cout << G << std::endl;
	std::cout << H << std::endl;




enum Name4Buttons { empty, cross, zero };
char Symb4Buttons[] { ' ','X','O' };
std::cout << Symb4Buttons [empty] << std::endl;
std::cout << Symb4Buttons [cross] << std::endl;
std::cout << Symb4Buttons [zero] << std::endl;
return 0; }