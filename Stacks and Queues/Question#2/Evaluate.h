#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool is_operand(char c)            //to check whether character is operand or not.
{
	return(c >= '0' && c <= '9');
}
float result(string res)
{
	float op1, op2;
	int i;
	stack<float> ss;
	char ch;
	int num;
	string temp_s = "";    //to deal with spaces
	for (i = 0; i < res.length(); i++)
	{

		if (is_operand(res[i]))
		{
			temp_s += res[i];    //when digit then store in it

		}
		else if (res[i] == ' ')
		{
			if (temp_s == " ")    //when space then convert it into float type and push into stack.
			{
				continue;
			}
			num = stoi(temp_s);
			ss.push(num);
			temp_s = " ";       //Again making it empty to store new operand.
		}
		else
		{

			op2 = static_cast<float>(ss.top());
			ss.pop();
			op1 = (float)ss.top();
			ss.pop();
			//op1 and op2 contains top values of stack
			switch (res[i])
			{
			case '+':ss.push(op1 + op2);
				break;
			case '-':ss.push(op1 - op2);
				break;
			case '*':ss.push(op1 * op2);
				break;
			case '/':ss.push(op1 / op2);
				break;
			}
		}

	}
	return ss.top();
}
