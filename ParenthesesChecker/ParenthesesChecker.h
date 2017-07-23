#pragma once
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
class ParenthesesChecker
{
public:
	ParenthesesChecker();
	~ParenthesesChecker();

	bool check(string expression);
	void ReadByStack(std::string &expression, std::stack<char> &recorder);
	void MatchedAParenthese(std::stack<char> & recorder);
	bool IsStackTopMatched(std::stack<char> & recorder, std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter);
	void RecordAChar(std::stack<char> & recorder, std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter);
	bool AreParenthesesMatched(std::stack<char> &recorder);
	bool IsRecorderEmpty(std::stack<char> &recorder);
private:
	unordered_map<char, char> parentheses;
};

