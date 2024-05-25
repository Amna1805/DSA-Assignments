#include<iostream>
#include<string>
#include<fstream>
#include<stack>
using namespace std;
bool balanced(string s, int l, stack<char>& s1)
{
	bool c = true;
	int size;
	size = s.length();
	int i;
	for (i = 0; i < size; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{

			s1.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (s1.empty())
			{
				cout << s[i] << "has no opening bracket " << l << " number." << endl;
			}
			else
			{
				if (s[i] == ']')
				{
					if (s1.top() == '[')
					{
						s1.pop();
					}
					else
					{
						cout << s[i] << " has no opening bracket " << l << " number." << endl;
						c = false;
					}
				}
				else if (s[i] == ')')
				{
					if (s1.top() == '(')
					{
						s1.pop();
						c = true;
					}
					else
					{
						cout << s[i] << " has no opening bracket " << l << " number." << endl;
						c = false;
					}


				}
				else if (s[i] == '}')
				{
					if (s1.top() == '{')
					{
						c = true;
						s1.pop();
					}
					else
					{
						cout << s[i] << " has no opening bracket " << l << " number." << endl;
						c = false;
					}

				}

			}
		}


	}
	if (!s1.empty())
	{
		while (s1.top() != '{')
		{
			if (s1.top() == '(' || s1.top() == '[')
			{
				cout << s1.top() << " has no closing bracket in " << l << " number." << endl;
			}
			else
			{
				cout << s1.top() << " has no opening bracket in " << l << " number." << endl;
			}
			s1.pop();
			if (s1.empty())
			{
				break;
			}
			c = false;
		}
	}
	return c;
}