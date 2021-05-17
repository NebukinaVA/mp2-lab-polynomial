#include <gtest.h>
#include "list.h"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}

TEST(List, can_copy_list)
{
	List<int> l1, l2(l1);

	EXPECT_TRUE(l1 == l2);
}

TEST(List, copied_list_has_its_own_memory)
{
	List<int> l1, l2(l1);

	l2.push_front(1);

	EXPECT_FALSE(l1 == l2);
}

TEST(List, can_push_front_element)
{
	List<int> l;

	ASSERT_NO_THROW(l.push_front(0));
}

TEST(List, can_check_if_empty)
{
	List<int> l;

	EXPECT_TRUE(l.empty());
}

TEST(List, can_check_if_not_empty)
{
	List<int> l;

	l.push_front(1);

	EXPECT_FALSE(l.empty());
}

TEST(List, can_pop_front_element)
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);

	ASSERT_NO_THROW(l.pop_front());
}

TEST(List, can_clear_list)
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.clear();

	EXPECT_TRUE(l.empty());
}

TEST(List, can_assign_lists)
{
	List<int> l1, l2;

	l1.push_front(1);
	l2.push_front(3);
	l1 = l2;

	EXPECT_TRUE(l1 == l2);
}

TEST(List, can_compare_equal_lists)
{
	List<int> l1, l2;

	l1.push_front(1);
	l2.push_front(1);

	EXPECT_TRUE(l1 == l2);
}

TEST(List, can_compare_unequal_lists)
{
	List<int> l1, l2;

	l1.push_front(1);
	l2.push_front(3);

	EXPECT_TRUE(l1 != l2);
}

TEST(List, can_compare_unequal_lists_1)
{
	List<int> l1, l2;

	l1.push_front(1);
	l2.push_front(3);
	l1.push_front(1);
	l2.push_front(3);
	l2.pop_front();

	EXPECT_TRUE(l1 != l2);
}

TEST(List, can_return_size)
{
	List<int> l;

	l.push_front(1);
	l.push_front(3);
	l.push_front(1);

	EXPECT_EQ(3, l.size());
}

TEST(List, can_append_node)
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	ASSERT_NO_THROW(l.append(4, l.head()));
}

TEST(List, can_remove_node)
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	ASSERT_NO_THROW(l.remove(l.head()));
}

TEST(List, can_push_back_element)
{
	List<int> l;

	ASSERT_NO_THROW(l.push_back(0));
}

TEST(List, can_pop_back_element)
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);

	ASSERT_NO_THROW(l.pop_front());
}

TEST(List, can_return_an_iterator_on_first_element)
{
	List<int> l;

	ASSERT_NO_THROW(l.begin());
}

TEST(List, can_return_an_iterator_on_last_element)
{
	List<int> l;

	ASSERT_NO_THROW(l.end());
}

//----------------------------


TEST(Iterator, can_create_iterator)
{
	ASSERT_NO_THROW(List<int>::Iterator it);
}

TEST(Iterator, can_create_copied_iterator)
{
	List<int>::Iterator it1, it2(it1);

	EXPECT_TRUE(it1 == it2);
}

TEST(Iterator, can_assign_iterators)
{
	List<int> l;
	List<int>::Iterator it1, it2;

	l.push_front(1);
	it1 = l.head();
	it2 = it1;

	EXPECT_TRUE(it1 == it2);
}

TEST(Iterator, can_compare_equal_iterators)
{
	List<int> l;
	List<int>::Iterator it1, it2;

	l.push_front(1);
	it1 = l.head();
	it2 = l.head();

	EXPECT_TRUE(it1 == it2);
}

TEST(Iterator, can_compare_not_equal_iterators)
{
	List<int> l;
	List<int>::Iterator it1(l.head()), it2;

	l.push_front(1);
	it2 = l.head();

	EXPECT_TRUE(it1 != it2);
}

TEST(Iterator, prefix_increment_is_correct_1)
{
	List<int> l;
	List<int>::Iterator it;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	it = l.head();
	++it;

	EXPECT_EQ(2, it->data);
}

TEST(Iterator, prefix_increment_is_correct_2)
{
	List<int> l;
	List<int>::Iterator it;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	it = l.head();

	EXPECT_EQ(2, (++it)->data);
}

TEST(Iterator, prefix_increment_throws_if_points_on_nullptr)
{
	List<int> l;
	List<int>::Iterator it(l.head());

	ASSERT_ANY_THROW(++it);
}

TEST(Iterator, postfix_increment_is_correct_1)
{
	List<int> l;
	List<int>::Iterator it;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	it = l.head();
	it++;

	EXPECT_EQ(2, it->data);
}

TEST(Iterator, postfix_increment_is_correct_2)
{
	List<int> l;
	List<int>::Iterator it;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	it = l.head();

	EXPECT_NE(2, (it++)->data);
}

TEST(Iterator, postfix_increment_throws_if_points_on_nullptr)
{
	List<int> l;
	List<int>::Iterator it(l.head());

	ASSERT_ANY_THROW(it++);
}
