#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=NULL;
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
void BuildList(struct node *list)
{
	insertBegining(list,10);
	insertBegining(list,20);
	insertBegining(list,30);
	insertBegining(list,40);
	insertBegining(list,50);
	insertBegining(list,60);
	insertBegining(list,70);
	insertBegining(list,80);
	search(list,10)->next = search(list,30);
}
struct node * findloop(struct node *list)
{
	struct node *slow = list;
	struct node *fast = list->next;
	while(fast != slow)
	{
		fast= fast->next->next;
		slow = slow->next;
	}
	return slow;
}
int main()
{
  BuildList(head);
  cout << findloop(head)->data << endl;
  return 0;
}
