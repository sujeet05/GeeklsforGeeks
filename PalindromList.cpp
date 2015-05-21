#include<iostream>
#include<stack>
#include<algorithm>

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

struct node * reverse_recursive(struct node **list)
{
	struct node *rev;
	if(!(*list) || !((*list)->next)) return *list;
	rev= reverse_recursive(&((*list)->next));
	(*list)->next->next = *list;
	(*list)->next = NULL;
	return rev;
}
void BuilListeven(struct node *list)
{
	insertBegining(list,10);
	insertBegining(list,20);
	insertBegining(list,30);
	insertBegining(list,40);
	insertBegining(list,40);
	insertBegining(list,30);
	insertBegining(list,20);
	insertBegining(list,10);
}

void BuilListodd(struct node *list)
{
	insertBegining(list,10);
	insertBegining(list,20);
	insertBegining(list,30);
	insertBegining(list,40);
	insertBegining(list,30);
	insertBegining(list,20);
	insertBegining(list,10);
}
bool compare(struct node *l1,struct node *l2)
{
	while(l2 && l1 &&  (l1->data ==l2->data ))
	{
			l2 =l2->next;
			l1 =l1->next;
	}
	return (!l2) ? true : false;
}
bool isPalindrome(struct node *list)
{
	struct node *slow = list;
	struct node *fast = list;
	struct node * rev = NULL;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	rev = (!fast) ? reverse_recursive(&slow) : reverse_recursive(&(slow->next));
	return  compare(list,rev);
}
bool isPalindrome2(struct node *list)
{
	stack<int> s;
	struct node * traversal = list;
	while(traversal)
	{
		s.push(traversal->data);
		traversal = traversal->next;
	}	
	struct node *rev = reverse_recursive(&list);
	while( rev && (rev->data == s.top()))
	{
		  rev= rev->next;
		  s.pop();
	}
	return s.empty();
}
int main()
{
	BuilListodd(head);
	display();
	cout << "list is palindrome : " << isPalindrome(head);
  return 0;
}
