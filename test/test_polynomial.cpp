#include <gtest.h>
#include "monomial.h"
#include "polynomial.h"

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

TEST(Polynomial, can_multiply_polynom_by_monom)
{
	Monomial m("80x2y5");
	Polynomial p("xyz+yz2-10y");

	ASSERT_NO_THROW(p * m);
}

TEST(Polynomial, cant_multiply_with_high_degrees)
{
	Monomial m("80x2y5");
	Polynomial p("xyz+yz2-10y5");

	ASSERT_ANY_THROW(p * m);
}