#include"Evaluate.h"
int main(int argc, char** argv)
{
	float r;
	cout << "\t\t\t\t\t\t      QUESTION#2" << endl;
	cout << "\t\t\t\t-----------------------------------------------------" << endl;
	cout << "\t\t\t\t\t    EVALUATION OF POSTFIX EXPRESSION" << endl;
	cout << "\t\t\t\t-----------------------------------------------------" << endl;
	cout << endl << endl;
	if (argc == 1)
	{
		cout << "UTILTY:POSTFIX EXPRESSION" << endl;
	}
	else
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "Postfix Expression is:" << argv[1] << endl;
		cout << "-----------------------------------------------------" << endl << endl << endl;
		r = result(argv[1]);
		cout << "-----------------------------------------------------" << endl;
		cout << "Result is:" << r << endl;
		cout << "-----------------------------------------------------" << endl;
	}
	return 0;
}