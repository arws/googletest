#include "ParentheseGenerator.h"
#include <vector>

class not_balance_bracket_error : public exception
{
public:
	not_balance_bracket_error(string& msg)
	{
		
	}
};

ParentheseGenerator::ParentheseGenerator()
{
}

ParentheseGenerator::~ParentheseGenerator()
{
}

void ParentheseGenerator::generate_paratheses(string exp, int left_left, int right_left, vector<string>* pair)
{
	if(left_left==0)
	{
		pair->push_back(exp.append(string(right_left, ')')));
		return;
	}
	if(left_left==right_left)
	{
		string next_exp = exp.append("(");
		generate_paratheses(next_exp, left_left - 1, right_left, pair);
	}
	if(left_left < right_left)
	{
		string next_exp_l = string(exp).append("(");
		generate_paratheses(next_exp_l, left_left - 1, right_left, pair);
		string next_exp_r = string(exp).append(")");
		generate_paratheses(next_exp_r, left_left, right_left - 1, pair);
	}
}


vector<string> ParentheseGenerator::generate(int n)
{
	vector<string> pairs;

	int num_of_paires = n;
	int left_bracket = num_of_paires;
	int right_bracket = num_of_paires;

	string well_formed_parenthesss = "";
	generate_paratheses(well_formed_parenthesss, left_bracket, right_bracket, &pairs);

	return pairs;
}
