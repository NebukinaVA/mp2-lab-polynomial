#include <iostream>
#include "monomial.h"
#include "polynomial.h"


int main()
{
	Monomial m1("x"), m2("xyz"), m; // = 1x3y1z6
	m = m1 * m2;
	double a = 555.0;
	std::cout << m << std::endl;
	Polynomial p1("xy+xz"), p2("x+z");
//	p1 = p1 * m1; 
//	p1 = p1 + m2;
//	p1 = p1 + p2;
//	p1 = p1 * p2; //x2y+x2z+xyz+xz2
//	p1 = p1 * a;
//	p1 = p1 - p2;
	std::cout << p1;
	return 0;
}