#pragma once
#include <string>
#include <stack>

using  std::string;

#define FuncNumber 3

const string func[] = { "ln","log","sqrt" };

class lexer
{
	public:
		lexer(string str);
		~lexer();
		enum type test_char();
		char get_operation();
		double get_double();
		double get_function();
		int priority(char c);
		void StringToTree(string str);
	private:
		std::stack<char> op;
		std::stack<double> val;
		int now;
		string S;
};