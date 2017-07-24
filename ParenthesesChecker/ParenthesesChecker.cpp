#include "ParenthesesChecker.h"



ParenthesesChecker::ParenthesesChecker()
{
	parentheses['['] = ']';
	parentheses['('] = ')';
	parentheses['{'] = '}';
}


ParenthesesChecker::~ParenthesesChecker()
{
}

bool ParenthesesChecker::check(string expression)
{
	
	ReadByStack(expression);
	return AreParenthesesMatched();
}

void ParenthesesChecker::ReadByStack(std::string &expression)
{
	for (auto iter = expression.begin(); iter < expression.end(); ++iter)
	{
		if (IsRecorderEmpty())
		{
			RecordAChar(iter);
			continue;
		}
		else
		{
			if (IsStackTopMatched(iter))
				MatchedAParenthese();
			else
				RecordAChar(iter);
		}

	}
}

void ParenthesesChecker::MatchedAParenthese()
{
	this->recorder.pop();
}

bool ParenthesesChecker::IsStackTopMatched(std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter)
{
	return parentheses[this->recorder.top()] == *iter;
}

void ParenthesesChecker::RecordAChar(std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter)
{
	this->recorder.push(*iter);
}

bool ParenthesesChecker::AreParenthesesMatched()
{
	return this->recorder.empty();
}

bool ParenthesesChecker::IsRecorderEmpty()
{
	return this->recorder.empty();
}
