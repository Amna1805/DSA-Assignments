#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prec(char c)    //to check precedence of operator
{
	if (c == '+' || c == '-')
	{
		return 1;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '(')
	{
		return 0;
	}
}
bool is_operand(char c)
{
	return(c >= '0' && c <= '9');
}
string postfix_expression_function(string ch)
{
	stack<char> s;
	int i;
	string temp = "";
	for (i = 0; i < ch.length(); i++)
	{
		if (is_operand(ch[i]))
		{
			temp += ch[i];
		}
		else if (ch[i] == '(')
		{
			s.push(ch[i]);
		}
		else if (ch[i] == ')')
		{
			while (s.top() != '(')
			{
				temp += " ";
				temp += s.top();
				s.pop();


			}
			s.pop();
		}

		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/')
		{
			temp += " ";
			if (s.empty() || s.top() == '(')
			{
				s.push(ch[i]);
			}
			else if (prec(ch[i]) > prec(s.top()))
			{
				s.push(ch[i]);
			}
			else
			{

				while (!s.empty() && prec(ch[i]) <= prec(s.top()))
				{
			    	temp += s.top();
					s.pop();
					temp += " ";
				}
				s.push(ch[i]);
			}

		}
	}
	while (!s.empty())
	{
		temp += " ";
		temp += s.top();
		s.pop();
	}
	return temp;
}
