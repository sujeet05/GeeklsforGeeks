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
void reverse_inorder(struct node *btree)
{
	if(btree)
	{
		reverse_inorder(btree->right);
		cout << btree->data << "...";
		reverse_inorder(btree->left);
	}
}
struct node *findelement(int key)
{
	struct node * traversal = root;
	while(traversal)
	{
		if(traversal->data ==key)
				return traversal;
		traversal = (traversal->data >key) ? traversal->left : traversal->right;
	}
		return NULL;
}
struct node* findelement2(struct node *btree,int key)
{
	   if( !btree || btree->data ==key) return btree;
      	return (btree->data >key) ? findelement2(btree->left,key):findelement2(btree->right,key);
}
struct node *getroot()
{
		return root;
}
void find_pair(struct node* btree,int sum,bool &found)
{
	if(btree)
	{
		find_pair(btree->left,sum,found);
		struct node *temp = findelement2(getroot(),sum-btree->data);
		if(temp) found = true; 
		find_pair(btree->right,sum,found);
	}
}
int main()
{
	root =  newnode(15);
	root->left = newnode(10);
	root->right = newnode(20);
	root->left->left = newnode(8);
	root->left->right = newnode(12);
	root->right->left = newnode(16);
	root->right->right = newnode(25);
	inorder(root);
	cout << endl;
	int target = 33;
	bool found = false;
    find_pair(root,target,found);
	cout << found << endl;
	target = 28;
	found = false;
    find_pair(root,target,found);
	cout << found << endl;
	found = false;
	target = 36;
    find_pair(root,target,found);
	cout << found << endl;
	found = false;
	target = 42;
    find_pair(root,target,found);
	cout << found << endl;
	return 0;
}
