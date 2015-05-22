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
void traversal_for_kthsmallest(struct node* btree,int k,int &c)
{
	if(!btree || c >= k)
		return;
	traversal_for_kthsmallest(btree->left,k,c);
	c++;
	if(k==c)
	{	
		cout << "kth smallest element:" << btree->data << endl;
		return;
	}
	traversal_for_kthsmallest(btree->right,k,c);
}
void find_kthsmallestelement(struct node *btree,int k)
{
	int c=0;
	traversal_for_kthsmallest(btree,k,c);
}

void traversal_for_kthlargest(struct node* btree,int k,int &c)
{
	if(!btree || c >= k)
		return;
	traversal_for_kthlargest(btree->right,k,c);
	c++;
	if(k==c)
	{	
		cout << "kth largest element:" << btree->data << endl;
		return;
	}
	traversal_for_kthlargest(btree->left,k,c);
}
void find_kthlargestelement(struct node *btree,int k)
{
	int c=0;
	traversal_for_kthlargest(btree,k,c);
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
	find_kthsmallestelement(root,3);
	find_kthsmallestelement(root,5);
	find_kthlargestelement(root,3);
	find_kthlargestelement(root,5);
	cout << endl;
	return 0;
}
