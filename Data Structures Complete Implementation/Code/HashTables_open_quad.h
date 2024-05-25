#include<iostream>
using namespace std;
const int Empty_quad = -1;
const int del_quad = -2;
template<typename T>
class hashtables_open_quad
{
	int m;
	int n;
	int c1, c2;
	T* data;
public:
	hashtables_open_quad(const int s = 8)
	{
		m = s;
		n = 0;
		c1 = 3;
		c2 = 2;
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
		for (int i = 0; i < m; i++)
		{
			int idxx = (idx + c1 * i + c2 * i * i) % m;
			if (data[idxx] == Empty_quad || data[idx] == del_quad)
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
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idxx = (idx + c1 * i + c2 * i * i) % m;
				if (data[idxx] == val)
				{
					data[idxx] = del;
					n--;
					return true;
				}
			}
			return false;
		}
		return false;
	}
	bool find(const T& val)
	{
		int idx = hash_div(val, m);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idxx = (idx + c1 * i + c2 * i * i) % m;
				if (idxx >= 0 && idxx < m)
				{
					if (data[idxx] == val)
					{
						return true;
					}
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
	~hashtables_open_quad()
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