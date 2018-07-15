#pragma once
#include "prefixtree.h"
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
		bool strtotree();
		double calculate( double x );
		pnode root;
	private:
		int priority( char c );
		std::stack<char> op;
		std::stack<pnode> val;
		int now;
		string S;
};