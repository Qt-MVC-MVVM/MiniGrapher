#pragma once
#include "prefixtree.h"
#include <string>
#include <stack>

using  std::string;

class lexer
{
	public:
		lexer(string str);
		~lexer();
		enum type test_char();
		char get_operation();
		double get_double();
		int get_function();
		bool strtotree();
		double calculate( double x );
		pnode root;
	private:
		void drop(pnode node);
		int priority( char c );
		std::stack<char> op;
		std::stack<pnode> val;
		int now;
		string S;
};