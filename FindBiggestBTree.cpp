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
	int max =INT_MAX;
	return  isBSTreeUtility2(btree,min,max);
}
struct node *Find_Biggest_Btree_utility(struct node* btree,int &size)
{
	if(btree)
	{
		 Find_Biggest_Btree_utility(btree->left,size);
	 	 Find_Biggest_Btree_utility(btree->right,size);
		 struct node* _ret = NULL;
		if(isBST(btree->left) && isBST(btree->right))
		{
			size+=1;
			_ret = btree;
		}
	}
}
struct node *Find_Biggest_Btree(struct node* btree)
{
	if(!btree) return NULL;
	int size =0;
	return Find_Biggest_Btree_utility(btree,size);
}
int main()
{
	bool x= true;
	cout << x;
	root = newnode(50);
	root->left        = newnode(10);
	root->right       = newnode(60);
	root->left->left  = newnode(5);
    root->left->right = newnode(20);
	root->right->left  = newnode(55);
	root->right->left->left  = newnode(45);
	root->right->right = newnode(70);
	root->right->right->left = newnode(65);
	root->right->right->right = newnode(80);
	cout <<"check tree is BST:" <<isBST(root)<< endl;
	cout << "Find Biggest Btree root:" << Find_Biggest_Btree(root)->data << endl;
	return 0;
}
