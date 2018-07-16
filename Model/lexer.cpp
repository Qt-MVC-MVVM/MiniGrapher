#include "lexer.h"
#include "prefixtree.h"

lexer::lexer(string str)
{
	now = 0;
	S = str;
}

lexer::~lexer()
{
	drop( root );
}

enum type lexer::test_char()
{
	while(now<S.length())
	{
		if (S[now] == ' ' || S[now] == '\n')now++;
		if (S[now] <= '9'&&S[now] >= '0')return NUMBER;
		else
		{
			if (S[now] == 'x')return ALGEBRA;
			for (int i = 0;i < FuncNumber;i++)
				if (!S.compare(now, func[i].length(), func[i]))return FUNCTION;
			if (S[now]=='+'||S[now]=='-'||S[now]=='*'||S[now]=='/'||S[now]=='^'||S[now]=='('||S[now]==')')
				return OPERATOR;
			return WRONGINPUT;
		}
	}
	return NONE;
}

char lexer::get_operation()
{
	return S[now++];
}

double lexer::get_double()
{
	double ans = 0;
	int pos = 0;
	bool point = false;
	while (now < S.length())
	{
		if (S[now] <= '9'&&S[now] >= '0')
		{
			ans = ans * 10 + S[now] - '0';
			if (point)pos++;
		}
		else if (S[now] == '.')point = true;
		else break;
		now++;
	}
	ans = ans / pow(10, pos);
	return ans;
}

int lexer::get_function()
{
	for (int i = 0; i<FuncNumber; i++)
		if (!S.compare( now, func[i].length(), func[i] ))
		{
			now += func[i].length();
			return i;
		}
	return 0;
}

bool lexer::strtotree()
{
	root = nullptr;
	enum type last = NONE;
	while (now<S.length())
	{
		if (test_char()==OPERATOR)
		{
			if (op.empty()&&val.empty()&&S[now]=='-')
			{
				val.push( new tree_node( 0.0 ) );
				op.push( S[now++] );
			}
			else if (op.empty())op.push( S[now++] );
			else
			{
				if (S[now]==')')
				{
					while (op.top()!='(')
					{
						pnode temp = new tree_node( op.top() );
						temp->right = val.top(); val.pop();
						temp->left = val.top(); val.pop();
						temp->left->parent = temp->right->parent = temp;
						op.pop();
						val.push( temp );
					}
					pnode temp = val.top();
					val.pop();
					if (val.size()&&val.top()->type_==FUNCTION&&val.top()->left==nullptr)
					{
						pnode t = val.top();
						val.pop();
						t->left = temp;
						temp->parent = t;
						temp = t;
					}
					val.push( temp );
					op.pop();
					now++;
				}
				else if (priority( op.top() )>=priority( S[now] )&&op.top()!='(')
				{
					while (!op.empty()&&priority( op.top() )>=priority( S[now] )&&op.top()!='(')
					{
						pnode temp = new tree_node( op.top() );
						temp->right = val.top(); val.pop();
						temp->left = val.top(); val.pop();
						temp->left->parent = temp->right->parent = temp;
						op.pop();
						val.push( temp );
					}
					op.push( S[now++] );
				}
				else op.push( S[now++] );
			}
			last = OPERATOR;
		}
		else if (test_char()==NUMBER)
		{
			if (last==NUMBER||last==ALGEBRA)return false;
			val.push( new tree_node( get_double() ) );
		}
		else if (test_char()==ALGEBRA)
		{
			if (last==NUMBER||last==ALGEBRA)return false;
			val.push( new tree_node( 'x' ) );
			now++;
		}
		else if (test_char()==FUNCTION)
		{
			if (last==NUMBER||last==ALGEBRA)return false;
			val.push( new tree_node( get_function() ) );
		}
		else return false;
	}
	while (!op.empty())
	{
		pnode temp = new tree_node( op.top() );
		temp->right = val.top(); val.pop();
		temp->left = val.top(); val.pop();
		temp->left->parent = temp->right->parent = temp;
		op.pop();
		val.push( temp );
	}
	if (!val.empty())root = val.top();
	else root = nullptr;
	return true;
}

double lexer::calculate( double x )
{
	double ans = 0;
	if (!root)return 0.0;
	else if(root->calculate( ans, x ))return ans;
	return 0.0;
}

void lexer::drop( pnode node )
{
	if (node==nullptr)return;
	drop( node->left );
	drop( node->right );
	delete node;
}

int lexer::priority( char c )
{
	switch (c)
	{
		case '+':return AddSub;
		case '-':return AddSub;
		case '*':return MulDiv;
		case '/':return MulDiv;
		case '^':return Pow;
		case '(':return LeftBracket;
		case ')':return RightBrackets;
		default: return ERROR;
	}
}




