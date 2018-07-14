#include "prefixtree.h"

tree_node::tree_node()
{
	left = right = nullptr;
	type_ = NONE;
	op_ = value_ = 0;
}

bool tree_node::calculate(double& ans)
{
	if (type_ == NUMBER)
	{
		ans = value_;return true;
	}
	else if (type_ == OPERATOR)
	{
		double l, r;
		if (left->calculate(l) && right->calculate(r))
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