#pragma once
#include <iostream>
#include <cmath>
#include <string>

using std::string;

typedef class tree_node* pnode;

#define FuncNumber 7
const string func[] = {"ln","lg","sqrt","abs","sin","cos","tan"};

enum type
{NUMBER,ALGEBRA,OPERATOR,FUNCTION,NONE,WRONGINPUT};

enum Priority
{ERROR,RightBrackets,AddSub,MulDiv,Pow,LeftBracket};

class tree_node
{
	public:
		void init();
		tree_node(double x);
		tree_node(char c);
		tree_node( int x );
		~tree_node();
		bool calculate( double& ans, double x );
		pnode left, right, parent;
		enum type type_;
	private:
		char op_;
		double value_;
		int func;
};