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

void preorder(struct node *btree)
{
	if(btree)
	{
		cout << btree->data << "...";
		preorder(btree->left);
		preorder(btree->right);
	}
}

void postorder(struct node *btree)
{
	if(btree)
	{
		postorder(btree->left);
		postorder(btree->right);
		cout << btree->data << "...";
	}

}
void print_in_range(struct node *btree,int k1,int k2)
{
	if(btree)
	{
		print_in_range(btree->left,k1,k2);
		if( btree->data > k1 && btree->data < k2)
			cout << btree->data << "...";
		print_in_range(btree->right,k1,k2);
	}
}
int main()
{
	insert2(&root,20);
	insert2(&root,8);
	insert2(&root,22);
	insert2(&root,4);
	insert2(&root,12);
	insert2(&root,10);
	insert2(&root,14);
	inorder(root);
	cout << endl;
	print_in_range(root,4,14);
	cout << endl;
	return 0;
}
