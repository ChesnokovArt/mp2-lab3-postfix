#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, throw_when_create_stack_with_negative_length)
{
	EXPECT_ANY_THROW(TStack<char>(-3));
}

TEST(TStack, throw_when_create_too_large_stack)
{
	EXPECT_ANY_THROW(TStack<int>(101));
}

TEST(TStack, can_push_and_pop_element)
{
	TStack<int> s(3);
	s.Push(11);
	EXPECT_EQ(11, s.Pop());

}

TEST(TStack, throw_when_push_in_full_stack)
{
	TStack<int> s(3);
	s.Push(1);
	s.Push(1);
	s.Push(1);
	EXPECT_ANY_THROW(s.Push(1));
}

TEST(TStack, throw_when_pop_from_empty_stack)
{
	TStack<int> s(3);
	EXPECT_ANY_THROW(s.Pop());
}