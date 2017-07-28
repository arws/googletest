#include "RomanConvertor.h"
#include <string.h>


void RomanConvertor::init_special_num()
{
	special_num.push(1);
	special_num.push(10);
	special_num.push(100);
	special_num.push(1000);
}

void RomanConvertor::init_digit_roman_convert_map()
{
	digit_roman_convert_map[1] = 'I';
	digit_roman_convert_map[5] = 'V';
	digit_roman_convert_map[10] = 'X';
	digit_roman_convert_map[50] = 'L';
	digit_roman_convert_map[100] = 'C';
	digit_roman_convert_map[500] = 'D';
	digit_roman_convert_map[1000] = 'M';
}

RomanConvertor::RomanConvertor()
{
	init_digit_roman_convert_map();

	init_special_num();
}


RomanConvertor::~RomanConvertor()
{
}

string RomanConvertor::GetRomanAlphabet(int integer, int count)
{
	if(count==4)
	{
		return string(1, digit_roman_convert_map[integer]) + string(1, digit_roman_convert_map[integer * 5]);
	}
	if(count==9)
	{
		return string(1, digit_roman_convert_map[integer]) + string(1, digit_roman_convert_map[integer * 10]);
	}
	if(count > 5)
	{
		return string(1, digit_roman_convert_map[integer * 5]) + string(count % 5, digit_roman_convert_map[integer]);
	}
	if(count == 5)
	{
		return string(1, digit_roman_convert_map[integer * 5]);
	}

	return string(count, digit_roman_convert_map[integer]);
}

string RomanConvertor::convert(int i)
{
	string RomanString("");
	while(!special_num.empty())
	{
		int k = special_num.top();
		RomanString += GetRomanAlphabet(k, i / k);
		i %= k;
		special_num.pop();
	}
	return RomanString;
}
