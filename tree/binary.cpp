#include<iostream>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

class tree
{
public:
	tree() { root = NULL; }
	tree(int a)
	{
		root = new node;
		root->value = a;
		root->left = NULL;
		root->right = NULL;
	}
	node* getroot() { return root; }
	void addnode(int, node*&);
	void show(node*);
private:
	node* root;
};

void tree::addnode(int val, node*& next)
{
	if (NULL == next)
	{
		next = new node;
		next->value = val;
		next->left = NULL;
		next->right = NULL;
	}
	else
	{
		if (val > next->value) return addnode(val, next->right);
		if (val < next->value) return addnode(val, next->left);
	}
}

void tree::show(node* next)
{
	if (next)
	{
		show(next->left);
		cout << next->value << " ";
		show(next->right);
	}
}

int main()
{
	tree first(10);
	int a = 1;
	node* Root = first.getroot();
	while (cin >> a)
	{
		first.addnode(a, Root);
	}
	first.show(Root);
	system("pause");
	return 0;
}
