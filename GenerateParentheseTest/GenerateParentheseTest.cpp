#include "gmock/gmock.h"

#include "ParentheseGenerator.h"
#include <memory>

class ParentheseGeneratorTest : public ::testing::Test
{
public:
	ParentheseGeneratorTest()
	{
	}	

protected:
	ParentheseGenerator parenthese_generator;
};

TEST_F(ParentheseGeneratorTest, generate_one_pair)
{
	ASSERT_EQ(string("()"), parenthese_generator.generate(1).front());
}



TEST_F(ParentheseGeneratorTest, generate_two_pair)
{
	vector<string> pairs = parenthese_generator.generate(2);
	ASSERT_EQ(2, pairs.size());
	auto result = find(pairs.begin(), pairs.end(), "()()");
	ASSERT_NE(pairs.end(), result);
	result = find(pairs.begin(), pairs.end(), "(())");
	ASSERT_NE(pairs.end(), result);
	//ASSERT_TRUE(find(pairs.begin(), pairs.end(), string("()()")));
}

TEST_F(ParentheseGeneratorTest, generate_three_pair)
{
	vector<string> pairs = parenthese_generator.generate(3);
	ASSERT_EQ(5, pairs.size());
	auto result = find(pairs.begin(), pairs.end(), string("((()))"));
	ASSERT_NE(pairs.end(), result);
	result = find(pairs.begin(), pairs.end(), string("(()())"));
	ASSERT_NE(pairs.end(), result);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;

}
