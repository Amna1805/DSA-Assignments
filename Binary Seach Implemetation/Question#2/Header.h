#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<map>
using namespace std;
void Display_Menu();
void Search_books();
struct Library
{

	char Book_Title[50];
	char Book_Author[50];
	int Book_ID;
	int year;
	char Book_Category;
};
map<int, Library> m;
pair<int, Library>p;
void input_books(Library & l)
{
	cout << "Enter Book_Title:";
	cin.ignore();
	cin.getline(l.Book_Title, 50);
	cout << "Enter Book_Author:";
	cin.getline(l.Book_Author, 50);
	cout << "Enter Book_Id:";
	cin >> l.Book_ID;
	cout << "Enter year of Publication:";
	cin >> l.year;
	cout << "Enter Category(A for Academic/F for Fiction/N for Non-Fiction):";
	cin >> l.Book_Category;
}
void output_books(Library& l)
{
	cout << setw(10) << l.Book_Title << setw(30) << l.Book_Author << setw(15) << l.Book_ID << setw(23) << l.year << setw(15) << l.Book_Category << endl;
}
////Search by year
void Search_by_year()
{
	typename map<int, Library>::iterator it;
	Library data;
	bool check;
	int y;
	char ch;
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK YEAR:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_YEAR you want to search:";
		cin >> y;
		check = false;
		cout << endl;
		it = m.begin();
		while (it != m.end())
		{
			if (it->second.year == y)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = it->second;
				cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				output_books(data);
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				check = true;
			}
			it++;
		}
		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
////Search by ID
void Search_by_ID()
{
	typename map<int,Library>::iterator it;
	Library data;
	bool check;
	int id;
	char ch;
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
		check = false;
		cout << endl;
		it = m.begin();
		while (it != m.end())
		{
			if (it->first== id)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = it->second;
				cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				output_books(data);
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				check = true;
			}
			it++;
		}
		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
///Serach by author
void Search_by_author()
{
	typename map<int, Library>::iterator it;
	Library data;
	bool check;
	char author[50];
	char ch;
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK AUTHOR:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_Author you want to search:";
		cin.ignore();
		cin.getline(author, 50);
		check = false;
		cout << endl;
		it = m.begin();
		while (it != m.end())
		{
			if (strcmp(it->second.Book_Author, author) == 0)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = it->second;
				cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				output_books(data);
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				check = true;
			}
			it++;
		}
		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
//Searching book by its title
void Search_by_title()
{
	typename map<int,Library>::iterator it;
	Library data;
	bool check = false;;
	char ch;
	char name[50];
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK TITLE:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_Title you want to search:";
		cin.ignore();
		cin.getline(name, 50);
		check = false;
		cout << endl;
		it = m.begin();
		while (it != m.end())
		{
			if (strcmp(it->second.Book_Title, name) == 0)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = it->second;
				cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				output_books(data);
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				check = true;
			}
			it++;
		}
		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
//Main Search funtion
void Search_books()
{
	system("cls");
	int choice;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t     SEARCH BOOKS" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t     (1)-SEARCH BY BOOK TITILE\n\t\t\t     (2)-SEARCH BY BOOK_AUTHOR\n\t\t\t     (3)-SEARCH BY BOOK_ID\n\t\t\t     (4)-SEARCH BY YEAR\n\t\t\t     (5)-MAIN MENU" << endl;
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
		Search_by_title();
		break;
	case 2:system("cls");
		Search_by_author();
		break;
	case 3:system("cls");
		Search_by_ID();
		break;
	case 4:system("cls");
		Search_by_year();
		break;
	case 5:system("cls");
		Display_Menu();
		break;
	}
}
//deleting book
void delete_books()
{
	char name[50];
	bool check = false;
	char ch;
	Library data;
	typename map<int,Library>::iterator it;
	do {
		check = false;
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     DELETE BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl << endl;
		cout << "Enter Book Title whose Information you want to delete:";
		cin.ignore();
		cin.getline(name, 50);
		it = m.begin();
		while (it != m.end())
		{
			if (strcmp(name, it->second.Book_Title) == 0)
			{
				cout << "-----------------------" << endl;
				cout << "Record Found." << endl;
				cout << "-----------------------" << endl;
				check = true;
				data = it->second;
				cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				output_books(data);
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				m.erase(it);
				cout << "---------------------------------" << endl;
				cout << "Record deleted Successfully" << endl;
				cout << "---------------------------------" << endl;
				break;
			}
			else
			{
				it++;
			}
		}
		if (!check)
		{
			cout << "\t\t\t-------------------------------------" << endl;
			cout << "Record Not found." << endl;
			cout << "\t\t\t-------------------------------------" << endl;
		}
		cout << endl << endl;
		cout << "Do you Want to Delete more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Display_Menu();
}
//updating book
void Update_books()
{
	char ch;
	int id;
	Library data;
	bool check = false;
	typename map<int,Library>::iterator it;
	do {
		check = false;
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t    UPDATE BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << endl;
		cout << "Enter Book Id you want to update:";
		cin >> id;
		it = m.begin();
		while (it != m.end())
		{
			if (it->second.Book_ID== id)
			{
				cout << "-------------------------------------" << endl;
				cout << "Record Found." << endl;
				cout << "-------------------------------------" << endl;
				check = true;
				cout << "Enter New Details:" << endl;
				cout << "--------------------" << endl;
				input_books(data);
				p.first = data.Book_ID;
				p.second = data;
				m.insert(p);
				m.erase(it++);
				cout << "-------------------------------------" << endl;
				cout << "Record Updated Successfully." << endl;
				cout << "-------------------------------------" << endl;
				break;
			}
			else
			{
				it++;
			}
		}
		if (!check)
		{
			cout << "-------------------------------------" << endl;
			cout << "Record Not found." << endl;
			cout << "-------------------------------------" << endl;
		}
		cout << endl << endl;
		cout << "Do you Want to Update more Books?(Y/N):" << endl;
		cout << "-----------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Display_Menu();
}
//displaying all books
void display_books()
{
	typename map<int,Library>::iterator it;
	Library data;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t     LIST ALL BOOKS" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << endl << endl;
	cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

	it = m.begin();
	while (it != m.end())
	{
		data = it->second;
		output_books(data);
		it++;
	}
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	Display_Menu();
}
//adding new books
void Add_books()
{
	int i = 0;
	char ch;
	Library data;
	do
	{

		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     ADD BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		input_books(data);
		p.first = data.Book_ID;
		p.second = data;
		m.insert(m.end(),p);
		cout << "--------------------------" << endl;
		cout << "Book Successfully added." << endl;
		cout << "--------------------------" << endl;
		cout << "Do you Want to add more books?(Y/N):";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	Display_Menu();
}
void Display_Menu()
{
	system("cls");
	int choice;
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
		display_books();
		break;
	case 6:
		typename map<int,Library>::iterator it;
		fstream f;
		Library data;
		f.open("records.bin", ios::out | ios::binary);
		it = m.begin();
		while (it != m.end())
		{
			data = it->second;
			f.write((const char*)&data, sizeof(data));
			it++;
		}
		f.close();
		puts("\t\t\t-------------------------------\n\t\t\t|Thanks for Using Our System.|\n\t\t\t-------------------------------");
		exit(0);
		break;
	}
}

