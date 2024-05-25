#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
struct bnode
{
	T data;
	bnode<T>* left,*right;
};
template<typename T>
class BST
{
	bnode<T>* root;
	queue<T>l_q;
	stack<T>s;
	int n;
public:
	BST()
	{
		root = NULL;
		n = 0;
	}
	void insert(const T& val)
	{
		bnode<T>* temp;
		temp = new bnode<T>;
		temp->data = val;
		temp->right = temp->left = NULL;
		if (root == NULL)
		{
			root = temp;
			n++;
		}
		else
		{
			bnode<T>* scan;
			scan = root;
			while (true)
			{
				if (val < scan->data)
				{
					if (scan->left == NULL)
					{
						scan->left = temp;
						n++;
						break;
					}
					else
					{
						scan = scan->left;
					}
				}
				else if (val > scan->data)
				{
					if (scan->right == NULL)
					{
						scan->right= temp;
						n++;
						break;
					}
					else
					{
						scan = scan->right;
					}
				}
				else
				{
					throw("Duplicate Values.");
					break;
				}
			}
		}
	}
	bool find(const T &val)
	{
		bnode<T>* scan;
		scan = root;
		while (scan != NULL)
		{
			if (val < scan->data)
			{
				if (scan->left == NULL)
				{
					return false;
				}
				else
				{
					scan = scan->left;
				}
			}
			else if (val > scan->data)
			{
				if (scan->right == NULL)
				{
					return false;
				}
				else
				{
					scan = scan->right;
				}
			}
			else if (val == scan->data)
			{
				return true;
			}
		}
		return false;
	}
	bool erase(const T& val)
	{
		bnode<T>*scan,*prev;
		prev = NULL;
		scan = root;
		while (true)
		{
			if (val < scan->data)
			{
				if (scan->left == NULL)
				{
					return false;
				}
				else
				{
					prev = scan;
					scan = scan->left;
				}
			}
			else if (val > scan->data)
			{
				if (scan->right == NULL)
				{
					return false;
				}
				else
				{
					prev = scan;
					scan = scan->right;
				}
			}
			else if (val == scan->data)
			{
				if (scan->right == NULL && scan->left == NULL)
				{
					bnode<T>* to_del;
					to_del = scan;
					if (prev == NULL)
					{
						to_del = scan;
						root = NULL;
						delete to_del;
						n--;
						return true;
					}
					if (prev->right == scan)
					{
						prev->right = NULL;
					}
					else if (prev->left == scan)
					{
						prev->left =NULL;
					}
					delete to_del;
					n--;
					return true;
				}
				else if (scan->right == NULL)
				{

					bnode<T>* to_del;
					to_del = scan;
					if (prev == NULL)
					{
						root = scan->left;
						delete to_del;
						n--;
						return true;
					}
					if (prev->right == scan)
					{
						prev->right = scan->left;
					}
					else if(prev->left==scan)
					{
						prev->left = scan->left;
					}
					delete to_del;
					n--;
					return true;
				}
				else if (scan->left == NULL)
				{

					bnode<T>*to_del;
					to_del = scan;
					if (prev == NULL)
					{
						root = scan->right;
						delete to_del;
						n--;
						return true;
					}
					if (prev->right == scan)
					{
						prev->right = scan->right;
					}
					else if (prev->left == scan)
					{
						prev->left = scan->right;
					}
					delete to_del;
					n--;
					return true;
				}
				else
				{
					T prec_val = prec(scan);
					bnode<T>* temp;
					temp = scan;
					while (true)
					{
						if (prec_val < temp->data)
						{
								prev = temp;
								temp = temp->left;
						}
						else if (prec_val > temp->data)
						{
							prev = temp;
						     temp = temp->right;
	
						}
						else if (prec_val == temp->data)
						{
							if (temp->right == NULL && temp->left == NULL)
							{
								bnode<T>* to_del;
								to_del = temp;
								if (prev->right == temp)
								{
									prev->right = NULL;
								}
								else if (prev->left == temp)
								{
									prev->left = NULL;
								}
								delete to_del;
								n--;
								break;
							}
							else if (temp->right== NULL)
							{

								bnode<T>* to_del;
								to_del = temp;
								if (prev->right == temp)
								{
									prev->right = temp->left;
								}
								else if (prev->left == temp)
								{
									prev->left = temp->left;
								}
								delete to_del;
								n--;
								break;
							}
						}
					}	
					scan->data = prec_val;
					return true;
				}
				
			}
		}
		return false;
	}
	T prec(bnode<T>*tree)
	{
		bnode<T>* temp;
		temp = tree->left;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp->data;
	}
	bool update(const T& val,const T &u_val)
	{
		bnode<T>* scan;
		scan = root;
		while (scan != NULL)
		{
			if (val < scan->data)
			{
				if (scan->left == NULL)
				{
					return false;
				}
				else
				{
					scan = scan->left;
				}
			}
			else if (val > scan->data)
			{
				if (scan->right == NULL)
				{
					return true;
				}
				else
				{
					scan = scan->right;
				}
			}
			else if (val == scan->data)
			{
				erase(val);
				insert(u_val);
				return true;
			}
		}
		return false;
	}
	void level_order()
	{
		if (!l_q.empty())
		{
			while (!l_q.empty())
			{
				l_q.pop();
			}
		}
		queue<bnode<T>*>q;
		if (root != NULL)
		{
			q.push(root);
		}
		while (!q.empty())
		{
			bnode<T>* temp;
			temp = q.front();
			q.pop();
			l_q.push(temp->data);
			if (temp->left != NULL)
			{
				q.push(temp->left);
			}
			if (temp ->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
	void level_order_reverse()
	{
		if (!s.empty())
		{
			while (!s.empty())
			{
				s.pop();
			}
		}
		queue<bnode<T>*>q;
		if (root != NULL)
		{
			q.push(root);
		}
		while (!q.empty())
		{
			bnode<T>* temp;
			temp = q.front();
			q.pop();
			s.push(temp->data);
			if (temp->left != NULL)
			{
				q.push(temp->left);
			}
			if (temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
	void reset()
	{
		if (root == NULL)
		{
			throw("BST underflow.");
		}
		if (!l_q.empty())
		{
			while (!l_q.empty())
			{
				l_q.pop();
			}
		}
		level_order();
	}
	bool is_last() const
	{
		return l_q.empty();
	}
	T get_next()
	{
		T val;
		val = l_q.front();
		l_q.pop();
		return val;
	}
	~BST()
	{
		clear();
	}
	void clear()
	{
		if (root != NULL)
		{
			if (!s.empty())
			{
				while (!s.empty())
				{
					s.pop();
				}
			}
			level_order_reverse();
			while (!s.empty())
			{
				erase(s.top());
				s.pop();
			}
		}
		
	}
	bool empty() const
	{
		return root == NULL;
	}
	void operator=(BST<T>&b)
	{
		if (!empty())
		{
			clear();
		}
		b.level_order();
		while (!b.l_q.empty())
		{
			insert(b.l_q.front());
			b.l_q.pop();
		}
	}
	BST(BST<T>& b)
	{
		operator=(b);
	}
};
template<typename T>
void display(BST<T>&b)
{
	if (b.empty())
	{
		throw("BST underflow.");
	}
	b.reset();
	cout << "--------------------------------------------" << endl;
	cout << "Binary Search Tree Values are:" << endl;
	cout << "--------------------------------------------" << endl;




	while (!b.is_last())
	{
		cout << b.get_next() << " ";
	}
	cout << endl;
}
int main()
{
	BST<int>b;
	b.insert(50);
	b.insert(20);
	b.insert(70);
	b.insert(10);
	b.insert(35);
	b.insert(30);
	b.insert(55);
	b.insert(80);
	b.insert(60);
	display(b);
	

	BST<int>bb;
	bb = b;
	display(bb);

	BST<int>bbb(bb);
	display(bbb);

	if (bbb.find(777))
	{
		cout << "Found Successfully." << endl;
		display(bbb);
	}
	else
	{
		cout << "Not found." << endl;
	}
	if (bbb.update(50,11))
	{
		cout << "Updated Successfully." << endl;
		display(bbb);
	}
	else
	{
		cout << "Not found." << endl;
	}

	if (bbb.erase(60))
	{
		cout << "Erased Successfully." << endl;
		display(bbb);
	}
	else
	{
		cout << "Not found." << endl;
	}

}