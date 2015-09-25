#include<iostream>

using namespace std;
		struct node
		{
			struct node * next;
			int data;
		};
class list
{
	private:
		struct node * m_list;
	public:
		list(struct node* _list=NULL):m_list(_list){}
		void insert(int _data);
		void display();
		void reverse();
		void reverse_recursive_count(int count);
		struct node* reverse_recursive_helper(struct node *list,int count);
		void reverse_recursive();
		struct node * gethead(){return m_list;}
};
void list::reverse_recursive_count(int count)
{
		struct node * head;
		struct node *temp;
		struct node *jun;
		if(!(m_list))
		{return;}
		else
	    {
			jun = m_list;	
		    head= reverse_recursive_helper(m_list,count);
			reverse_recursive_count(count);
			jun->next = m_list;
			m_list = head;
		}
}
struct node* list::reverse_recursive_helper(struct node *list,int count)
{
	 struct node* head ;
	 struct node* temp ;
	 struct node* ret ;
     struct node *nexthead ;
	 if(!(m_list->next->next)) {
			m_list->next->next=m_list;
			m_list=m_list->next;
			return NULL;}
	if( count <=2) {
			ret = m_list->next->next;
			m_list->next->next=m_list;
			m_list=m_list->next;
			return ret;}
	else
	{
	    temp =m_list;
		m_list =m_list->next;
		head = reverse_recursive_helper(m_list,count-1);
		temp->next->next = temp;
		temp->next = NULL;

	}
	temp->next = head;
	nexthead = m_list;
	m_list = head;
	return nexthead;
}
void list::reverse_recursive()
{
	if(!(m_list->next->next)){
			m_list->next->next=m_list;
			m_list=m_list->next;
			return;}
	else
	{
	    struct node* temp=m_list;
		m_list =m_list->next;
		reverse_recursive();
		temp->next->next = temp;
		temp->next = NULL;
	}
}
void list::reverse()
{
	struct node * _previous = NULL;
	struct node * _current = m_list;
	struct node * _next = NULL;
	while(_current)
	{
			_next = _current->next;
			_current->next =_previous;
			_previous =_current;
			_current =_next;
	}
	
	m_list = _previous;
}
void list::insert(int _data)
{
		struct node* _temp = new struct node;
		_temp->data =_data;
		_temp->next = NULL;
		if(!m_list) m_list = _temp;
		else{
			_temp->next = m_list;
			m_list = _temp;
		}
}
void list::display()
{
	struct node *_traversal = m_list;
	while(_traversal)
		{
			std::cout << _traversal->data << "...";
			_traversal = _traversal->next;
		}
}
int main()
{
	list l1;
	l1.insert(10);
	l1.insert(20);
	l1.insert(30);
	l1.insert(40);
	l1.insert(50);
	l1.insert(60);
	l1.insert(70);
	l1.insert(80);
	l1.insert(90);
	l1.display();
	cout << endl;
//	l1.reverse();
//	l1.display();
	cout << endl;
	l1.reverse_recursive_count(4);
	l1.display();
	cout << endl;
//	l1.reverse_recursive_count(2);
//	l1.display();
	cout << endl;
}
