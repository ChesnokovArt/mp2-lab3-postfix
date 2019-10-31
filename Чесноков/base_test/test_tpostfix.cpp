#include "postfix.h"
#include "postfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p("a+b"));

}

TEST(TPostfix, parsing_is_correct_1)
{
	TPostfix p("(  a - B)/  (c+D)  ");
	string s("(A-B)/(C+D)");
	EXPECT_EQ(s, p.GetInfix());
}

TEST(TPostfix, parsing_is_correct_2)
{
	TPostfix p("a - B * c *D");
	string s("A-B*C*D");
	EXPECT_EQ(s, p.GetInfix());
}


TEST(TPostfix, convertion_is_correct_1)
{
	TPostfix p("(  a - B)/  (c+D)  ");
	string s("AB-CD+/");
	EXPECT_EQ(s, p.ToPostfix());
}

TEST(TPostfix, convertion_is_correct_2)
{
	TPostfix p("a - B * c *D");
	string s("ABC*D*-");
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
TEST(TPostfix, throw_for_invalid_input_3)
{
	EXPECT_ANY_THROW(TPostfix p("a (- 3)"));
}

TEST(TPostfix, throw_for_invalid_input_4)
{
	EXPECT_ANY_THROW(TPostfix p("a */ b"));
}

TEST(TPostfix, throw_for_invalid_input_5)
{
	EXPECT_ANY_THROW(TPostfix p("a + bc"));
}

TEST(TPostfix, throw_for_invalid_input_6)
{
	EXPECT_ANY_THROW(TPostfix p("a + b - ()"));
}
