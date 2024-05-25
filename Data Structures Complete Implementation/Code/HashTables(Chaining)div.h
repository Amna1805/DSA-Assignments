#include<iostream>
#include<list>
using namespace std;
template<typename T>
class hashtables_chaining_div
{
	list<T>* data;
	int m;
public:
	hashtables_chaining_div(const int s = 8)
	{
		m = s;
		data = new list<T>[m];
	}
	~hashtables_chaining_div()
	{
		delete[] data;
	}
	int hash_div(T val, int s)
	{
		return val % s;
	}
	void insert(const T& val)
	{
		int i = hash_div(val, m);
		data[i].insert(data[i].end(), val);
	}
	bool erase_h(const T& val)
	{
		typename list<T> ::iterator it;
		int i = hash_div(val, m);
		if (i >= 0 && i < m)
		{
			it = data[i].begin();
			while (it != data[i].end())
			{
				if (*it == val)
				{
					data[i].erase(it);
					return true;
				}
				it++;
			}
		}
		
		return false;
	}
	bool find_h(const T& val)
	{
		typename list<T> ::iterator it;
		int i = hash_div(val, m);
		if (i >= 0 && i < m)
		{
			it = data[i].begin();
			while (it != data[i].end())
			{
				if (*it == val)
				{
					return true;
				}
				it++;
			}
			return false;
		}
		return false;
		
	}
	bool update_h(const T& val, const T& u_val)
	{
		if (erase_h(val))
		{
			insert(u_val);
			return true;
		}
		return false;
	}
	void display()
	{
		typename list<T> ::iterator it;
		cout << "Values in Hash Table are :" << endl;
		for (int i = 0; i < m; i++)
		{
			it = data[i].begin();
			cout << "Values at index " << i << " are:" << endl;
			while (it != data[i].end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
		}
	}
};
