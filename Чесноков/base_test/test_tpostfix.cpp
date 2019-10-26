#include "postfix.h"
#include "postfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p("a+b"));

}

TEST(TPostfix, parsing_is_correct)
{
	TPostfix p("(  a - B)/  (c+D)  ");
	string s("(A-B)/(C+D)");
	EXPECT_EQ(s, p.GetInfix());
}

TEST(TPostfix, convertion_is_correct)
{
	TPostfix p("(  a - B)/  (c+D)  ");
	string s("AB-CD+/");
	EXPECT_EQ(s, p.ToPostfix());
}

TEST(TPostfix, throw_for_invalid_input_1)
{
	EXPECT_ANY_THROW(TPostfix p("a-b)/(c+d)"));
}

TEST(TPostfix, throw_for_invalid_input_2)
{
	EXPECT_ANY_THROW(TPostfix p("a+,"));
}