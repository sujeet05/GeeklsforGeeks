#include<iostream>

using namespace std;

struct list
{
		int data;
		list *next;
		list *random;
}*mylist = NULL;

list* arr_address[5];
list * clonelist = NULL;

void prepare_clone_list()
{
		static int i =0;
		list* traversal = mylist;
		while(traversal != NULL)
		{
				list *_temp = new list;
				_temp->data = traversal->data;
				_temp->random = traversal->random;
				traversal->random = _temp;
				_temp->next = NULL;
				if(clonelist == NULL)
						clonelist = _temp;
				else
				{
						list* traversal_clone = clonelist;
						while(traversal_clone->next != NULL)
								traversal_clone = traversal_clone->next;
						traversal_clone->next = _temp;
				}
				traversal = traversal->next;
		}
		list *mylist_traversal = mylist;
		list *clonelist_traversal = clonelist;
		while(mylist != NULL)
		{
				mylist_traversal->random = clonelist_traversal->random;
				clonelist_traversal->random = clonelist_traversal->random->random;
				mylist = mylist->next;
		}
}

// prepare the list . i mean given list 
void insert(int data)
{
		static int i =0;
		list *_temp = new list;
		_temp->data = data;
		_temp->next = NULL;
		arr_address[i] = _temp;
		i++;
		if(mylist ==NULL)
				mylist = _temp;
		else
		{
				list * traversal = mylist;
				while(traversal->next != NULL)
						traversal = traversal->next;
				traversal->next = _temp;
		}

}

// store the address of random pointer of given list 
void random_node(list* _list)
{
		list * traversal = _list;
		traversal->random = arr_address[2];
		traversal = traversal->next;
		traversal->random =  arr_address[4];
		traversal = traversal->next;
		traversal->random =  arr_address[0];
		traversal = traversal->next;
		traversal->random =  arr_address[1];
		traversal = traversal->next;
		traversal->random =  arr_address[3];

}
// Print the list as random node traversal 
void print_list_random(list *_list)
{
		list * traversal = _list;
		while(traversal != NULL)
		{
				cout << traversal->random->data << "..." << std::endl;
				traversal = traversal->next;
		}
}
//print the node as next node traversal 
void print_list(list * _list)
{
		list * traversal = _list;
		while(traversal != NULL)
		{
				cout << traversal->data << "..." << std::endl;
				traversal = traversal->next;
		}
}
void print_arr_address()
{
		for (int i =0; i <5; i++)
				cout << arr_address[i] << "...."<< std::endl;
}
int main()
{
		insert(25);
		insert(10);
		insert(26);
		insert(6);
		insert(90);
		print_list(mylist);
		//print_arr_address();
		random_node(mylist);
		print_list_random(mylist);
		cout << "....................."<< endl;
		prepare_clone_list();
		print_list(clonelist);
		random_node(clonelist);
		print_list_random(clonelist);

		return 0;
}
