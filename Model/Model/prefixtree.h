#pragma once
#include <iostream>
#include <cmath>
#include <string>

using std::string;

typedef class tree_node* pnode;

enum type
{NUMBER,ALGEBRA,OPERATOR,FUNCTION,NONE};

enum Priority
{ERROR,RightBrackets,AddSub,MulDiv,Pow,LeftBracket};

class tree_node
{
	public:
		void init();
		tree_node(double x);
		tree_node(char c);
		tree_node( string str );
		~tree_node();
		bool calculate( double& ans, double x );
		pnode left, right, parent;
	private:
		string name;
		enum type type_;
		char op_;
		double value_;
};

class prefix_tree
{
	public:
		prefix_tree();
		~prefix_tree();
	private:
		
};