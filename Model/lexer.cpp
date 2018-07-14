#include "lexer.h"
#include "prefixtree.h"

lexer::lexer(string str)
{
	now = 0;
	S = str;
}

lexer::~lexer()
{
}

enum type lexer::test_char()
{
	while(now<S.length())
	{
		if (S[now] == ' ' || S[now] == '\n')now++;
		if (S[now] <= '9'&&S[now] >= '0')return NUMBER;
		else
		{
			if (S[now] == 'x')return ALGEBRA;
			for (int i = 0;i < FuncNumber;i++)
				if (S.compare((now, func[i].length(), func[i])))return FUNCTION;
			return OPERATOR;
		}
	}
	return NONE;
}

char lexer::get_operation()
{
	return S[now++];
}

double lexer::get_double()
{
	double ans = 0;
	int pos = 0;
	bool point = false;
	while (now < S.length())
	{
		if (S[now] <= '9'&&S[now] >= '0')
		{
			ans = ans * 10 + now - '0';
			if (point)pos++;
		}
		else if (S[now] == '.')point = true;
		else break;
	}
	ans = ans / pow(10, pos);
	return ans;
}

double lexer::get_function()
{
	return 0.0;
}

int lexer::priority(char c)
{
	switch (c)
	{
		case '+':return AddSub;
		case '-':return AddSub;
		case '*':return MulDiv;
		case '/':return MulDiv;
		case '^':return Pow;
		case '(':return LeftBracket;
		case ')':return RightBrackets;
		default: return ERROR;
	}
}

