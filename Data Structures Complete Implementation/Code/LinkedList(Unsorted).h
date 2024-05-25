#include<iostream>
using namespace std;
template<typename T>
struct dnode_unsorted
{
	T data;
	dnode_unsorted<T>* prev, * next;
};
template<typename T>
class dlist_unsorted
{
	dnode_unsorted<T>* f, * r;
	dnode_unsorted<T>* it;
	int size;
public:
	dlist_unsorted()
	{
		f = r = NULL;
		it = NULL;
		size = 0;
	}
	void push_back(const T& val)
	{
		dnode_unsorted<T>* temp;
		temp = new dnode_unsorted<T>;
		temp->data = val;
		temp->next = NULL;
		if (f == NULL)
		{
			temp->prev = NULL;
			f = r = temp;

		}
		else
		{
			temp->prev = r;
			temp->prev->next = temp;//rare->next=temp;
			r = temp;

		}


	}
	void push_front(const T& val)
	{
		dnode_unsorted<T>* temp;
		temp = new dnode_unsorted<T>;
		temp->data = val;
		if (f == NULL)
		{
			temp->next = temp->prev = NULL;
			f = r = temp;
		}
		else
		{
			temp->next = f;
			temp->next->prev = temp;//f->next=temp;
			f = temp;
		}
		temp->prev = NULL;
	}
	void pop_front()
	{
		dnode_unsorted<T>* temp;
		temp = f;
		if (f->next == NULL)
		{
			r = f = NULL;
		}
		else
		{
			f->next->prev = NULL;
			f = f->next;
		}

		delete temp;
	}
	void pop_back()
	{
		dnode_unsorted<T>* temp;
		temp = r;
		if (r->prev == NULL)
		{
			r = f = NULL;
		}
		else
		{
			r->prev->next = NULL;
			r = r->prev;
		}

		delete temp;
	}
	bool empty() const
	{
		return r == NULL;
	}
	void make_empty()
	{
		while (!empty())
		{
			pop_front();
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
	~dlist_unsorted()
	{
		make_empty();
	}
	void display() const
	{
		if (empty())
		{
			throw("List Underflow.");
		}
		dnode_unsorted<T>* temp;
		temp = f;
		cout << "List IS:" << endl;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void operator=(const dlist_unsorted <T>& q)
	{
		if (!empty())
		{
			make_empty();
		}
		size = q.size;
		dnode_unsorted<T>* temp;
		temp = q.f;
		while (temp != NULL)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}
	dlist_unsorted(const dlist_unsorted<T>& d)
	{
		operator=(d);
	}
	bool is_erase_all(const T& v)
	{
		dnode_unsorted<T>* temp_t;
		temp_t = f;
		dnode_unsorted<T>* temp;
		dnode_unsorted<T>* to_del;
		temp = f;
		bool check = false;
		while (temp != NULL)
		{
			//temp = f;
			if (temp->data == v)
			{
				if (temp->next == NULL)
				{
					if (temp->prev == NULL)
					{
						r = f = NULL;
						temp = NULL;
					}
					else
					{

						temp->prev->next = NULL;
						r = temp->prev;

					}
				}
				else
				{
					if (temp->prev == NULL)
					{
						temp->next->prev = NULL;
						f = temp->next;
					}
					else
					{
						temp->next->prev = temp->prev;
						temp->prev->next = temp->next;
					}
				}
				check = true;
			}
			temp = temp->next;

		}
		return check;
	}
	bool is_erase(const T& v)
	{
		dnode_unsorted<T>* temp;
		temp = f;
		while (temp != NULL)
		{
			if (temp->data == v)
			{
				if (temp->next == NULL)
				{
					if (temp->prev == NULL)
					{
						r = f = NULL;
					}
					else
					{

						temp->prev->next = NULL;
						r = temp->prev;

					}
				}
				else
				{
					if (temp->prev == NULL)
					{
						temp->next->prev = NULL;
						f = temp->next;
					}
					else
					{
						temp->next->prev = temp->prev;
						temp->prev->next = temp->next;
					}
				}
				delete temp;
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
		dnode_unsorted<T>* temp;
		temp = f;
		while (temp != NULL)
		{
			if (temp->data == v)
			{
				temp->data = u_v;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool find(const T& v)
	{
		dnode_unsorted<T>* temp;
		temp = f;
		while (temp != NULL)
		{
			if (temp->data == v)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool update_all(const T& v, const T& u_v)
	{
		dnode_unsorted<T>* temp;
		temp = f;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->data == v)
			{
				temp->data = u_v;
				check = true;
			}
			temp = temp->next;
		}
		return check;
	}
	void reset()
	{
		it = f;
	}
	bool is_last()
	{
		return it == NULL;
	}
	T get_next()
	{
		T v;
		v = it->data;
		it = it->next;
		return v;
	}
}; 
