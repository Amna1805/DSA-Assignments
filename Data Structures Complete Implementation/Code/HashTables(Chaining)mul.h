#include<iostream>
#include<list>
using namespace std;
template<typename T>
class hashtables_chaining_mul
{
	list<T>* data;
	int m;
public:
	hashtables_chaining_mul(const int s = 8)
	{
		m = s;
		data = new list<T>[m];
	}
	~hashtables_chaining_mul()
	{
	
		delete[] data;
	}
	int hash_mul(T val, int s, float a)
	{
		return s * ((val * a) - int(val * a));
	}
	void insert(const T& val)
	{
		int i = hash_mul(val, m, 0.3);
		data[i].insert(data[i].end(), val);
	}
	bool erase_h(const T& val)
	{
		typename list<T> ::iterator it;
		int i = hash_mul(val, m, 0.3);
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
		int i = hash_mul(val, m, 0.3);
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