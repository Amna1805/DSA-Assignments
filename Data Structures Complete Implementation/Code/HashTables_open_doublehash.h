#include<iostream>
using namespace std;
const int Empty_hash = -1;
const int del_hash = -2;
template<typename T>
class hashtables_open_doublehash
{
	int m;
	int n;
	T* data;
public:
	hashtables_open_doublehash(const int s = 8)
	{
		m = s;
		n = 0;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = -1;
		}
	}
	int hash_div(T val, int s)
	{
		return val % s;
	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 29);
		for (int i = 0; i < m; i++)
		{
			int idxx = (idx + i * (1 + h2)) % m;
			if (data[idxx] == Empty_hash || data[idx] == del_hash)
			{
				data[idxx] = val;
				n++;
				return;
			}
		}
	}
	bool erase(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 29);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idxx = (idx + i * (1 + h2)) % m;
				if (idxx >= 0 && idxx < m)
				{
					if (data[idxx] == val)
					{
						data[idxx] = del;
						n--;
						return true;
					}
				}
				
			}
			return false;
		}
		return false;
	}
	bool find(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 29);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idxx = (idx + i * (1 + h2)) % m;
				if (data[idxx] == val)
				{
					return true;
				}
			}
			return false;
		}
		return false;
	}
	bool update(const T& val, const T& u_val)
	{
		if (find(val))
		{
			erase(val);
			insert(u_val);
			return true;
		}
		return false;
	}
	~hashtables_open_doublehash()
	{
		delete[] data;
	}
	void display()
	{
		cout << "Values in Hash-Table are:" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};