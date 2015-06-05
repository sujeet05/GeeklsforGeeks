#include<iostream>
#include<stack>
#include<algorithm>
#include <limits.h>

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
struct node * TreeMinimum(struct node* btree)
{
		while(btree->left)
		 btree= btree->left;
		return btree;
}

struct node * TreeMinimum2(struct node* btree)
{
	  if(!(btree->left)) return btree;
	  return TreeMinimum(btree->left);
}
struct node * TreeMaximum(struct node* btree)
{
		while(btree->right)
		 btree= btree->right;
		return btree;
}
struct node * TreeMaximum2(struct node* btree)
{
	  if(!(btree->right)) return btree;
	  return TreeMaximum2(btree->right);
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
struct node * getparent(int key)
{
		if(!root || root->data == key) return NULL;
		else
		{
			struct node *_ret = NULL;
			struct node * traversal = root;
			while(traversal)
			{
				_ret = traversal;
				traversal = (traversal->data >key) ? traversal->left : traversal->right;
				if(traversal->data == key)
				return _ret;
			}
		}
		return NULL;
}
struct node * Successor(int key)
{
		if(!root)
		return NULL;
		struct node *find = findelement(key);
		if(find)
		{
			if(find->right) 
			 return TreeMinimum(find->right);
			struct node *ancestor = getparent(key);
			while(ancestor && find ==ancestor->right)
			{
				find = ancestor;
				ancestor = getparent(find->data);
			}
			return ancestor;
		}
			return NULL;
}
void inorder_alternate(struct node *btree,int number)
{
	struct node *tree_min = TreeMinimum(btree);
	for(int i=0;i<number;i++)
	{
			if(tree_min)
			{
				std::cout << tree_min->data << "...";
				tree_min = Successor(tree_min->data);
			}
	}
}
struct node* Predecessor(int key)
{
		if(!root)
		return NULL;
		struct node *find = findelement(key);
		if(find)
		{
			if(find->left)
			 return TreeMaximum(find->left);
			struct node *ancestor = getparent(key);
			while(ancestor && find == ancestor->left)
			{
				find = ancestor;
				ancestor = getparent(find->data);
			}
			return ancestor;
		}
		return NULL;
}
void Transplant(struct node **btree,struct node *u, struct node *v)
{
	struct node *Uparent = NULL;
	struct node *Vparent = NULL;
	if(u)
		 Uparent= getparent(u->data);
	if(v)
		 Vparent= getparent(v->data);
	if(!Uparent)
		*btree = v;
	else if (u==Uparent->left)
		Uparent->left = v;
	else
		Uparent->right =v;
	
}
void Delete(struct node **btree,struct node * _deletenode)
{
	if(_deletenode)
	{
		if(!(_deletenode->left)) //No left child of deleted node handle two case 1. no left child 2. leaf node 
			Transplant(btree,_deletenode,_deletenode->right);
		else if(!(_deletenode->right))
			Transplant(btree,_deletenode,_deletenode->left);
		else
		{
			struct node *successornode = Successor(_deletenode->data);
			if(successornode)
			{
				if(_deletenode->right != successornode)
				{
					 Transplant(btree,successornode,successornode->right);
					 successornode->right = _deletenode->right;
					 _deletenode->right = successornode;
				}
		        Transplant(btree,_deletenode,successornode);
				successornode->left = _deletenode->left;
			}
		}
	}
	delete _deletenode;
}
int Least_common_incesstor(struct node *btree,int key1,int key2)
{
		struct node * traversal = btree;
		bool found =false;
		int ancesstor = traversal->data;
		while(traversal && !found)
		{
			if(ancesstor > key1 && ancesstor > key2 )
					traversal = traversal->left;
			else if( ancesstor < key1 && ancesstor < key2) 
					traversal = traversal->right;
			else 
					found = true;
			ancesstor = traversal->data;
		}
		struct node *second =NULL;
		if(found)
		second = ancesstor==key1 ? findelement(key2) : findelement(key1);
		if(found && second && traversal) return  traversal->data;
		else return -1;	
					
}
struct node * lca(struct node *btree,int key1,int key2)
{
		if(!btree) return btree;
		if(btree->data > key1 && btree->data > key2)
				return lca(btree->left,key1,key2);
		 else if(btree->data < key1 && btree->data < key2)
				return lca(btree->right,key1,key2);
		else
			return btree;
}
struct node * findelement_subtree(struct node *btree,int key)
{
		if(!btree) return btree;
		if(key > btree->data)
			return	findelement_subtree(btree->right,key);
		else if( key < btree->data)
				return findelement_subtree(btree->left,key);
		else
				return btree;
}
int lca_validation(struct node *btree,int key1,int key2)
{
		struct node *root = lca(btree,key1,key2);
		struct node *f1 = findelement_subtree(root,key1);
		struct node *f2 = findelement_subtree(root,key2);
		return (f1 && f2) ? root->data : -1;
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

bool isBST(struct node* p, int min, int max)
{
		if(p)
		{
				return isBST(p->left, min, p->data)
						&& isBST(p->right, p->data, max)
						&& p->data >= min && p->data <= max;
		}
		else return true;
}
int main()
{
	insert2(&root,11);
//	insert2(&root,2);
//	insert2(&root,14);
//	insert2(&root,1);
//	insert2(&root,7);
//	insert2(&root,15);
//	insert2(&root,5);
//	insert2(&root,8);
//	insert2(&root,4);
//	root->left->left->left = newnode(10);
#if 0
	find_kthsmallestelement(root,3);
	find_kthsmallestelement(root,5);
	find_kthlargestelement(root,3);
	find_kthlargestelement(root,5);
	reverse_inorder(root);
	cout << "Least common incesstor 4 and 12 :" << Least_common_incesstor(root,4,12) << endl;
	cout <<  "Least common incesstor 14 and 20 :" << Least_common_incesstor(root,14,20) << endl;
	cout << "Least common incesstor 14 and 10 :" << Least_common_incesstor(root,14,10) << endl;
	cout << "Least common incesstor 22 and 12 :" << Least_common_incesstor(root,22,12) << endl;
	cout << "Least common incesstor 20 and 12 :" << Least_common_incesstor(root,20,12) << endl;
	cout << "Least common incesstor 6 and 12 :" << Least_common_incesstor(root,6,12) << endl;
	cout << "Least common incesstor 6 and 8 :" << Least_common_incesstor(root,6,8) << endl;
	cout << "second method for lca testing .. " << endl;
	cout << "Least common incesstor 4 and 12 :" << lca_validation(root,4,12) << endl;
	cout <<  "Least common incesstor 14 and 20 :" << lca_validation(root,14,20) << endl;
	cout << "Least common incesstor 14 and 10 :" << lca_validation(root,14,10) << endl;
	cout << "Least common incesstor 22 and 12 :" << lca_validation(root,22,12) << endl;
	cout << "Least common incesstor 20 and 12 :" << lca_validation(root,20,12) << endl;
	cout << "Least common incesstor 6 and 12 :" << lca_validation(root,6,12) << endl;
	cout << "Least common incesstor 6 and 8 :" << lca_validation(root,6,8) << endl;
#if 0
	insert2(&root,15);
	insert2(&root,6);
	insert2(&root,3);
	insert2(&root,2);
	insert2(&root,4);
	insert2(&root,7);
	insert2(&root,13);
	insert2(&root,9);
	insert2(&root,18);
	insert2(&root,17);
	insert2(&root,20);
#endif
#if 0	
	insert(15);
	insert(6);
	insert(3);
	insert(2);
	insert(4);
	insert(7);
	insert(13);
	insert(9);
	insert(18);
	insert(17);
	insert(20);
#endif 
	cout << "Inorder Traversal Alternate... " << endl;
	inorder_alternate(root,11);
	cout << "Inorder Traversal... " << endl;
	inorder(root);
	cout << "Prerder Traversal... " << endl;
	preorder(root);
	cout << "Postorder Traversal... " << endl;
	postorder(root);
	cout << endl;
#endif
	cout << isBST(root, INT_MIN, INT_MAX) << endl;
	return 0;
}
