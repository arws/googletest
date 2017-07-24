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

private:
	unordered_map<char, char> parentheses;
	stack<char> recorder;

	void ReadByStack(std::string &expression);

	void MatchedAParenthese();

	bool IsStackTopMatched(std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter);

	void RecordAChar(std::_String_iterator<std::_String_val<std::_Simple_types<char>>> &iter);

	bool AreParenthesesMatched();

	bool IsRecorderEmpty();
};

