#include"Header.h"
using namespace std;
int main(int argc, char*argv[])
{

	if (argc == 1)   //when no command in line arguments pass
	{
		fstream f;
		f.open("records.bin", ios::binary | ios::in | ios::out);
		if (f.is_open())    //if file exsite
		{
			f.close();
			Display_Menu();
		}
		else
		{
			cout << "Cannot Open a file.Creating a file with name records.bin." << endl;   
			f.open("records.bin", ios::binary | ios::out);  //creating file
			f.close();
			Display_Menu();
		}

	}
	else    //When command lines are passed
	{
		cout << "WELCOME TO COMMAND LINE ARGUMENTS." << endl;
		cout << "----------------------------------" << endl;
		fstream f;
		f.open(argv[1], ios::binary | ios::in | ios::out);
		if (f.is_open())
		{
			f.close();

    	}
		else
		{
			cout << "Cannot Open a file.Creating a file with name " << argv[1] << endl;
			cout << "----------------------------------------------" << endl;
			f.open(argv[1], ios::binary | ios::out);
			f.close();
		}
		//HERE LOGICS ARE SAME JUST REPLACE THEM WITH ARGUMENTS WE PASS
		if (argc >= 3)    //it must be 3 arguments.1st will be default.2md must be file name and 3rd must be operation you wants to perform
		{
			if (strcmp(argv[2], "add") == 0) //comparing to perform functionalites
			{
				if (argc == 6)
				{
					fstream fout;
					fout.open(argv[1], ios::binary | ios::out | ios::app);
					Library l;
					strcpy_s(l.Book_Title, argv[3]);
					strcpy_s(l.Book_Author, argv[4]);
					l.Book_ID = stoi(argv[5]);
					fout.write((const char*)&l, sizeof(Library));
					cout << "----------------------------------------------------------------------" << endl;
					cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
					cout << "----------------------------------------------------------------------" << endl;
					l.display();
					cout << endl << endl;
					cout << "----------------------------" << endl;
					cout << "Record added Succesfully." << endl;
					cout << "----------------------------" << endl;
					fout.close();
				}
				else
				{
					cout << "USAGE FOR ADD:[FILE_NAME] [add] [TITLE] [AUTHOR] [ID]" << endl;
				}
				return 0;
			}
			else if (strcmp(argv[2], "list") == 0)
			{
				if (argc == 3)
				{
					ifstream fin;
					fin.open(argv[1], ios::binary | ios::in);
					Library l;
					fin.seekg(0, ios::end);
					no_of_bytes = fin.tellg();
					no_of_records = no_of_bytes / sizeof(Library);
					fin.seekg(0, ios::beg);
					cout << "---------------------------------------------------------------------" << endl;
					cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					for (int i = 0; i < no_of_records; i++)
					{
						fin.read((char*)&l, sizeof(Library));
						l.display();
					}
					cout << "--------------------------------------------------------------------" << endl;
					cout << "Total Number of Records are:" << no_of_records << endl;
					cout << "--------------------------------------------------------------------" << endl;
					fin.close();
				}
				else
				{
					cout << "USAGE FOR LIST:[FILE_NAME] [list]" << endl;
				}
				return 0;

			}
			else if (strcmp(argv[2], "update") == 0)
			{

				if (argc == 7)
				{
					fstream fout;
					Library l;
					fout.open(argv[1], ios::binary | ios::out | ios::in);
					fout.seekg(0, ios::end);
					no_of_records = fout.tellg() / sizeof(Library);
					int rec_no = stoi(argv[3]);
					if (rec_no >= 1 && rec_no <= no_of_records)
					{
						fout.seekg((rec_no - 1) * sizeof(Library), ios::beg);
						strcpy_s(l.Book_Title, argv[4]);
						strcpy_s(l.Book_Author, argv[5]);
						l.Book_ID = stoi(argv[6]);
						fout.write((const char*)&l, sizeof(Library));
						fout.close();
						cout << "Book Successfully Updated.New Book Record is:" << endl << endl;
						cout << "----------------------------------------------------------------------" << endl;
						cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
						cout << "----------------------------------------------------------------------" << endl;
						l.display();
					}
					else
					{
						cout << "Record not found." << endl;
						cout << "------------------" << endl;
						cout << "Enter Record Number between(1-" << no_of_records << "):" << endl;
					}
				}
				else
				{
					cout << "USAGE FOR UPDATE:[FILE_NAME] [update] [RECORD_NO] [TITLE] [AUTHOR] [ID]" << endl;
				}
				return 0;
			}
			else if (strcmp(argv[2], "delete") == 0)
			{
				if (argc == 4)
				{
					ifstream fin;
					bool checker = false;
					ofstream  fout;
					Library data;
					fout.open("new_records.bin", ios::binary | ios::out);
					fin.open(argv[1], ios::binary | ios::in);
					while (fin.read((char*)&data, sizeof(Library)))
					{
						if (strcmp(argv[3], data.Book_Title) == 0)
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
					fout.close();
					fin.close();
					if (!checker)
					{
						cout << "Record not found." << endl;
						cout << "------------------" << endl;
						remove("new_records.bin");
					}
					else
					{
						int s;
						s = remove(argv[1]);
						if (s == 0)
						{
							cout << endl << endl;
							cout << "Book Successfully Deleted." << endl;
							cout << "--------------------------" << endl;
							rename("new_records.bin", argv[1]);
						}
						else
						{
							cout << endl << endl;
							cout << "Record Not deleted successfully." << endl;
							cout << "--------------------------------" << endl;
						}
					}
				}
				else
				{
					cout << "USAGE FOR DELETE:[FILE_NAME] [delete] [TITLE]" << endl;
				}
				return 0;
			}
			else if (strcmp(argv[2], "search") == 0)
			{
				if (argc == 5)
				{
					if (strcmp(argv[3], "s_b_rec") == 0)
					{
						ifstream fin;
						Library l;
						fin.open(argv[1], ios::binary | ios::out | ios::in);
						fin.seekg(0, ios::end);
						no_of_bytes = fin.tellg();
						no_of_records = no_of_bytes / sizeof(Library);
						fin.seekg(0, ios::beg);
						int rec_no = stoi(argv[4]);
						if (rec_no >= 1 && rec_no <= no_of_records)
						{
							fin.seekg((rec_no - 1) * sizeof(Library), ios::beg);
							fin.read((char*)&l, sizeof(Library));
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
							cout << "Enter Record Number between(1-" << no_of_records << "):" << endl;
						}
						fin.close();
					}
					else if (strcmp(argv[3], "s_b_tit") == 0)
					{
						ifstream fin;
						Library data;
						bool checker = false;
						fin.open(argv[1], ios::binary | ios::in);
						while (fin.read((char*)&data, sizeof(data)))
						{
							if (strcmp(argv[4], data.Book_Title) == 0)
							{
								cout << "Record Found." << endl;
								cout << "--------------" << endl << endl;
								cout << "----------------------------------------------------------------------" << endl;
								cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
								cout << "----------------------------------------------------------------------" << endl;
								data.display();
								checker = true;
							}

						}
						fin.close();
						if (!checker)
						{
							cout << "Record not found." << endl;
							cout << "------------------" << endl;
						}

						fin.close();
					}
					else if (strcmp(argv[3], "s_b_aut") == 0)
					{
						ifstream fin;
						Library data;
						bool checker = false;
						fin.open(argv[1], ios::binary | ios::in);
						while (fin.read((char*)&data, sizeof(data)))
						{
							if (strcmp(argv[4], data.Book_Author) == 0)
							{
								cout << "Record Found." << endl;
								cout << "--------------" << endl << endl;
								cout << "----------------------------------------------------------------------" << endl;
								cout << "BOOK_ID" << setw(28) << "BOOK_TITLE" << setw(30) << "BOOK_AUTHOR" << endl;
								cout << "----------------------------------------------------------------------" << endl;
								data.display();
								checker = true;
							}

						}
						fin.close();
						if (!checker)
						{
							cout << "Record not found." << endl;
							cout << "------------------" << endl;
						}

						fin.close();
					}
					else if (strcmp(argv[3], "s_b_id") == 0)
					{
						ifstream fin;
						Library data;
						bool checker = false;
						int id = stoi(argv[4]);
						fin.open(argv[1], ios::binary | ios::in);
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
								checker = true;
							}
						}
						fin.close();
						if (!checker)
						{
							cout << "Record not found." << endl;
							cout << "------------------" << endl;
						}
						fin.close();
					}
					else
					{
						cout << "USAGE FOR SEARCH:[FILE_NAME] [search] [s_b_rec/s_b_tit/s_b_aut/s_b_id] [rec_no/title/author/id]" << endl;
					}
				}
				else
				{
					cout << "USAGE FOR SEARCH:[FILE_NAME] [search] [s_b_rec/s_b_tit/s_b_aut/s_b_id] [rec_no/title/author/id]" << endl;
				}
				return 0;
			}
			else
			cout << "Usage for different Funtions:" << endl;
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "1-Usage for ADD:[FILE_NAME] [add] [TITLE] [AUTHOR] [ID]" << endl;
			cout << "2-Usage for SEARCH:[FILE_NAME] [search] [s_b_rec/s_b_tit/s_b_aut/s_b_id] [rec_no/title/author/id]" << endl;
			cout << "3-Usage for UPDATE:[FILE_NAME] [update] [TITLE] [AUTHOR] [ID]" << endl;
			cout << "4-Usage for DELETE:[FILE_NAME] [delete] [TITLE]" << endl;
			cout << "5-Usage for LIST:[FILE_NAME] [list]" << endl;
     
		}
		else
		{
			cout << "Usage for different Funtions:" << endl;
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "1-Usage for ADD:[FILE_NAME] [add] [TITLE] [AUTHOR] [ID]" << endl;
			cout << "2-Usage for SEARCH:[FILE_NAME] [search] [s_b_rec/s_b_tit/s_b_aut/s_b_id] [rec_no/title/author/id]" << endl;
			cout << "3-Usage for UPDATE:[FILE_NAME] [update] [TITLE] [AUTHOR] [ID]" << endl;
			cout << "4-Usage for DELETE:[FILE_NAME] [delete] [TITLE]" << endl;
			cout << "5-Usage for LIST:[FILE_NAME] [list]" << endl;
		}
	}
	return 0;
}
