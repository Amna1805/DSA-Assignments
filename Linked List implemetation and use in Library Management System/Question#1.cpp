#include<iostream>
using namespace std;
template<typename T>
struct dnode
{
	T data;
	dnode<T>* prev, * next;
};
template<typename T>
class dlist
{
	dnode<T>* f, * r, * it;
	int size;
public:
	dlist()
	{
		f = r = NULL;
		it = NULL;
		size = 0;
	}
	void insert(const T& val)
	{
		dnode<T>* temp;
		temp = new dnode<T>;
		temp->data = val;
		if (f == NULL)
		{
			temp->prev = NULL;
			temp->next = NULL;
			f = r = temp;
		}
		else
		{
			if (val >= r->data)
			{
				r->next = temp;
				temp->prev = r;
				temp->next = NULL;
				r = temp;
			}
			else if (val <= f->data)
			{
				temp->prev = NULL;
				temp->next = f;
				f->prev = temp;
				f = temp;
			}
			else
			{
				dnode<T>* scan;
				scan = f;
				while (scan != NULL)
				{
					if (scan->data > val)
					{
						temp->prev = scan->prev;
						temp->next = scan;
						scan->prev->next = temp;
						scan->prev = temp;
						break;
					}
					else
					{
						scan = scan->next;
					}
				}
			}



		}
		size++;
	}
	void pop()
	{
		dnode<T>* temp;
		temp = f;
		if (f->next == NULL)
		{
			f = r = NULL;
		}
		else
		{
			f->next->prev = NULL;
			f = f->next;
		}

		delete temp;
	}
	bool remove(const T& val)
	{
		dnode<T>* temp;
		temp = f;
		while (temp != NULL)
		{
			if (temp->data == val)
			{
				if (temp->prev == NULL)
				{
					if (temp->next == NULL)
					{
						r = f = NULL;
					}
					else
					{
						temp->next->prev = NULL;
						f = temp->next;
					}
				}
				else
				{
					if (temp->next == NULL)
					{
						temp->prev->next = NULL;
						r = temp->prev;
					}
					else
					{
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
					}
				}
				return true;
			}
			else
			{
				temp = temp->next;
			}
		}
		return false;
	}
	bool update(const T& v, const T& u_v)
	{
		dnode<T>* temp;
		temp = f;
		while (temp != NULL)
		{
			if (temp->data == v)
			{
				remove(temp->data);
				insert(temp->data = u_v);
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool find(const T& val)
	{
		dnode<T>* temp;
		temp = f;
		while (temp != NULL)
		{
			if (temp->data == val)
			{
				return true;
			}
			else
			{
				temp = temp->next;
			}
		}
		return false;
	}
	bool empty() const
	{
		return r == NULL;
	}
	void make_empty()
	{
		while (!empty())
		{
			pop();
		}
	}
	int get_size() const
	{
		return size;
	}
	T get_front() const
	{
		if (empty())
		{
			throw("List UnderFlow.");
		}
		return f->data;
	}
	T get_rare() const
	{
		if (empty())
		{
			throw("List UnderFlow.");
		}
		return r->data;
	}
	~dlist()
	{
		make_empty();
	}
	void reset_f()
	{
		it = f;
	}
	bool is_last() const
	{
		return it == NULL;
	}
	T get_next_f()
	{
		if (empty())
		{
			throw("List Empty.");
		}
		T v;
		v = it->data;
		it = it->next;
		return v;
	}
	void reset_l()
	{
		it = r;
	}
	bool is_first() const
	{
		return it == NULL;
	}
	T get_next_b()
	{
		if (empty())
		{
			throw("List Empty.");
		}
		T v;
		v = it->data;
		it = it->prev;
		return v;
	}
	void display() const
	{
		if (empty())
		{
			throw("List Underflow.");
		}
		dnode<T>* temp;
		temp = f;
		cout << "List IS:" << endl;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void operator=(const dlist <T>& q)
	{
		if (!empty())
		{
			make_empty();
		}
		size = q.size;
		dnode<T>* temp;
		temp = q.f;
		while (temp != NULL)
		{
			insert(temp->data);
			temp = temp->next;
		}
	}
	dlist(const dlist<T>& d)
	{
		operator=(d);
	}
};
template<typename T>
void display_forward(dlist<T>& l)
{
	cout << "--------------------------------------------------" << endl;
	cout << "Doubly Sorted Linked List in forward direction is:" << endl;
	cout << "--------------------------------------------------" << endl;
	l.reset_f();
	while (!l.is_last())
	{
		cout << l.get_next_f() << " ";
	}
	cout << endl;
	cout << "--------------------------------------------------" << endl;
}
template<typename T>
void display_backward(dlist<T>& l)
{
	cout << "--------------------------------------------------" << endl;
	cout << "Doubly Sorted Linked List in Reverse direction is:" << endl;
	cout << "--------------------------------------------------" << endl;
	l.reset_l();
	while (!l.is_first())
	{
		cout << l.get_next_b() << " ";
	}
	cout << endl;
	cout << "--------------------------------------------------" << endl;
}
int main()
{
	dlist<int> l;
	l.insert(4);
	l.insert(7);
	l.insert(2);
	l.insert(0);
	l.insert(3);
	l.insert(1);
	l.insert(11);
	l.insert(15);
	l.insert(9);
	l.insert(12);
	display_forward(l);
	display_backward(l);
	cout << "front:" << l.get_front() << endl;
	cout << "rear:" << l.get_rare() << endl;
	if (l.update(9, 77))
	{
		cout << "Found." << endl;
	}
	else
	{
		cout << "Not found." << endl;
	}
	display_forward(l);

	cout << "front:" << l.get_front() << endl;
	cout << "rear:" << l.get_rare() << endl;

	dlist<int> l2(l);
	display_forward(l);
	return 0;
}