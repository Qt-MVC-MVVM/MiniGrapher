#include "prefixtree.h"

void tree_node::init()
{
	left = right = parent = nullptr;
	type_ = NONE;
	op_ = value_ = 0;
	func = 0;
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

tree_node::tree_node( int x )
{
	init();
	type_ = FUNCTION;
	func = x;
}



tree_node::~tree_node()
{
}

bool tree_node::calculate( double& ans, double x )
{
	ans = 0;
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
					return false;break;
				}
			}
		}
		else return false;
	}
	else if (type_==FUNCTION)
	{
		double l = 0;
		if (!left->calculate( l, x ))return false;
		switch (func)
		{
			case 0:
			{
				ans = log( l );
				break;
			}
			case 1:
			{
				ans = log10( l );
				break;
			}
			case 2:
			{
				ans = pow( l, 0.5 );
				break;
			}
			case 3:
			{
				ans = fabs( l );
				break;
			}
			case 4:
			{
				ans = sin( l );
				break;
			}
			case 5:
			{
				ans = cos( 1 );
				break;
			}
			case 6:
			{
				ans = tan( l );
				break;
			}
			default:
			{
				ans = 0;
				break;
			}
		}
		return true;
	}
}
