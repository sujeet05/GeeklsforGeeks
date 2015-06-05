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
bool isBSTreeUtility(struct node*btree,int &min)
{
	if(btree)
	{
		isBSTreeUtility(btree->left,min);
		if(btree->data > min )
				min=btree->data;
		else 
			return false;
		isBSTreeUtility(btree->right,min);
	}
	return true;
}
bool isBSTreeUtility2(struct node *btree, int min,int max)
{
	if(btree)
	{
		if(btree->data < min || btree->data > max)
				return false;
		return isBSTreeUtility2(btree->left,min,(btree->data)-1) && isBSTreeUtility2(btree->right,(btree->data)+1,max);
	}
	return true;
}
bool isBST(struct node *btree)
{
	int min =INT_MIN;
	return  isBSTreeUtility(btree,min);
}
int main()
{
	//root = newnode(4);
	//root->left        = newnode(2);
	//root->right       = newnode(5);
	//root->left->left  = newnode(1);
	//root->left->right = newnode(3);
	   insert( 11);	
	   insert( 2);	
	   insert( 14);	
	   insert( 1);	
	   insert( 7);	
	   insert( 15);	
	   insert( 5);	
	   insert( 8);	
	   insert( 4);	
	if(isBST(root))
			cout << "BST" << endl;
	else
		cout << "Not BST" << endl;
	return 0;
}
