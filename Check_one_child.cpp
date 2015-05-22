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
int count_nodes( struct node* btree)
{
		return (btree)? count_nodes(btree->left)+count_nodes(btree->right)+1:0;
}
bool validate_one_child(struct node *btree)
{
	int count=count_nodes(btree);;
	while(btree)
	{
	   count--;
	   btree = (btree->left) ? btree->left : btree->right;
	}
	return count==0 ? true: false;
}
int main()
{
	insert2(&root,20);
	insert2(&root,22);
	insert2(&root,24);
	insert2(&root,18);
	insert2(&root,19);
	insert2(&root,11);
	insert2(&root,13);
	insert2(&root,12);
	cout << count_nodes(root) << endl;
	cout << "Inorder Traversal... " << endl;
	inorder(root);
	cout << endl;
	bool x = true;
	cout << x<<endl;
    cout<<validate_one_child(root);
	return 0;
}
