#include<iostream>
using namespace std;
template<typename T>
struct node
{
	T data;
	node<T>* next;
};
template<typename T>
class circular_queue
{
	node<T> *rear;
	int size;
public:
	circular_queue()
	{
		rear = NULL;
		size = 0;
	}
	void push(const T& val)////////////////////push back
	{
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		if (rear == NULL)
		{
			temp->next = rear;
		}
		else
		{
			if (rear->next == NULL)
			{
				temp->next = rear;
			}
			else
			{
				temp->next = rear->next;
			}
			rear->next = temp;
		}
		rear = temp;
		size++;
	}
	void push_front(const T &val)
	{
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		
		if (rear== NULL)
		{
			temp->next = rear;
			rear = temp;
			
		}
		else
		{
			
			if (rear->next == NULL)
			{
				temp->next = rear;
			}
			else
			{
				temp->next = rear->next;
			}
			
      	    rear->next = temp;
	
		}
		
	}
	void pop()/////////////////////////pop front
	{
		node<T>* to_del;
		if (rear == NULL)
		{
			throw("Queue Overflow.");
		}
		to_del = rear->next;
		if (rear->next == rear->next->next)
		{
			rear->next = NULL;
		}
		else
		{
			rear->next = rear->next->next;
		}
		
	    delete to_del;
		size--;
	}
	void pop_back()
	{
		node<T>* to_del;
		if (rear == NULL)
		{
			throw("Queue Overflow.");
		}
		if (rear->next == NULL)
		{
			rear= NULL;
		}
		else 
		{
			node<T>* temp;
			temp = rear->next;
			while (temp->next != rear)
			{
				temp = temp->next;
			}
			to_del = rear;
			temp->next = rear->next;
			rear = temp;
			delete to_del;
		}

	}
	T get_front() const
	{
		return rear->next->data;
	}
	T get_rear() const
	{
		return rear->data;
	}
	circular_queue(const circular_queue<T>& c)
	{
		operator=(c);
	}
	void operator=(const circular_queue<T>& c)
	{
		if (!empty())
		{
			make_empty();
		}
		node<T>* temp;
		temp = c.rear->next;
		size = c.size;
		while (temp !=c. rear)
		{
			push(temp->data);
			temp = temp->next;
		}
		push(temp->data); 
	}

	void display()
	{
		node<T>* temp;
		temp =rear->next;
		cout << "QUEUE IS:" << endl;
		while (temp!=rear)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
	int get_size() const
	{
		return size;
	}
	~circular_queue()
	{
		make_empty();
	}
	void make_empty()
	{
		rear = NULL;
		size = 0;
	}
	bool empty() const
	{
		return rear == NULL;
	}
	bool full() const
	{
		node<T>* temp;
		temp = new node<T>;
		if (temp==NULL)
		{
			return true;
		}
		else
		{
			delete temp;
			return false;
		}
	}
	
};
int main()
{
	circular_queue<int> q;
	q.push_front(11);
	q.push_front(10);
	q.push(88);
	q.push_front(77777);
	q.push(999);
	q.push(10);
	cout << "-------------------------------------------" << endl;
	q.display();
	cout << "Front:"<<q.get_front() << endl;
	q.pop();
	cout << "Front:"<<q.get_front() << endl;
	cout << "-------------------------------------------" << endl;
	q.push(777);
	q.push(9);
	q.push(10);
	q.display();
	cout << q.get_front() << endl;
	cout << "-------------------------------------------" << endl;
	circular_queue<int>qq;
	qq = q;
	qq.display();
	cout <<"Front:"<< qq.get_front()<<endl;
	cout << "-------------------------------------------" << endl;
	circular_queue<int>qqq(qq);
	qqq.display();
	cout<<"Front:"<<qqq.get_front() << "\nRear:" << qqq.get_rear() << endl;
	cout << "-------------------------------------------" << endl;
	circular_queue<int> sss;
	sss.push_front(888);
	sss.push_front(99999);
	sss.push_front(7777777);
	sss.push(8);
	sss.display();
	cout << "-------------------------------------------" << endl;
	sss.pop();
	sss.display();
	cout << "-------------------------------------------" << endl;
	sss.pop_back();
	sss.display();
	cout << "-------------------------------------------" << endl;
	return 0;
}
