#include"Header.h"
int main(int argc,char**argv)
{
	bool check = false;
	stack<char> ss;
	stack<int>ll;
	ofstream f;
	int line_no=1;
	if (argc == 1)
	{
		cout << "UTILTY:FILE_NAME." << endl;
	}
	else
	{
		ifstream fin;
		string file;
		fin.open(argv[1], ios::in);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				getline(fin, file);
				check = balanced(file, line_no, ss);
				line_no++;

			}
		}
		line_no--;
		if (!ss.empty())
		{
			while (!ss.empty())
			{
				if (ss.top() == '(' || ss.top() == '[' || ss.top() == '{')
				{
					cout << ss.top() << " has no closing bracket in " << line_no << " number." << endl;
				}
				else
				{
					cout << ss.top() << " has no opening bracket in " << line_no << " number." << endl;
				}

				ss.pop();
			}
			cout << "--------------------------------------" << endl;
			cout << "File is not balanced." << endl;
			cout << "--------------------------------------" << endl;
		}

		else
		{
			cout << "--------------------------------------" << endl;
			cout << "File is balanced." << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	
	return 0;
}