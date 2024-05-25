#include"postfix.h"
int main(int argc, char** argv)
{
	cout << "\t\t\t\t\t\t      QUESTION#3" << endl;
	cout << "\t\t\t\t-----------------------------------------------------" << endl;
	cout << "\t\t\t\tCONVERSION OF INFIX EXPRESSION TO POSTFIX EXPRESSION" << endl;
	cout << "\t\t\t\t-----------------------------------------------------" << endl;
	cout << endl << endl;
	if (argc == 1)
	{
		cout << "UTILTY:INFIX EXPRESSION" << endl;
	}
	else
	{
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Infix Expression is:" << argv[1] << endl;
		cout << "-----------------------------------------------------------------------" << endl << endl << endl;
		string res = postfix_expression_function(argv[1]);
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Postfix Expression is:" << res << endl;
		cout << "-----------------------------------------------------------------------" << endl;
	}
	return 0;
}