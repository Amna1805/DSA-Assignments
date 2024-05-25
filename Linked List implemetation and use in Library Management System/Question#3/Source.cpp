#include"Header.h"
int main()
{
	fstream f;
	f.open("records.bin", ios::in | ios::out | ios::binary);
	if (f.is_open())
	{
		Library data;
		f.seekg(0, ios::end);
		int no_of_bytes = f.tellg();
		int no_of_records = no_of_bytes / sizeof(Library);
		f.seekg(0, ios::beg);
		for (int i = 0; i < no_of_records; i++)
		{
			f.read((char*)&data, sizeof(Library));
			l.insert(l.end(), data);
		}
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
	return 0;
}