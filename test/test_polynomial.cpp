#include <gtest.h>
#include "monomial.h"
#include "polynomial.h"

TEST(Polynomial, can_check_if_string_is_correct_2111111111111)
{
	EXPECT_NO_THROW(Polynomial p("-x-y"));
}

TEST(Polynomial, can_create_polynom_from_string)
{
	EXPECT_NO_THROW(Polynomial p("x+y"));
}

TEST(Polynomial, can_check_if_string_is_correct_1)
{
	EXPECT_NO_THROW(Polynomial p("2x4y5z6+5xy"));
}

TEST(Polynomial, can_check_if_string_is_correct_2)
{
	EXPECT_NO_THROW(Polynomial p("x+y+z+y+z+z+x"));
}

TEST(Polynomial, can_check_if_string_is_not_correct_1)
{
	EXPECT_ANY_THROW(Polynomial p(""));
}

TEST(Polynomial, can_check_if_string_is_not_correct_2)
{
	EXPECT_ANY_THROW(Polynomial p("xyz-5x2y6+"));
}

TEST(Polynomial, can_check_if_string_is_not_correct_3)
{
	EXPECT_ANY_THROW(Polynomial p("xyz-+-5x2y6+"));
}

TEST(Polynomial, can_check_if_polynomials_are_equal)
{
	Polynomial p1("x+y"), p2("x+y");
	EXPECT_TRUE(p1 == p2);
}

TEST(Polynomial, can_multiply_polynom_by_monom)
{
	Monomial m("80x2y5");
	Polynomial p("xyz+yz2-10y");

	ASSERT_NO_THROW(p * m);
}

TEST(Polynomial, can_multiply_polynom_by_monom_correctly)
{
	Monomial m("80xy");
	Polynomial p1("x+y"), p2("80x2y+80xy2");
	p1 = p1 * m;

	EXPECT_TRUE(p1 == p2);
}

TEST(Polynomial, cant_multiply_with_high_degrees)
{
	Monomial m("80x2y5");
	Polynomial p("xyz+yz2-10y5");

	ASSERT_ANY_THROW(p * m);
}

TEST(Polynomial, can_add_monom_to_polynom)
{
	Monomial m("80x2y5");
	Polynomial p("xyz+yz2-10y5");

	ASSERT_NO_THROW(p + m);
}

TEST(Polynomial, can_add_monom_to_polynom_correctly)
{
	Monomial m("80xy");
	Polynomial p1("x+y"), p2("80xy+x+y");
	p1 = p1 + m;

	EXPECT_TRUE(p1 == p2);
}

TEST(Polynomial, can_add_polynom_to_polynom)
{
	Polynomial p1("xyz+yz2-10y5"), p2("x+y");

	ASSERT_NO_THROW(p1 + p2);
}

TEST(Polynomial, can_add_polynom_to_polynom_correctly)
{
	Polynomial p1("x+y"), p2("xy+xz"), p3("xy+xz+x+y");
	p1 = p1 + p2;

	EXPECT_TRUE(p1 == p3);
}

TEST(Polynomial, can_multiply_polynom_by_polynom)
{
	Polynomial p1("xyz+yz2-10y5"), p2("x+y");

	ASSERT_NO_THROW(p1 * p2);
}

TEST(Polynomial, can_multiply_polynom_by_polynom_correctly)
{
	Polynomial p1("x+y"), p2("xyz+y");
	Polynomial p3("x2yz+xy2z+xy+y2");
	p1 = p1 * p2;

	EXPECT_TRUE(p1 == p3);
}

TEST(Polynomial, can_multiply_polynom_by_a_constant)
{
	Polynomial p("xyz+yz2-10y5");

	ASSERT_NO_THROW(p * 5);
}

TEST(Polynomial, can_multiply_polynom_by_a_constant_correctly)
{
	Polynomial p1("x+y"), p2("124.3x+124.3y");
	double a = 124.3;
	p1 = p1 * a;

	EXPECT_TRUE(p1 == p2);
}

TEST(Polynomial, can_subtract_polynoms_correctly)
{
	Polynomial p1("x+y"), p2("xy+xz"), p3("-xy-xz+x+y");
	p1 = p1 - p2;

	EXPECT_TRUE(p1 == p3);
}