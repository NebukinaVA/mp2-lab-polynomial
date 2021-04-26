#include <gtest.h>
#include "monomial.h"

TEST(Monomial, can_create_simple_monom)
{
	ASSERT_NO_THROW(Monomial m);
}

TEST(Monomial, can_create_monom_with_two_arguements)
{
	ASSERT_NO_THROW(Monomial m(123, 15));
}

TEST(Monomial, cant_create_monom_with_negative_degree)
{
	ASSERT_ANY_THROW(Monomial m(-111, 15));
}

TEST(Monomial, cant_create_monom_with_high_degree)
{
	ASSERT_ANY_THROW(Monomial m(4531, 15));
}

TEST(Monomial, can_create_monom_from_string)
{
	ASSERT_NO_THROW(Monomial m("2x4y5z6"));
}

TEST(Monomial, can_check_if_string_is_correct_1)
{
	EXPECT_NO_THROW(Monomial m("2x4y5z6"));
}

TEST(Monomial, can_check_if_string_is_correct_2)
{
	EXPECT_NO_THROW(Monomial m("xxy5z6"));
}

TEST(Monomial, can_check_if_string_is_correct_3)
{
	EXPECT_NO_THROW(Monomial m("0"));
}

TEST(Monomial, can_check_if_string_is_not_correct_1)
{
	EXPECT_ANY_THROW(Monomial m(""));
}

TEST(Monomial, can_check_if_string_is_not_correct_2)
{
	EXPECT_ANY_THROW(Monomial m("0.22.3xyz"));
}

TEST(Monomial, can_check_if_string_is_not_correct_3)
{
	EXPECT_ANY_THROW(Monomial m(".3xyz"));
}

TEST(Monomial, can_add_monoms_with_equal_degrees)
{
	Monomial m1(123, 10), m2(123, 5);

	ASSERT_NO_THROW(m1 + m2);
}

TEST(Monomial, cant_add_monoms_with_different_degrees)
{
	Monomial m1(123, 10), m2(124, 5);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(Monomial, can_multiply_monoms_with_acceptable_degrees)
{
	Monomial m1(123, 10), m2(642, 5);

	ASSERT_NO_THROW(m1 * m2);
}

TEST(Monomial, cant_multiply_monoms_with_high_degrees)
{
	Monomial m1(128, 10), m2(686, 5);

	ASSERT_ANY_THROW(m1 * m2);
}

TEST(Monomial, can_subtract_monoms_with_equal_degrees)
{
	Monomial m1(123, 10), m2(123, 5);

	ASSERT_NO_THROW(m1 - m2);
}

TEST(Monomial, cant_subtract_monoms_with_different_degrees)
{
	Monomial m1(123, 10), m2(124, 5);

	ASSERT_ANY_THROW(m1 - m2);
}

TEST(Monomial, can_compare_monoms_1)
{
	Monomial m1(523, 10), m2(124, 5);

	EXPECT_TRUE(m1 > m2);
}

TEST(Monomial, can_compare_monoms_2)
{
	Monomial m1(120, 10), m2(124, 5);

	EXPECT_TRUE(m1 < m2);
}