#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<list>
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
list<Library>l;
void input_books(Library& l)
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
void Search_Year_author_Category(list<Library>& ll, int y, string a)
{
	typename list<Library>::iterator it;
	Library data;
	bool check;
	char c;
	char ch;
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t   SEARCH BY BOOK CATEGORY IN YEAR:" << y << " OF AUTHOR:" << a << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "Enter Category  you want to search:";
		cin >> c;
		check = false;
		cout << endl;
		it = ll.begin();
		while (it != ll.end())
		{
			if (it->Book_Category == c)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = *it;
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
void Search_Year_Author(list<Library>& ll, int y)
{
	typename list<Library>::iterator it;
	list<Library>year_author;
	Library data;
	bool check;
	char a[50];
	char ch;
	do
	{
		year_author.clear();
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tSEARCH BY BOOK AUTHOR IN YEAR:" << y << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter Author  you want to search:";
		cin.ignore();
		cin.getline(a, 50);
		check = false;
		cout << endl;
		it = ll.begin();
		while (it != ll.end())
		{
			if (it->year == y)
			{
				data = *it;
				year_author.insert(year_author.end(), data);
				check = true;
			}
			it++;
		}

		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		else
		{

			Search_Year_author_Category(year_author, y, a);
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
void Search_by_year()
{
	typename list<Library>::iterator it;
	char ch;
	Library data;
	int choice;
	bool check;
	int y;
	list<Library> year;
	do
	{
		year.clear();
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK YEAR:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter Year you want to search:";
		cin >> y;
		check = false;
		it = l.begin();
		while (it != l.end())
		{
			if (it->year == y)
			{
				data = *it;
				year.insert(year.end(), data);
				check = true;
			}
			it++;
		}
		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		else
		{

			Search_Year_Author(year, y);
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl; //If user want to search more books
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
void Search_Author_year_Category(list<Library>& ll, string a, int y)
{
	typename list<Library>::iterator it;
	Library data;
	bool check;
	char c;
	char ch;
	do
	{
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t   SEARCH BY BOOK CATEGORY OF AUTHOR:" << a << " IN YEAR:" << y << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "Enter Category  you want to search:";
		cin >> c;
		check = false;
		cout << endl;
		it = ll.begin();
		while (it != ll.end())
		{
			if (it->Book_Category == c)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = *it;
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
void Search_Author_year(list<Library>& ll, string a)
{
	typename list<Library>::iterator it;
	list<Library> authors_years;
	Library data;
	bool check;
	int y;
	char ch;
	do
	{
		authors_years.clear();
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tSEARCH BY BOOK YEAR OF AUTHOR:" << a << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter Year  you want to search:";
		cin >> y;
		check = false;
		cout << endl;
		it = ll.begin();
		while (it != ll.end())
		{
			if (it->year == y)
			{
				data = *it;
				authors_years.insert(authors_years.end(), data);
				check = true;
			}
			it++;
		}

		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		else
		{

			Search_Author_year_Category(authors_years, a, y);
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl;
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
void Search_by_author()
{
	typename list<Library>::iterator it;
	char ch;
	Library data;
	int choice;
	bool check;
	char author[50];
	list<Library> authors;
	do
	{
		authors.clear();
		system("cls");
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t     SEARCH BOOKS" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "\t\t\t\t   SEARCH BY BOOK AUTHOR:" << endl;
		cout << "\t\t\t-------------------------------------" << endl;
		cout << "Enter BOOK_Title you want to search:";
		cin.ignore();
		cin.getline(author, 50);
		check = false;
		it = l.begin();
		while (it != l.end())
		{
			if (strcmp(it->Book_Author, author) == 0)
			{
				data = *it;
				authors.insert(authors.end(), data);
				check = true;
			}
			it++;
		}
		if (!check)
		{
			cout << "Record not found." << endl;
			cout << "------------------" << endl;
		}
		else
		{

			Search_Author_year(authors, author);
		}
		cout << endl;
		cout << "Do you Want to Search more Books?(Y/N):" << endl; //If user want to search more books
		cout << "---------------------------------------" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	Search_books();
}
void Search_by_ID()
{
	typename list<Library>::iterator it;
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
		it = l.begin();
		while (it != l.end())
		{
			if (it->Book_ID == id)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = *it;
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
	typename list<Library>::iterator it;
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
		it = l.begin();
		while (it != l.end())
		{
			if (strcmp(it->Book_Title, name) == 0)
			{
				cout << "Record found." << endl;
				cout << "------------------" << endl;
				data = *it;
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
	typename list<Library>::iterator it;
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
		it = l.begin();
		while (it != l.end())
		{
			if (strcmp(name, it->Book_Title) == 0)
			{
				cout << "-----------------------" << endl;
				cout << "Record Found." << endl;
				cout << "-----------------------" << endl;
				check = true;
				data = *it;
				cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				output_books(data);
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				l.erase(it);
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
	typename list<Library>::iterator it;
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
		it = l.begin();
		while (it != l.end())
		{
			if (it->Book_ID == id)
			{
				cout << "-------------------------------------" << endl;
				cout << "Record Found." << endl;
				cout << "-------------------------------------" << endl;
				check = true;
				cout << "Enter New Details:" << endl;
				cout << "--------------------" << endl;
				input_books(data);
				l.insert(it, data);
				l.erase(it++);
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
	typename list<Library>::iterator it;
	Library data;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO LIBRARY INFORMATION SYSTEM" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << "\t\t\t\t     LIST ALL BOOKS" << endl;
	cout << "\t\t\t-------------------------------------" << endl;
	cout << endl << endl;
	cout << "   " << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << setw(15) << "BOOK_ID" << setw(20) << "YEAR" << setw(20) << "CATEGORY" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

	it = l.begin();
	while (it != l.end())
	{
		data = *it;
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
		l.insert(l.end(), data);
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
		typename list<Library>::iterator it;
		fstream f;
		Library data;
		f.open("records.bin", ios::out | ios::binary);
		it = l.begin();
		while (it != l.end())
		{
			data = *it;
			f.write((const char*)&data, sizeof(data));
			it++;
		}
		f.close();
		puts("\t\t\t-------------------------------\n\t\t\t|Thanks for Using Our System.|\n\t\t\t-------------------------------");
		exit(0);
		break;
	}
}

