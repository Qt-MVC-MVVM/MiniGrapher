#pragma once
#include "prefixtree.h"
#include <string>
#include <stack>

using  std::string;

class lexer
{
	public:
        lexer();
		lexer(string str);
		~lexer();
        void setstring(string str);
		enum type test_char();
		char get_operation();
		double get_double();
		int get_function();
		bool strtotree();
		double calculate( double x );
		double integral( double a, double b );
		double differential( double x );
        string getString();
		pnode root;
	private:
		void drop(pnode node);
		int priority( char c );
		std::stack<char> op;
		std::stack<pnode> val;
		int now;
		string S;
};
