#include<iostream>
#include<cstdlib>
using namespace std;
///////////////////////////////////////ARRAY BASED DOUBLE ENDED QUEUE////////////////////////////////////////////////////////
template<typename T>
class queue
{
	int f, r;
	int size;
	T* data;
public:
	queue(const int& s = 5)
	{
		size = s + 1;
		data = new T[size];
		f = 0;
		r = 0;
	}
	~queue()
	{
		make_empty();
	}
	queue(const queue& q)
	{
		operator=(q);
	}
	void push(const int& val)   /////same as push_back()
	{
		if (isfull())
		{
			throw("Queue Overflow.");
		}
		r = (r + 1) % size;
		data[r] = val;
	}
	void push_back(const T& s)
	{
		if (isfull())
		{
			throw("Queue Overflow.");
		}
		r = (r + 1) % size;
		data[r] = s;
	}
	void push_front(const T& s)
	{
		if (isfull())
		{
			throw("Queue Overflow.");
		}
		data[f] = s;
		if (f == 0)   //So that it will not equal to -1.
		{
			f = size - 1;
		}
		else
		{
			f = f - 1;
		}

	}
	void pop()///same as pop_front()
	{
		if (empty())
		{
			throw("Queue underflow.");
		}
		f = (f + 1) % size;
	}
	void pop_rear()
	{
		if (empty())
		{
			throw("Queue underflow.");
		}
		if (r == 0)// So that it will not equal to - 1.
		{
			r = size - 1;
		}
		else
		{
			r--;
		}
	}
	void pop_front()
	{
		if (empty())
		{
			throw("Queue underflow.");
		}
		f = (f + 1) % size;
	}
	T front() const
	{

		if (empty())
		{
			throw("Queue underflow.");
		}
		return data[(f + 1) % size];

	}
	T rear() const
	{
		if (empty())
		{
			throw("Queue underflow.");
		}
		return data[r];
	}
	bool empty() const
	{
		return f == r;
	}
	bool isfull() const
	{
		return r + 1 % size == f;
	}
	void operator=(const queue& q)
	{
		if (!empty())
		{
			make_empty();
		}
		f = q.f;
		r = q.r;
		size = q.size;
		data = new T[size];
		int f_i = f;
		int r_i = (r + 1) % size;
		while (((f_i + 1) % size) != r_i)
		{
			data[(f_i + 1) % size] = q.data[(f_i + 1) % size];
			f_i++;
		}
	}
	void display()
	{
		if (empty())
		{
			throw("Queue Underflow.");
		}
		int f_i = f;
		int r_i = (r + 1) % size;
		cout << "Queuue is:";
		while ((f_i + 1) % size != r_i)
		{
			cout << data[(f_i + 1) % size] << " ";
			f_i++;
		}
		cout << endl;
	}
	void make_empty()
	{
		f = r = 0;
		delete[] data;
	}
};
int main()
{
	cout << "\t\t\t\t\t\tQUESTION#4" << endl;
	cout << "\t\t\t\t\t--------------------------" << endl << endl;
	queue<int> q;
	cout << "----------------------------------" << endl;
	q.push_back(77);
	q.push_front(1);               //pushing in back and front
	q.push_back(2);
	q.display();
	cout << "----------------------------------" << endl;
	q.push_back(4);
	q.push_back(5);
	q.display();
	cout << "----------------------------------" << endl;
	queue<int>s;
	s.push_back(88);
	s.push_front(77);
	s.display();
	cout << "----------------------------------" << endl;
	s = q;         //Copy Assignment operator
	s.display();
	try
	{
		cout << "front:" << s.front() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "Rare:" << s.rear() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	cout << "----------------------------------" << endl;

	queue<int> ss(q);   //copy constructor
	ss.display();
	try
	{
		cout << "front:" << q.front() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "Rare:" << q.rear() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "Popping from front:" << endl;
	try
	{
		q.pop_front();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	q.display();
	try
	{
		cout << "front:" << q.front() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "Rare:" << q.rear() << endl;
	}
	catch (const char& msg)
	{
		cout << msg << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "Popping from back:" << endl;
	try
	{
		q.pop_rear();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	q.display();
	try
	{
		cout << "front:" << q.front() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "Rare:" << q.rear() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "Popping from back and front:" << endl;
	try
	{
		q.pop_rear();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		q.pop_front();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	q.display();
	try
	{
		cout << "front:" << q.front() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "Rare:" << q.rear() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "Popping from front:" << endl;
	try
	{
		q.pop_front();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	try
	{
		q.display();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "front:" << q.front() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		cout << "Rare:" << q.rear() << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	cout << "----------------------------------" << endl;
	return 0;
}