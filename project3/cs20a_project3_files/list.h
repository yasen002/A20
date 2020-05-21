//--
#ifndef CS20A_LIST_H
#define CS20A_LIST_H

#include <iostream>
#include <assert.h>
// Linked List object that maintains both head and tail pointers
// and the num_nodes of the list.  Note that you have to keep the head,
// tail and num_nodes consistent with the intended state of the List
// otherwise very bad things happen.
template <typename Type>
class List
{
public:
	List();

	List(const List<Type> &other);

	List<Type> &operator=(const List<Type> &other);

	~List();

	void print() const;
	bool empty() const;

	void push_front(const Type &item);
	void push_back(const Type &item);
	void add_at(int index, const Type &item);

	// Note that the user must first ensure the list is not empty
	// prior to calling these functions.
	Type front() const;
	Type rear() const;
	Type get_at(int index) const;

	int size() const;
	int find(const Type &item) const;

	bool pop_front();
	bool pop_rear();
	bool pop_at(int index);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our List.
	// Will be implemented along with list's
	// member functions
	class Node;

	// We'll have both head and tail points for
	// Fast insertion/deletion from both ends.
	Node *head;
	Node *tail;

	// Keep track of num_nodes of list
	int num_nodes;
};

/* List Implementation
//
//  Since List is a template class (which is not an actual 
//  class yet, not until we actually instantiate the list) 
//  we need to keep the implementation together with 
//  the definition.  There are ways to simulate having 
//  separate "implementation/definition" with templates, 
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template <typename Type>
class List<Type>::Node
{
public:
	Node() : next(nullptr), prev(nullptr) {}
	Node(Type item, Node *p, Node *n) : item(item), next(n), prev(p) {}

	Type item;
	Node *next;
	Node *prev;
};

/* List default constructor
//		Set head and tail pointer to point to nothing, num_nodes is zero
//		Already implemented, nothing to do.
*/
template <typename Type>
List<Type>::List() : head(nullptr), tail(nullptr), num_nodes(0)
{
}

/* Copy constructor  
//		This should create an entirely new linked list with the same 
//		number of Nodes and the Values stored these Nodes in the same 
//		order as seen the other list�s Nodes.  This should not result 
//		in any memory leaks or aliasing.  
*/
template <typename Type>
List<Type>::List(const List<Type> &other)
{
	/* TODO */
	//if ohter.head is null this.head is null
	//else
	//create new node with custom node constructor: Node(Type item, Node* p, Node* n) : item(item), next(n), prev(p) {}
	//create a pointer node P
	//create a current pointer node CP
	// CP is this.head  P is next object to copy over from 'ohter'.
	//traverse all the nodes
	//CP.next = new node from P
	//CP=CP.next
	//p=p.next

	if (other.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		num_nodes = other.num_nodes;
		head = new List<Type>::Node(other.head->item, nullptr, nullptr);
		List<Type>::Node *p = other.head->next;
		List<Type>::Node *cp = head;
		tail = head; //can i let the head and tail point ot same node?????
		while (p != nullptr)
		{
			cp->next = new List<Type>::Node(p->item, nullptr, nullptr);
			//cp->next = new List<Type>::Node(p->item, cp, nullptr);why this did not work-----?????
			cp->next->prev = cp;
			cp = cp->next;
			tail = cp;
			p = p->next;
		}
		//all the 5coding part is done but have not test it yet!;
	}

	////set the head to new node
	//List<Type>::Node* p = new List<Type>::Node;  //why do i have to use it this way------?????
	////other.head == this.head

	//this->num_nodes = other->num_nodes;
	//for (int i = 0; i < this->num_nodes; i++) {

	//}
}
/* Overloaded assignment operator 
//		Causes the already existing linked list to be identical to the 
//		other linked list without causing any memory leaks or aliasing.
*/
template <typename Type>
List<Type> &List<Type>::operator=(const List<Type> &other)
{
	/* TODO */
	if (&other == this)
	{
		return (*this);
	}
	return *this;

	//clear m_list
	for (int i = 0; i < num_nodes; i++)
	{
		pop_front();
	}

	num_nodes = other.num_nodes;

	//copy m_list
	for (int i = 0; i < num_nodes; i++)
	{
		this->push_back(other.get_at(i));
	}
	// TODO:
	return *this;
}

/* List destructor
//		Traverses the nodes and deletes them without causing memory leaks
*/
template <typename Type>
List<Type>::~List()
{
	/* TODO */
	Node *p;
	p = head;
	while (p != nullptr)
	{
		Node *n = p->next;
		delete p;
		p = n;
	}
	//std::cout << "destructor called\n";
}

/* List print
//		Traverses list and prints items in list to console
//		Assumes << is overloaded for object Type.---------------------?????
*/

template <typename Type>
void List<Type>::print() const
{
	/* TODO */
	//1.while there is node loop through all nodes
	//print node
	//go to next note

	if (num_nodes > 0)
	{
		Node *p = head;
		for (int i = 0; i < num_nodes; i++)
		{
			std::cout << p->item << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
}

/* List empty
//		returns true if there are no items in the list
//		otherwise returns false.
*/
template <typename Type>
bool List<Type>::empty() const
{
	/* TODO */
	if (num_nodes == 0)
		return true;

	return false;
}

/* List push_front
//		Adds a new item to the front of the list
//		updates head, tail, and num_nodes accordingly.
//		
//		Two cases to consider: If the list is empty 
//		and if the list has items already it.
*/
template <typename Type>
void List<Type>::push_front(const Type &item)
{
	/* TODO */
	//    //allocate new node
	//    //put the value in new node
	//    //new node->next is old node->head
	//    //new node becomes head

	//update head & tail
	//if the list is empty:
	//head & tail equal to the same node?????
	//if the list has nodes:
	//tail stays the same

	if (head == nullptr)
	{
		Node *p = new Node;
		p->item = item;
		p->next = head;
		head = p;
		tail = p;
	}
	else
	{
		Node *p = new Node;
		p->item = item;
		p->next = head;
		head->prev = p;
		head = p;
	}
	num_nodes += 1;
}

/* List push_back
//		Adds a new item to the rear of the list
//		updates head, tail, and num_nodes accordingly.
//
//		Two cases to consider: If the list is empty 
//		and if the list has items already it.
*/
template <typename Type>
void List<Type>::push_back(const Type &item)
{
	/* TODO */

	//if list is empty
	//add to front
	//if the list has items
	//create new node and store the value
	//new.prev = tail
	//tail.next = new node
	//tail = new node

	if (num_nodes == 0)
	{
		push_front(item);
		return;
	}
	else
	{
		Node *p = new Node;
		p->item = item;
		p->prev = tail;
		tail->next = p;
		tail = p;
	}
	num_nodes += 1;
}

/* List add_at
//		Adds a new item at the index indicated
//		updates head, tail, and num_nodes accordingly.
//
//		If the index less than or equal to zero add to the front.
//		If the index is greater than or equal to
//			the num_nodes of the list, add to the rear.
//		All other cases, add the item to the appropriate
//			location
*/
template <typename Type>
void List<Type>::add_at(int index, const Type &item)
{
	/* TODO */
	//If the index less than or equal to zero add to the front.
	if (index <= 0)
	{
		push_front(item);
		return;
	}

	//If the index is greater than or equal to the num_nodes, add to the rear.
	if (index >= num_nodes)
	{
		push_back(item);
		return;
	}

	//All other cases, add the item to the appropriate location
	//traverse to one Index ahead
	//create New node with value init
	//New.next = Index.next
	//Index.next = New node
	//New.prev = Index
	//New.next.prev = New
	Node *p = new Node;
	p = head;
	for (int i = 0; i < num_nodes; i++)
	{
		if (i == (index))
		{ //can i assume that the index starts from zero?
			break;
		}
		else
		{
			p = p->next;
		}
	}
	Node *n = new Node;
	n->item = item;
	n->next = p->next;
	p->next = n;
	n->prev = p;
	n->next->prev = n;

	//update member var
	num_nodes += 1;
}

/*  List front
//		returns the first item in the list.
*/
template <typename Type>
Type List<Type>::front() const
{
	// Force check that the head is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that yet
	// we'll make due with assert, which is used for testing

	assert(head != nullptr);
	/* TODO */
	if (head != nullptr)
	{
		Type first_item = head->item;
		return first_item;
	}
	Type none = NULL;
	return none;
}

/* List rear
//		returns the last item in the list
*/
template <typename Type>
Type List<Type>::rear() const
{

	// Force check that the tail is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(tail != nullptr);

	/* TODO */
	if (tail != nullptr)
	{
		Type last_item = tail->item;
		return last_item;
	}
	Type None = NULL;
	return None;
}

/* List get_at
//		returns the item at index
*/
template <typename Type>
Type List<Type>::get_at(int index) const
{

	// Force index to be correct before getting the Item
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(index >= 0 && index < num_nodes);

	/* TODO */
	//If the index less than or equal to zero
	//If the index is greater than or equal to the num_nodes

	//All other cases, return the item to the appropriate location
	//traverse
	//it the index is found return the item;
	if (index >= 0 && index < num_nodes)
	{
		Node *p = new Node;
		p = head;
		for (int i = 0; i < num_nodes; i++)
		{
			if (i == (index))
			{
				return p->item;
			}
			else
			{
				p = p->next;
			}
		}
	}

	Type None = NULL;
	return None;
}

/* List size
//		return the num_nodes of the list
*/
template <typename Type>
int List<Type>::size() const
{
	/* TODO */
	return num_nodes;
}

/* List find
//		Traverses the list to see if the item is in the list
//		if it is return the index of that item, otherwise
//		return -1. Assumes the == operator is overloaded for//?????
//		object Type.
*/
template <typename Type>
int List<Type>::find(const Type &item) const
{

	/* TODO */
	//if there is node, traverse array
	//if no node return -1
	//if not found return -1
	if (num_nodes > 0)
	{
		Node *p = new Node;
		p = head;
		for (int i = 0; i < num_nodes; i++)
		{
			if (p->item == item)
			{
				return i;
			}
			else
			{
				p = p->next;
			}
		}
	}

	return -1;
}

/* List pop_front
//		Removes the first item in the list returns true
//		if the item was deleted, false otherwise. Updates 
//		head, tail, and num_nodes accordingly.
//
//		Must consider at least two cases where the list: is empty, 
//		has one or more items.
*/
template <typename Type>
bool List<Type>::pop_front()
{

	/* TODO */
	//create New node = head
	//New node = head; head= hea.next
	//delete new node
	// decrement number of node

	//if there is only one node
	//head = nul
	//if there is more items
	//still works

	if (head)
	{
		Node *p = head;
		Node *n = head->prev;
		head = head->next;
		delete p;
		num_nodes--;
		return true;
	}

	return false;
}
/* List pop_rear
//		Removes the last item in the list returns true
//		if the item was deleted, false otherwise. Updates 
//		head, tail, and num_nodes accordingly.
//
//		Must consider at least three cases where the list: is empty, 
//		has one item, has two or more items.
*/
template <typename Type>
bool List<Type>::pop_rear()
{

	if (num_nodes == 0)
	{
		return false;
	}
	else if (num_nodes == 1)
	{
		//remove that one item
		//maybe had to delete the space
		delete head;
		head = nullptr;
		tail = nullptr;
		num_nodes = 0;
		return true;
	}
	else if (num_nodes > 1)
	{
		Node *p = tail;
		tail = tail->prev;
		delete p;
		num_nodes -= 1;
		tail->next = nullptr;
		return true;
	}

	return false;
}

/* List pop_at
//		Removes the item at the index returns true
//		if the item was deleted, false otherwise. Updates 
//		head, tail, and num_nodes accordingly. If the index is
//		out of bounds return false.
*/
template <typename Type>
bool List<Type>::pop_at(int index)
{

	/* TODO */

	//if the index is valid
	if (index < num_nodes && index >= 0)
	{

		if (num_nodes == 0)
		{
			return false;
		}
		else if (num_nodes == 1)
		{
			if (index == 0)
			{
				this->pop_front();
				return true;
			}
			return false;
		}
		else if (num_nodes > 1)
		{
			//if index is 0
			if (index == 0)
			{
				this->pop_front();
			} //if index is last index
			else if (index == (num_nodes - 1))
			{
				this->pop_rear();
			}
			else
			{
				//go to the index
				Node *p = new Node;
				p = head;
				for (int i = 0; i < num_nodes; i++)
				{
					if (i == (index))
					{
						break;
					}
					else
					{
						p = p->next;
					}
				}

				Node *top = p->prev;
				Node *bottom = p->next;

				top->next = bottom;
				bottom->prev = top;
				delete p;
				//update member var
				num_nodes -= 1;
				return true;
			}
		}
	}

	return false;
}

#endif