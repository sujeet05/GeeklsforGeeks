#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

struct node 
{
	struct node * left;
	struct node * right;
	int data;
}*root =NULL ;

struct node * newnode(int key)
{
	struct node* create= new struct node;
	create->left = NULL;
	create->right =NULL;
	create->data = key;
	return create;
}
void insert(int data)
{
	struct node* cr = newnode(data);
	if(!root)
			root=cr;
	else
	{
		struct node* traversal =root;
		struct node* parent =NULL;
		while(traversal)
		{
			    parent = traversal;
				traversal = (traversal->data > data) ? traversal->left : traversal->right;
		}
		if (parent->data >data) 
				 parent->left = cr;
	    else	
			     parent->right =cr;
	}
}
void insert2(struct node** btree,int key)
{
		if(!*btree)
				*btree = newnode(key);
		else
			((*btree)->data >key) ? insert2(&((*btree)->left),key):insert2(&((*btree)->right),key);
}
void inorder(struct node *btree)
{
	if(btree)
	{
		inorder(btree->left);
		cout << btree->data << "...";
		inorder(btree->right);
	}
}

void inorder_sum(struct node* btree,int &sum)
{
	if(btree)
	{
		inorder_sum(btree->right,sum);
		sum+= btree->data;
		btree->data=sum-btree->data;
		inorder_sum(btree->left,sum);
	}
}
int main()
{
	 root = newnode(11);
	 root->left = newnode(2);
     root->right = newnode(29);
	 root->left->left = newnode(1);
	 root->left->right = newnode(7);
	 root->right->left = newnode(15);
	 root->right->right = newnode(40);
	 root->right->right->left = newnode(35);
	cout << "Inorder Traversal... " << endl;
	inorder(root);
	cout << endl;
	int x=0;
	inorder_sum(root,x);
	cout << endl;
	inorder(root);
	return 0;
}
