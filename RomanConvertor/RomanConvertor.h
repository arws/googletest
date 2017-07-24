#pragma once
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;
class RomanConvertor
{
public:
	void init_special_num();
	void init_digit_roman_convert_map();
	RomanConvertor();
	~RomanConvertor();
	string convert(int i);
private:
	unordered_map<int, char> digit_roman_convert_map;
	stack<int> special_num;
	string GetRomanAlphabet(int integer, int count);

};

