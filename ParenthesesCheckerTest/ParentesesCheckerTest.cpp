#include "gmock\gmock.h"
#include "ParenthesesChecker.h"

using namespace std;

ParenthesesChecker parentheseschecker;

TEST(ParenthesesCheckerTest, test_check_one_balanced_bracket)
{
	std::string exp = "[]";
	ASSERT_TRUE(parentheseschecker.check(exp));
}

TEST(ParenthesesCheckerTest, test_check_two_balanced_bracket)
{
	std::string exp = "[]()";
	ASSERT_TRUE(parentheseschecker.check(exp));
}

TEST(ParenthesesCheckerTest, test_multiple_balanced_bracket)
{
	string exp = "[({})]";
	ASSERT_TRUE(parentheseschecker.check(exp));
}

TEST(ParenthesesCheckerTest, test_odd_length_input)
{
	string exp = "[](";
	ASSERT_FALSE(parentheseschecker.check(exp));
}

TEST(ParenthesesCheckerTest, test_even_length_not_balanced)
{
	string exp = "({)}";
	ASSERT_FALSE(parentheseschecker.check(exp));
}

TEST(ParenthesesCheckerTest, test_reversed_bracket)
{
	string exp = "{{)(}}";
	ASSERT_FALSE(parentheseschecker.check(exp));
}




int main(int argc, char* argv[])
{
	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;

}