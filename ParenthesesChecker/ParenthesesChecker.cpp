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
	stack<char> recorder;
	ReadByStack(expression, recorder);
	return AreParenthesesMatched(recorder);
}

void ParenthesesChecker::ReadByStack(std::string &expression, std::stack<char> &recorder)
{
	for (auto iter = expression.begin(); iter < expression.end(); iter++)
	{
		if (IsRecorderEmpty(recorder))
		{
			RecordAChar(recorder, iter);
			continue;
		}
		else
		{
			if (IsStackTopMatched(recorder, iter))
				MatchedAParenthese(recorder);
			else
				RecordAChar(recorder, iter);
		}

	}
}

void ParenthesesChecker::MatchedAParenthese(std::stack<char> & recorder)
{
	recorder.pop();
}

bool ParenthesesChecker::IsStackTopMatched(std::stack<char> & recorder, std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter)
{
	return parentheses[recorder.top()] == *iter;
}

void ParenthesesChecker::RecordAChar(std::stack<char> & recorder, std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter)
{
	recorder.push(*iter);
}

bool ParenthesesChecker::AreParenthesesMatched(std::stack<char> &recorder)
{
	return recorder.empty();
}

bool ParenthesesChecker::IsRecorderEmpty(std::stack<char> &recorder)
{
	return recorder.empty();
}
