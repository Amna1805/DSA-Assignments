#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
//to store details of pateint
struct patient
{
	string p_name, f_name, disease;
	int age;
};
void queues_names(string *s, int n)
{
	int i;
	cout << "\t\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT" << endl;
	cout << "\t\t\t\t\t------------------------------" << endl;
	cout << "\t\t\t\t\t\tQUEUES IN HOSPITAL" << endl;
	cout << "\t\t\t\t\t\t------------------" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\t\t\t\t\t\t    (*)" << s[i] << endl;
	}
	cout << "\t\t\t\t\t------------------------------" << endl;
	cout << endl;
}
int main()
{
	int q_no, i; string choice;
	int c;
	patient p;
	char ch;
	cout << "\t\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT" << endl;
	cout << "\t\t\t\t\t------------------------------" << endl;
	cout << "How many queues you want to create?";
	cin >> q_no;
	queue <patient> *q;
    q = new queue<patient>[q_no];
	string *name;
	name = new string[q_no];
	cout << "\t\t\t\t\tEnter names of queues:"<<endl;
	cin.ignore();
	for (i = 0; i <q_no; i++)
	{
		cout << "Enter name of queue " << i+1<< ":";
		getline(cin,name[i]);
	}
    queue_op:
	system("cls");
	{
		queues_names( name, q_no);
		cout << "1-Queue(add/remove)\n2-Display Queues\n3-Exit." << endl;
		cout << "Enter choice:";
		cin >> c;
	}

	if (c == 1)
	{
	    
		system("cls");
		queues_names(name, q_no);
		cout << "\t\t\t\t\t\tQUEUES OPERATIONS" << endl;
		cout << "\t\t\t\t\t\t-----------------" << endl;
		int c1;
		cout << endl << endl;
		do
		
		{
			cout << "Please enter  queue name in which you want to add or remove person:";
			cin.get();
			getline(cin, choice);
			for (i = 0; i < q_no; i++)
			{
				if (choice == name[i])
				{
					system("cls");
					queues_names(name, q_no);
					cout << "\t\t\t\t\t\t   "<<name[i] << " QUEUE" << endl;
					cout << "\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t1-ADD PERSON\n\t\t\t\t\t\t2-REMOVE PERSON" << endl;
					cout << endl << endl;
					cout << "Enter your choice:";
					cin >> c1;
					if (c1 == 1)
					{
						
						do
						{
							system("cls");
							queues_names(name, q_no);
							cout<<  "\t\t\t\t\t   ADD PERSON IN "<< name[i] << " QUEUE" << endl ;
							cout << "\t\t\t\t\t------------------------------" << endl<<endl;
							cin.get();
							cout << "Enter Name:";
							getline(cin, p.p_name);
							cout << "Enter father name:";
							getline(cin, p.f_name);
							cout << "Enter age:";
							cin >> p.age;
							cin.get();
							cout << "Enter disease:";
							getline(cin, p.disease);
							q[i].push(p);
							cout << endl;
							cout << "Information added Successfully." << endl;
							cout << "Do you want to add more persons?:";
							cin >> ch;
							cout << endl;
						} while (ch == 'y' || ch == 'Y');
						goto queue_op;
					}
					else if (c1 == 2)
					{
						system("cls");
						queues_names(name, q_no);
						do
						{
							
							cout << "\t\t\t\t\t    REMOVE PERSON IN " << name[i] << " QUEUE" << endl << endl;
							cout << "\t\t\t\t\t------------------------------" << endl << endl;
							q[i].pop();
							cout << "Person removed Successfully." << endl;
							cout << "Do you want to remove more persons from queue?:";
							cin >> ch;
						} while (ch == 'y' || ch == 'Y');
						goto queue_op;
					}
					else
					{
						cout << "Invalid Input." << endl;
					}
					break;
				}
				
			}
			cout << endl;
			cout << "Queue with " << choice << " name does not exsist." << endl << endl;;
			cout << "Do you want enter again?:";
			cin >> ch;
			cout << endl;
		} while (ch == 'y' || ch == 'Y');
		goto queue_op;
	}
	else if (c == 2) {
		system("cls");
		queues_names(name, q_no);
		char c;
		cout << "\t\t\t\t\t  DISPLAYING ALL QUEUES DATA" << endl;
		cout << "\t\t\t\t\t------------------------------" << endl << endl;
		queue<patient>* temp;
		temp = new queue<patient>[q_no];
		for (i = 0; i < q_no; i++)
		{
			
				temp[i] = q[i];
				cout << "---------------------------------------------------" << endl;
				if (temp[i].empty())
				{
					cout << "Queue " << name[i] << " is Empty." << endl;
				}
				else
				{
					cout << name[i] << " Queue data:" << endl;
					cout << "--------------------------------------------------------------" << endl;
					cout << "Name\t\tFather Name\t\tAge\t\tDisease" << endl;
					while (!temp[i].empty())
					{
						p = temp[i].front();
						temp[i].pop();
						cout << p.p_name << "\t\t" << p.f_name << "\t\t" << p.age << "\t\t" << p.disease << endl;
					}
					cout << "--------------------------------------------------------------" << endl;
					cout << endl;
				}
				
			}
		cout << "---------------------------------------------------" << endl;
		cout << "Press any key to goto main menu:";
		cin >> c;
		delete[] temp;
		goto queue_op;
		}
	else
	{
		
		exit(0);
	}
	
	
}
