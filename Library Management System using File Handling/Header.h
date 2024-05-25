///////////////////////////////////////MAIN MENU////////////////////////////////////////////////////////////////////
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<stdlib.h>
#include<cctype>
using namespace std;
char ch;
int no_of_bytes;
int no_of_records;
int choice;
void Display_Menu();
void Search_books();
//Structure to store information of book
struct Library
{

	char Book_Title[50];
	char Book_Author[50];
	int Book_ID;
	void display()
	{
		cout << setw(5)<<Book_ID <<setw(30)<< Book_Title << setw(30)<< Book_Author << endl;
	}
};
//Searching book by its author
void Search_by_author()
{
	ifstream fin;
	Library data;
	bool checker;
	char author[50];
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK ID:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_Title you want to search:";
		cin.ignore();
		cin.getline(author, 50);
		checker = false;
		cout << endl;
		fin.open("records.bin", ios::binary | ios::in);
		while (fin.read((char*)&data, sizeof(data)))    //reading  record one by one untill no record found
		{
			if (strcmp(author, data.Book_Author) == 0)
			{
				cout << "Record Found." << endl;
				cout << "--------------" << endl << endl;
				cout << "----------------------------------------------------------------------" << endl;
				cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
				cout << "----------------------------------------------------------------------" << endl;
				data.display();
				cout << endl;
				checker = true; // to check whether record found or not.
			}

		}
		fin.close();
		if (!checker)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl; //If user want to search more books
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	fin.close();
	Search_books();
}
//Searching book by its title
void Search_by_title()
{
	ifstream fin;
	Library data;
	bool checker;
	char name[50];
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK ID:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_Title you want to search:";
		cin.ignore();
		cin.getline(name, 50);
		checker = false;
		cout << endl;
		fin.open("records.bin", ios::binary | ios::in);
		while (fin.read((char*)&data, sizeof(data)))
		{
			if (strcmp(name, data.Book_Title) == 0)
			{
				cout << "Record Found." << endl;
				cout << "--------------" << endl << endl;
				cout << "----------------------------------------------------------------------" << endl;
				cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
				cout << "----------------------------------------------------------------------" << endl;
				data.display(); //in structure to display its records
				cout << endl;
				checker = true;
			}

		}
		fin.close();
		if (!checker)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	}while(ch == 'y' || ch == 'Y');
	fin.close();
	Search_books();
}
//Searching book  by its ID
void Search_by_ID()
{
	ifstream fin;
	Library data;
	bool checker;
	int id;
	
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK ID:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_ID you want to search:";
		cin >> id;
		checker = false;
		cout << endl;
		fin.open("records.bin", ios::binary | ios::in);

		while (fin.read((char*)&data, sizeof(data)))
		{

			if (data.Book_ID == id)
			{
				cout << "Record Found." << endl;
				cout << "--------------" << endl << endl;
				cout << "----------------------------------------------------------------------" << endl;
				cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
				cout << "----------------------------------------------------------------------" << endl;
				data.display();
				cout << endl;
				checker = true;
			}
		}
		fin.close();
		if (!checker)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	fin.close();
	Search_books();
}
//Searching record by record no
void Search_by_record()
{
	ifstream fin;
	Library l;
	fin.open("records.bin", ios::binary | ios::out | ios::in);      
	fin.seekg(0, ios::end);                                        ///////To find number of bytes in file and by using formula////////////
	no_of_bytes = fin.tellg();                                     ///////finding no_of_records./////////////////////////////////////////
	no_of_records = no_of_bytes / sizeof(Library);                ////////seekg to set position pointer at different positions/////////
	fin.seekg(0, ios::beg);  
	do
	{
		system("cls"); 
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t SEARCH BY RECORD NO:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter Record No:(1-" << no_of_records << "):";
		cin >> choice;
		cout << endl;
		if (choice >= 1 && choice <= no_of_records)
		{
			fin.seekg((choice - 1) * sizeof(Library), ios::beg); //(choice-1) to move to that index as index starts from 0.and settinf pointer at that position
			fin.read((char*)&l, sizeof(Library));    //reading record at that index
			cout << "Record Found." << endl;
			cout << "--------------" << endl << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			l.display();
		}
		else
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	fin.close();
	Search_books();
}
//Main Search funtion
void Search_books()
{
	system("cls");
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t     SEARCH BOOKS" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t     (1)-SEARCH BY RECORD NUMBER\n\t\t\t     (2)-SEARCH BY BOOK TITILE\n\t\t\t     (3)-SEARCH BY BOOK_AUTHOR\n\t\t\t     (4)-SEARCH BY BOOK_ID\n\t\t\t     (5)-MAIN MENU" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "Enter Choice(1-5):";
	cin >> choice;
	if (!(choice >= 1 && choice <= 5))
	{
		do {
			cout << "Enter Valid Choice between(1-5):";
			cin >> choice;
		} while (!(choice >= 1 && choice <= 5));
	}

	switch (choice)
	{
	case 1:system("cls");
		Search_by_record();
		break;
	case 2:system("cls");
		Search_by_title();
		break;
	case 3:system("cls");
		Search_by_author();
		break;
	case 4:system("cls");
		Search_by_ID();
		break;
	case 5:system("cls");
	       Display_Menu();
		   break;
	}
}
//deleting book
void delete_books()
{
	ifstream fin;
	char name[50];
	bool checker;
	ofstream  fout;
	Library data;
	do {
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     DELETE BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		fout.open("new_records.bin", ios::binary | ios::out);    //to store data after deleting desired record
		fin.open("records.bin", ios::binary | ios::in);
		cout << "Enter Book Title whose Information you want to delete:";
		cin.ignore();
		cin.getline(name, 50);
		checker = false;
		cout << endl;
		while (fin.read((char*)&data, sizeof(Library)))
		{
			if (strcmp(name, data.Book_Title) == 0)   //comparing two strings
			{
				cout << "Record Found." << endl;
				cout << "--------------" << endl << endl;
				cout << "----------------------------------------------------------------------" << endl;
				cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
				cout << "----------------------------------------------------------------------" << endl;
				data.display();
				checker = true;
			}
			else
			{
				fout.write((char*)&data, sizeof(Library));
			}
		}
		fout.close();   //closing them so ////
		fin.close();    //they can be deleted/renamed.////
		if (!checker)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
			remove("new_records.bin"); //As record not found so we dont need that file
		}
		else
		{
			int s;
			s = remove("records.bin");   //record found and data is written into another file so we delete it
			if (s == 0)
			{
				cout << endl << endl;
				cout << "Book Successfully Deleted." << endl;
				cout << "--------------------------" << endl;
				rename("new_records.bin", "records.bin");   //And rename that file with that file so we can use it further
			}
			else
			{
				cout << endl << endl;
				cout << "Record Not deleted successfully." << endl;
				cout << "--------------------------------" << endl;
			}
		}
		cout << endl;
		cout << "Do you Want to Delete more Books?(Y/N):"<<endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Display_Menu();
}
//updating book
void Update_books()
{
	fstream fout;
	char ch;
	fout.open("records.bin", ios::binary | ios::out | ios::in);
	fout.seekg(0, ios::end);
	no_of_records = fout.tellg() / sizeof(Library);
	Library data;
	do {
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t    UPDATE BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << endl;
		cout << "Enter Record No you want to update(1-"<<no_of_records<<"):";
		cin >> choice;
		cout << endl;
		if (choice >= 1 && choice <= no_of_records)
		{
			cout << "Record found." << endl;
			cout << "---------------" << endl;
			fout.seekg((choice - 1) * sizeof(Library), ios::beg);
			cout << "Enter New Book Title:";
			cin.ignore();
			cin.getline(data.Book_Title, 50);
			cout << "Enter New Book_Author:";
			cin.getline(data.Book_Author, 50);
			cout << "Enter New  Book_ID:";
			cin >> data.Book_ID;
			fout.write((char*)&data, sizeof(Library));
			cout <<endl;
			cout << "Book Successfully Updated.New Book Record is:" << endl<<endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
			cout<<"----------------------------------------------------------------------"<<endl;
			data.display();
		}
		else
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl << endl;
		cout << "Do you Want to Update more Books?(Y/N):" << endl;
		cout << "-----------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	fout.close();
	Display_Menu();
}
//displaying all books
void list_books()
{
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t     LIST ALL BOOKS" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << endl << endl;
	ifstream fin;
	fin.open("records.bin", ios::binary | ios::in);
	Library l;
	fin.seekg(0, ios::end);
	no_of_bytes = fin.tellg();                               //Same as defined above
	no_of_records = no_of_bytes / sizeof(Library);
	fin.seekg(0, ios::beg);
	cout <<"---------------------------------------------------------------------" << endl;
	cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
	cout <<"---------------------------------------------------------------------" << endl;
	for (int i = 0; i < no_of_records; i++)
	{
		fin.read((char*)&l, sizeof(Library));
		l.display();
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Total Number of Records are:" << no_of_records << endl;
	cout << "--------------------------------------------------------------------" << endl;
	fin.close();
	system("pause");
	Display_Menu();
}
//adding new books
void Add_books()
{
	int i = 0;
	fstream fout;
	fout.open("records.bin", ios::binary | ios::out | ios::in | ios::app);
	Library data;
	fout.seekg(0, ios::end);
	no_of_bytes = fout.tellg();
	no_of_records = no_of_bytes / sizeof(Library);
	fout.seekg(0, ios::beg);
	do
	{

		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     ADD BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter Book Title:";
		cin.ignore();
		cin.getline(data.Book_Title, 50);
		//cin.ignore();
		cout << "Enter Book_Author:";
		cin.getline(data.Book_Author, 50);
		cout << "Enter Book_ID:";
		cin >> data.Book_ID;
		fout.write((const char*)&data, sizeof(Library));
		cout<<"--------------------------"<<endl;
		cout << "Book Successfully added." << endl;
		cout << "--------------------------" << endl;
		cout << "Do you Want to add more books?(Y/N):";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	fout.close();
	Display_Menu();
}
void Display_Menu()
{
	system("cls");
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t     (1)-ADD BOOK INFORMATION\n\t\t\t     (2)-SEARCH BOOK INFORMATION\n\t\t\t     (3)-UPDATE BOOK INFORMATION\n\t\t\t     (4)-DELETE BOOK INFORMATION\n\t\t\t     (5)-LIST ALL BOOKS\n\t\t\t     (6)-EXIT\n" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "Enter Choice:";
	cin >> choice;
	if (!(choice >= 1 && choice <= 6))
	{
		do {
			cout << "Enter Valid Choice between(1-6):";
			cin >> choice;
		} while (!(choice >= 1 && choice <= 6));
	}

	switch (choice)
	{
	case 1:system("cls");
		Add_books();
		break;
	case 2:system("cls");
		Search_books();
		break;
	case 3:system("cls");
		Update_books();
		break;
	case 4:system("cls");
		delete_books();
		break;
	case 5:system("cls");
		list_books();
		break;
	case 6:puts("\t\t\t-------------------------------\n\t\t\t|Thanks for Using Our System.|\n\t\t\t-------------------------------");
		exit(0);
		break;
	}
}


