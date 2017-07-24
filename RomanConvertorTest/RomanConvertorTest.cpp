#include "gmock/gmock.h"

#include "RomanConvertor.h"

class RomanConvertorTest : public ::testing::Test
{
protected:
	RomanConvertor roman_convertor;
};

TEST_F(RomanConvertorTest, test_input_1)
{
	ASSERT_EQ(string("I"), roman_convertor.convert(1));
	//ASSERT_STREQ(string("I"), roman_convertor.convert(1));
}

TEST_F(RomanConvertorTest, test_input_2)
{
	ASSERT_EQ(string("II"), roman_convertor.convert(2));
	//ASSERT_STREQ(string("II"), roman_convertor.convert(2));
}

TEST_F(RomanConvertorTest, test_input_3)
{
	ASSERT_EQ(string("III"), roman_convertor.convert(3));
}
TEST_F(RomanConvertorTest, test_input_5)
{
	ASSERT_EQ(string("V"), roman_convertor.convert(5));
	//ASSERT_STREQ(string("V"), roman_convertor.convert(5));
}

TEST_F(RomanConvertorTest, test_input_6)
{
	ASSERT_EQ(string("VI"), roman_convertor.convert(6));
	//ASSERT_STREQ(string("VI"), roman_convertor.convert(6));
}

TEST_F(RomanConvertorTest, test_input_13)
{
	ASSERT_EQ(string("XIII"), roman_convertor.convert(13));
}

TEST_F(RomanConvertorTest, test_input_4)
{
	ASSERT_EQ("IV", roman_convertor.convert(4));
}

TEST_F(RomanConvertorTest, test_input_1990)
{
	ASSERT_EQ("MCMXC", roman_convertor.convert(1990));
}

TEST_F(RomanConvertorTest, test_input_99)
{
	ASSERT_EQ("XCIX", roman_convertor.convert(99));
}
int main(int argc, char* argv[])
{
	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;

}