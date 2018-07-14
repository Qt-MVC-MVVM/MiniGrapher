#pragma once
#include <iostream>
#include <cmath>

typedef class tree_node* pnode;

enum type
{NUMBER,ALGEBRA,OPERATOR,FUNCTION,NONE};

enum Priority
{ERROR,RightBrackets,AddSub,MulDiv,Pow,LeftBracket};

class tree_node
{
	public:
		tree_node();
		tree_node(double x);
		tree_node(char c);
		~tree_node();
		bool calculate(double& ans);
		pnode left, right;
	private:
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