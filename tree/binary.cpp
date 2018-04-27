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
	tree(){root = NULL;}
	tree(int a)
	{
		root->value = a;
		root->left = NULL;
		root->right = NULL;
	}
	void addnode(int,node*);
private:
	node* root;
};

void tree::addnode(int val,node* next)
{
	if(next = NULL)
	{
		next = new node;
		next->value = val;
		next->left = NULL;
		next->right = NULL;
	}
	else
	{
		if(val > next->value) addnode(val,next->right);
		if(val < next->value) addnode(val,next->left);
	}
}

int main()
{
	tree Try();
	return 0;
}
