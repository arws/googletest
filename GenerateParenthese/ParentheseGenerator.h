#pragma once
#include <string>
#include <vector>
#include "ParenthesesChecker.h"
#include <memory>


using namespace std;

class ParentheseGenerator	
{
public:
	ParentheseGenerator();
	~ParentheseGenerator();
	void generate_paratheses(string exp, int left_left, int right_left, vector<string>* pair);
	vector<string> generate(int n);
private:
	void IsImbalancedInput(string exp);
};

