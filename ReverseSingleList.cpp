#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=NULL;
void display()
{
	struct node *traversal = head;
	while(traversal)
		{
			cout << traversal->data << "...";
			traversal = traversal->next;
		}
	cout << endl;
}
struct node* search(struct node *list,int key)
{
	struct node *traversal = head;
	while(traversal != NULL)
		{
				if(traversal->data ==key)
				return traversal;
				traversal= traversal->next;
		}
	return traversal;
}
void insertBegining(struct node *list,int key)
{
		struct node* temp = new struct node;
	    temp->data = key;
		temp->next = head;
		head = temp;
			
}

void insertEnd(struct node *list,int key)
{
		struct node* temp = new struct node;
	    temp->data = key;
		temp->next = NULL;
		struct node *traversal = head;
		if(!traversal) head = temp;
		else
		{
			while(traversal->next!= NULL)
			traversal = traversal->next;
			traversal->next = temp;
		}
}
struct node * remove(struct node *list,int key)
{
 	struct node *traversal = head;
 	struct node *del= NULL;
	if(traversal)
	{
		if(traversal->data == key) 
		{
			del = traversal;
		 	head = traversal->next;
		}
		else 
		{
				while(traversal->next != NULL)
					{
						if(traversal->next->data == key)
						{
						   del = traversal->next;
						   traversal->next = traversal->next->next;
						}
						else
						traversal = traversal->next;
					}
		}
		return del;
	}
	else
 	  return NULL;
}
struct node * reverse_recursive(struct node **list)
{
	struct node *rev;
	if(!(*list) || !((*list)->next)) return *list;
	rev= reverse_recursive(&((*list)->next));
	(*list)->next->next = *list;
	(*list)->next = NULL;
	return rev;
}
void reverse(struct node **list)
{
	   if(list)
	   {

			struct node *_previous =NULL;
			struct node *_current = *list;
			struct node * _next = NULL;
			while(_current)
			{
				_next = _current->next;
				_current->next = _previous;
				_previous = _current;
				_current =_next;

			}
			*list = _previous;
#if 0
		   	same logic above in more elagant manner
			struct node *_next = _current->next;
			while(_next)
			{
				_previous = _current;
				_current = _next;
				_next = _next->next;
				_current->next=_previous;
				if(_previous ==*list)
					_previous->next = NULL;
			}
			_current->next =_previous;
		*list = _current;
#endif 
	   }
}
int main()
{
  int option;
  int data;
  while(1)
  {
		  cout << "Enter 1 for insert at Beginning" << endl;
		  cout << "Enter 2 for insert at End" << endl;
		  cout << "Enter 3 for search " << endl;
		  cout << "Enter 4 for Remove " << endl;
		  cout << "Enter 5 for show " << endl;
		  cout << "Enter 6 for Reverse " << endl;
		  cout << "Enter 7 for Reverse with count " << endl;
		  cout << "Enter 10 for Exit " << endl;
		  cin >> option;
		  switch(option)
		  {
			case 1: 
				cout << "Enter data for Beginning Insertion" << endl;
				cin >> data;
				insertBegining(head,data);
				break;
			case 2:
				cout << "Enter data for End Insertion " << endl;
				cin >> data;
				insertEnd(head,data);
				break;
			case 3:
				cout << "Enter data for  search " << endl;
				cin >> data;
				cout << "Searched Result: " << search(head,data);
				break;
			case 4:
				cout << "Enter data for remove " << endl;
				cin >> data;
				cout << "Removed Element: " << remove(head,data);
				break;
			case 5:
				display();
				break;
			case 6:
				  head= reverse_recursive(&head);
				  display();
				break;
			case 7:
				 int n;
				insertBegining(head,10);
				insertBegining(head,20);
				insertBegining(head,30);
				insertBegining(head,40);
				insertBegining(head,50);
				insertBegining(head,60);
				insertBegining(head,70);
				insertBegining(head,80);
				insertBegining(head,90);
				 display();
				 cin >> n;
				  reverse_recursive_count(&head,n,true);
				 display();
				 break;
			case 10:
				cout << "Thank you: " << endl;
				 exit(0);
		  }
  }
  return 0;
}
