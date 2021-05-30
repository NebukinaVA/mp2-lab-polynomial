#include <iostream>
#include "monomial.h"
#include "polynomial.h"
#include <string>


int main()
{
	std::string str = "xy+xz";
	std::cin >> str;
	Polynomial p(str);
	std::cout << p;
	return 0;
}