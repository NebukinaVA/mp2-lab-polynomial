#include <iostream>
#include "monomial.h"
#include "polynomial.h"


int main()
{
	Monomial m("x"); // = 1x3y1z6
	std::cout << m;
	Polynomial p("xy+xz");
//	p = p * m;
	std::cout << p;
	return 0;
}