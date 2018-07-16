#include "prefixtree.h"

void tree_node::init()
{
	left = right = parent = nullptr;
	type_ = NONE;
	op_ = value_ = 0;
	name = "";
}

tree_node::tree_node( double x )
{
	init();
	type_ = NUMBER;
	value_ = x;
}

tree_node::tree_node( char c )
{
	init();
	if (c=='x')type_ = ALGEBRA;
	else
	{
		type_ = OPERATOR;
		op_ = c;
	}
}

tree_node::tree_node( string str )
{
	init();
	type_ = FUNCTION;
	name = str;
}

bool tree_node::calculate( double& ans, double x )
{
	if (type_ == NUMBER)
	{
		ans = value_;return true;
	}
	else if(type_==ALGEBRA)
	{
		ans = x; return true;
	}
	else if (type_ == OPERATOR)
	{
		double l, r;
		if (left->calculate( l, x )&&right->calculate( r, x ))
		{
			switch (op_)
			{
				case '+':
				{
					ans = l + r;return true;break;
				}
				case '-':
				{
					ans = l - r;return true;break;
				}
				case '*':
				{
					ans = l * r;return true;break;
				}
				case '/':
				{
					ans = l / r;return true;break;
				}
				case '^':
				{
					ans = pow(l, r);return true;break;
				}
				default:
				{
					ans = 0;return false;break;
				}
			}
		}

	}
}