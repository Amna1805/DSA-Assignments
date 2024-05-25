#include<iostream>
using namespace std;
template<typename T>
struct node
{
	T data;
	node<T>* next;
};
template<typename T>
class list
{
	node<T>* rear, * it;
	int size;
public:
	list()
	{
		rear = NULL;
		it = NULL;
		size = 0;
	}
	void insert(const T& val)
	{
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		temp->next = NULL;
		if (rear == NULL)
		{
			rear = temp;
			rear->next = rear;
		}
		else
		{
			if (val >= rear->data)
			{
				if (rear->next == rear)
				{
					temp->next = rear;
				}
				else
				{
					temp->next = rear->next;
				}
				rear->next = temp;
				rear = temp;
			}
			else if (val <= rear->next->data)
			{
				temp->next = rear->next;
				rear->next = temp;
			}
			else
			{
				node<T>* c, * p;
				c = rear->next;
				p = NULL;
				while (c != rear)
				{
					if (c->data > val)
					{
						p->next = temp;
						temp->next = c;
						break;
					}
					else
					{
						p = c;
						c = c->next;
					}
				}
				if (c->data > val)
				{
					p->next = temp;
					temp->next = c;
				}
			}
		}
		size++;

	}
	void pop()
	{
		node<T>* to_del;
		if (rear == NULL)
		{
			throw("Queue Overflow.");
		}
		to_del = rear->next;
		if (to_del == rear)
		{
			rear = NULL;
		}
		else
		{
			rear->next = rear->next->next;
		}
		delete to_del;
		size--;
	}
	bool remove(const T& val)
	{
		node<T>* prev, * curr, * to_del;
		prev = NULL;
		if (rear->next == rear)
		{
			curr = rear;
		}
		else
		{
			curr = rear->next;
		}

		while (prev != rear)
		{
			if (curr->data == val)
			{
				to_del = curr;
				if (prev == NULL)
				{
					if (curr->next == rear)
					{
						rear = NULL;
					}
					else
					{
						rear->next = curr->next;
					}
				}
				else
				{
					if (curr->next == rear->next)
					{
						prev->next = rear->next;
						rear = prev;
					}
					else
					{
						prev->next = curr->next;
					}
				}
				delete to_del;
				return true;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
		size--;
		return false;
	}
	bool update(const T& v, const T& u_v)
	{
		node<T>* temp;
		temp = rear->next;
		while (temp != rear)
		{
			if (temp->data == v)
			{
				remove(temp->data);
				insert(temp->data = u_v);
				return true;
			}
			temp = temp->next;
		}
		if (temp->data == v)
		{
			temp->data = u_v;
			return true;
		}
		return false;
	}
	bool find(const T& val)
	{
		node<T>* temp;
		temp = rear->next;
		bool check = false;
		while (temp != rear)
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
		if (temp->data == val)
		{
			return true;
		}
		return false;
	}

	T get_front() const
	{
		if (rear->next == rear)
		{
			return rear->data;
		}
		else
		{
			return rear->next->data;
		}
	}
	T get_rear() const
	{
		return rear->data;
	}
	list(const list<T>& l)
	{
		operator=(l);
	}
	void operator=(const list<T>& l)
	{
		if (!empty())
		{
			make_empty();
		}
		node<T>* temp;
		temp = l.rear->next;
		size = l.size;
		if (l.check_only_node())
		{
			insert(temp->data);
		}
		else
		{
			while (temp != l.rear)
			{
				insert(temp->data);
				temp = temp->next;
			}
			insert(temp->data);
		}

	}
	void reset()
	{
		if (rear->next == rear)
		{
			it = rear;
		}
		else
		{
			it = rear->next;
		}

	}
	bool is_last() const
	{
		return it == rear;

	}
	bool check_only_node()const
	{
		return rear->next == rear;
	}
	T get_next()
	{
		T v;
		v = it->data;
		it = it->next;
		return v;
	}
	int get_size() const
	{
		return size;
	}
	~list()
	{
		while (!empty())
		{
			pop();
		}
	}
	bool empty() const
	{
		return rear == NULL;
	}
	bool full() const
	{
		node<T>* temp;
		temp = new node<T>;
		if (temp == NULL)
		{
			return true;
		}
		else
		{
			delete temp;
			return false;
		}
	}
	void make_empty()
	{
		while (!empty())
		{
			pop();
		}
	}
};
template<typename T>
void display(list <T>& l)
{
	if (l.empty())
	{
		throw("List empty.");
	}
	l.reset();
	cout << "Circular Sorted List in forward direction is:" << endl;
	if (l.check_only_node())
	{
		cout << l.get_next() << endl;
	}
	else
	{
		while (!l.is_last())
		{
			cout << l.get_next() << " ";
		}
		cout << l.get_next() << " " << endl;
	}

}
int main()
{
	list<int>l;
	l.insert(4);
	l.insert(7);
	l.insert(2);
	l.insert(0);
	l.insert(3);
	l.insert(1);
	l.insert(11);
	display(l);
	if (l.remove(4))
	{
		cout << "Found and Removed Successfully." << endl;
	}
	else
	{
		cout << "Not found." << endl;
	}
	cout << "front:" << l.get_front() << endl;
	cout << "rear:" << l.get_rear() << endl;
	if (l.update(3, 67))
	{
		cout << "Found and updated Successfully." << endl;
	}
	else
	{
		cout << "Not found." << endl;
	}
	display(l);
	cout << "Copy Constructor:" << endl;
	list<int> l2(l);
	display(l2);
	cout << "Assignement operator:" << endl;
	list<int> l3;
	l3 = l2;
	display(l3);
}