// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3 RUN4
#define MAKE_MEMBERS_PUBLIC

#ifdef RUN0

#include "list.h"
#include "studentinfo.h"
#include <iostream>
#include <string>

enum TestMEthod
{
	Print,
	Empty,
	PushFront,
	PushBack,
	AddAt,
	Front,
	Rear,
	GetAt,
	Size,
	Find,
	PopFront,
	PopRear,
	PopAt,
	CopyConstructor
};

//this is a fucntion that test the link list
bool test(TestMEthod method);

int main()
{

	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<std::string> l, l2, l3, l4, l5, l6, l7, l8; //List of integers

	test(PushFront) ? std::cout << "Push front     OK\n" : std::cout << "push front     Fail\n";
	test(Print);
	test(Empty) ? std::cout << "Empty     OK\n" : std::cout << "Empty     Fail\n";
	test(PushBack) ? std::cout << "PushBack     OK\n" : std::cout << "PushBack     Fail\n";
	test(AddAt) ? std::cout << "AddAt     OK\n" : std::cout << "AddAt     Fail\n";
	test(Front) ? std::cout << "front     OK\n" : std::cout << "front     Fail\n";
	test(Rear) ? std::cout << "Rear     OK\n" : std::cout << "Rear     Fail\n";
	test(GetAt) ? std::cout << "GetAt     OK\n" : std::cout << "GetAt     Fail\n";
	test(Find) ? std::cout << "Find     OK\n" : std::cout << "Find     Fail\n";
	test(PopFront) ? std::cout << "popFront     OK\n" : std::cout << "popFront     Fail\n";
	test(PopRear) ? std::cout << "popRear     OK\n" : std::cout << "popRear     Fail\n";
	test(PopAt) ? std::cout << "popat     OK\n" : std::cout << "popat     Fail\n";

	//l.pop_rear();
	//l.print(); // 2 Bob World
	//std::cout << l.front() << std::endl; // 2
	return 0;
}

#elif defined RUN1
#define MAKE_MEMBERS_PUBLIC
#include "list.h"
#include <assert.h>

//Unit test example for push_font on initially empty list

int main()
{

	// Step 1: Initial state

	List<int> l;

	// Step 2: Execute the function to test
	l.push_front(99);

	// Step 3: Verify what you expect to observe.

	assert(l.head != nullptr);
	assert(l.tail != nullptr);
	assert(l.num_nodes == 1);
	assert(l.head->prev == nullptr);
	assert(l.head->next == nullptr);
	assert(l.head->item == 99);
}

#elif defined RUN2
#define MAKE_MEMBERS_PUBLIC
#include "list.h"
#include <assert.h>
#include <string>

//Unit test example for push_font on initially non empty list

int main()
{

	// Step 1: Initial state

	List<std::string>::Node *first = new List<std::string>::Node;
	List<std::string>::Node *second = new List<std::string>::Node;
	List<std::string>::Node *third = new List<std::string>::Node;

	// We have to manually linked everything together:
	first->item = "first";
	first->prev = nullptr;
	first->next = second;

	second->item = "second";
	second->prev = first;
	second->next = third;

	third->item = "third";
	third->prev = second;
	third->next = nullptr;

	// Now we create  List object and inject the initial control state:
	List<std::string> l;
	l.head = first;
	l.tail = third;
	l.num_nodes = 3;

	// Step 2: Now with the list given a complete and correct starting state

	l.push_front("Zero");

	// Step 3: Verify:  Technically, we should examine all

	assert(l.num_nodes == 4);
	assert(l.head->prev == nullptr);
	assert(l.head == first->prev);
	assert(l.head->next == first);
	assert(l.head->item == "Zero");
	assert(l.tail == third);
}

#else

#endif

//template<typename Type>
bool test(TestMEthod method)
{
	List<std::string> l;

	//copy constructor testing---------
	List<std::string> l3;
	l3.push_front("Hi2");
	l3.push_front("World2");
	l3.push_front("Bob2");
	l3.push_front("2");
	List<std::string> l2 = l3;
	assert(l2.num_nodes == 4);
	assert(l2.head->item == "2");		//check the head
	assert(l2.tail->item == "Hi2"); //check the tail
	//copy constructor testing---------ends

	l3.push_front("Bob21");
	l3.push_front("Bob22");
	l3.push_front("Bob23");
	l3.push_front("Bob24");

	l2 = l3;

	std::cout << "hello";

	switch (method)
	{
	case Print:
		//1.if tere is nothing to print
		//2.if there is things to print
		l.print();
		l.print();
		l.print();
		l.push_front("Hi2");
		l.push_front("World2");
		l.push_front("Bob2");
		l.push_front("2");
		l.print();
		break;
	case Empty:
		assert(l.empty() == true); //shoud be empty at first
		l.push_front("Hi2");
		assert(l.empty() == false); //should not be empty
		l.push_front("World2");
		assert(l.empty() == false); //should not be empty
		return true;
	case PushFront:
		//testing senario:
		//1.when list is empty, after pushing one element, head and tail points to same thing
		l.push_front("Hi");
		assert(l.head == l.tail);

		//2.when there is multiple nodes, head and tail points to proper node
		l.push_front("World");
		l.push_front("Bob");
		l.push_front("2");
		assert(l.head != l.tail);
		assert(l.head->item == "2");	//check the head
		assert(l.tail->item == "Hi"); //check the tail
		assert(l.num_nodes == 4);
		return true;
	case PushBack:
		//1.if the list is empty
		l.push_back("Hello4");
		assert(l.head == l.tail); //fitst time head and tail is the same------------?????
		assert(l.num_nodes == 1);
		//2.if list has item, check tail
		//3.does the list has consistent local vars?
		l.push_back("Hello5");
		l.push_back("Hello6");
		assert(l.tail->item == "Hello6");
		assert(l.num_nodes == 3);
		return true;
	case AddAt:
		//List<std::string> ll;   //why can't i initialize another object in this fucntio------------?????
		//if there is no node
		l.add_at(0, "yasen1");
		assert(l.head->item == "yasen1");
		//negetive index
		l.add_at(-1, "yasen2");
		assert(l.head->item == "yasen2");
		//if index = num_nodes
		assert(l.num_nodes == 2);
		l.add_at(2, "yasen3");
		assert(l.tail->item == "yasen3");
		//if index > num_nodes
		l.add_at(55, "yasen4");
		assert(l.tail->item == "yasen4");
		return true;
	case Front:
		//what should i return for front() if the L is empty?????
		l.push_front("World");
		l.push_front("Bob");
		l.push_front("2");
		l.front();
		assert(l.head->item == "2");

		return true;
	case Rear:
		//test the empty senario!!!!!
		l.push_front("World");
		l.push_front("Bob");
		l.push_front("2");
		assert(l.tail->item == "World");
		assert(l.num_nodes == 3);
		return true;
	case GetAt:
		l.push_front("World");
		assert(l.get_at(0) == "World");
		l.push_front("Bob");
		l.push_front("2");
		assert(l.get_at(1) == "Bob");
		assert(l.num_nodes == 3);
		assert(l.head->item == "2");		 //check the head
		assert(l.tail->item == "World"); //check the tail

		return true;
	case Size: //have to test this!!!!!
		break;
	case Find:
		assert(l.find("World") == -1);
		l.push_front("World");
		assert(l.find("World") == 0);
		l.push_front("Bob");
		l.push_front("2");
		assert(l.find("Worldlolololo") == -1);
		assert(l.find("Bob") == 1);
		assert(l.num_nodes == 3);
		assert(l.head->item == "2");		 //check the head
		assert(l.tail->item == "World"); //check the tail
		return true;
	case PopFront:
		l.push_front("World");
		assert(l.get_at(0) == "World");
		l.push_front("Bob");
		l.push_front("2");
		assert(l.get_at(1) == "Bob");
		assert(l.num_nodes == 3);
		assert(l.head->item == "2");		 //check the head
		assert(l.tail->item == "World"); //check the tail

		//pop check

		//if there is multiple nodes
		assert(l.pop_front() == true);
		assert(l.num_nodes == 2);
		l.pop_front();
		assert(l.num_nodes == 1);
		//if there is one nodes
		l.pop_front();
		assert(l.num_nodes == 0);
		//if there is no nodes
		l.pop_front();
		assert(l.num_nodes == 0);
		assert(l.pop_front() == false);

		return true;
	case PopRear:
		//when list is empty
		assert(l.pop_rear() == false);
		l.push_front("World");
		//when there is only one thing in list
		assert(l.pop_rear() == true);

		l.push_front("Bob");
		l.push_front("Bob2");
		l.push_front("Bob3");
		l.push_front("Bob4");
		l.push_front("Bob5");
		l.push_front("2");
		//list has more multiple thing
		assert(l.pop_rear() == true);
		assert(l.pop_rear() == true);
		assert(l.pop_rear() == true);

		return true;
	case PopAt:
		l.push_front("World");
		assert(l.get_at(0) == "World");
		l.push_front("Bob");
		l.push_front("2");
		assert(l.get_at(1) == "Bob");
		assert(l.num_nodes == 3);
		assert(l.head->item == "2");		 //check the head
		assert(l.tail->item == "World"); //check the tail

		//pop_at tests
		l.pop_at(0);

		assert(l.num_nodes == 2);
		assert(l.tail->item == "World");
		l.pop_at(1);
		assert(l.num_nodes == 1);
		l.push_front("World1");
		l.push_front("World2");
		l.push_front("World3");
		l.push_front("World4");
		l.push_front("World5");
		l.push_front("World6");

		l.pop_at(2);
		l.pop_at(1);
		l.pop_at(4);

		return true;
	case CopyConstructor:

		break;
	default:
		std::cout << "test method not found!\n";
		break;
	}

	return false;
}
