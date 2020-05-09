

// Choose which run to compile
#define RUN0 //RUN1 RUN2 RUN3 RUN4
#define MAKE_MEMBERS_PUBLIC

#ifdef RUN0 

#include"list.h"
#include"studentinfo.h"
#include<iostream>
#include<string>  


template<typename Type>
bool pushFrontTest( List<Type>& l) {
	//testing senario:
	//1.when list is empty, head and tail points to same thing
	l.push_front("Hi");
	if (l.head != l.tail)
		return false;

	//2.when there is multiple nodes, head and tail points to proper node
	l.push_front("World");
	l.push_front("Bob");
	l.push_front("2");
	if (l.head == l.tail)
		return false;
	//std::cout << l.head->item;
	if (l.head->item != "2")
		return false;
	if (l.tail->item != "Hi")
		return false;

	if (l.num_nodes != 4)
		return false;

	return true;
}










int main() {

	std::cout << StudentInfo::name() << std::endl;
	std::cout << StudentInfo::id() << std::endl;

	List<std::string> l; //List of integers


	pushFrontTest(l) ? std::cout << "Push front     OK\n" : std::cout << "push front     Fail\n";

	//if (pushFrontTest(l)) {
	//	std::cout << "push front OK!";
	//}



	l.print(); // 2 Bob World Hello

	//l.pop_rear();
	//l.print(); // 2 Bob World 

	//std::cout << l.front() << std::endl; // 2
	return 0;
}

#elif defined RUN1
#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily ther default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function to spec.
	List<int> l;


	// Step 2: Execute the function to test
	l.push_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is suppose to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l.head != nullptr);
	assert(l.tail != nullptr);
	assert(l.num_nodes == 1);
	assert(l.head->prev == nullptr);
	assert(l.head->next == nullptr);
	assert(l.head->item == 99);
	

}


#elif defined RUN2
#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

	// Step 1: Initial state
	// Same as above, except we must first populate the list
	// However, since we are testing push_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	List<std::string>::Node* first = new List<std::string>::Node;
	List<std::string>::Node* second = new List<std::string>::Node;
	List<std::string>::Node* third = new List<std::string>::Node;
	
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
	// We can test various member functions for correctness.
	// For example we can use this as one test for push_front;
	l.push_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' item, next, prev pointers
	// to ensure that the push_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l.num_nodes == 4);
	assert(l.head->prev == nullptr);
	assert(l.head == first->prev);
	assert(l.head->next == first);
	assert(l.head->item == "Zero");
	assert(l.tail == third);
}

#else

#endif






//#include <iostream>
//using namespace std;
//
//
//
//struct Node {
//    string value;
//    Node* next;
//};
//
//class LinkedList
//{
//public:
//	LinkedList();
//    void printItems();
//    void addToFront(string v);
//    void addToRear(string v);
//    void addItem(string v);
//    void deleteItem(string v);
//    bool findItem(string v);
//	~LinkedList();
//
//private:
//    Node* head;
//};
//
//
//
//
//
//LinkedList::LinkedList() :head(nullptr) {};
//
//LinkedList::~LinkedList()
//{
//};
//
//void LinkedList::printItems()
//{
//    //start at head 
//
//     //while there are node
//        //print Node
//        //go to next Node
//    Node* p = head;
//    while (p->next != nullptr)
//    {
//        cout << p->value << endl;
//        p = p->next;
//    }
//
//};
//
//void LinkedList::addToFront(string v) {
//    //allocate new node
//    //put the value in new node
//    //new node->next is old node->head
//    //new node becomes head
//    Node* p = new Node;
//    p->value = v;
//    p->next = head;
//    head = p;
//}
//
//
//void LinkedList::addToRear(string v) {
//    //case1: list is emty
//        //if  list is emty add to front
//    //case2: list has nodes
//        //traverse node and get to last node
//        //allocate new Node
//        //add value to new Node
//        //last_node->next is new node
//        //new node->next is nullptr
//
//        
//    if (head == nullptr)
//        addToFront(v);
//    else {
//        Node* p = head;
//        while (p->next !=nullptr)
//        {
//            p = p->next;
//        }
//        Node* n = new Node;
//        n->value = v;
//        p->next = n;
//        n->next = nullptr;
//    }   
//}
//
//
//void LinkedList::addItem(string v) {
//    //if list is empty
//        //add to front
//    //if the node belongs to the front
//    //if the node belongs to middle
//        //traverse the node to above the target node
//        //allocate new node
//        //put the value
//        //link new node into above Node
//        //line new node->next 
//    if (head == nullptr)
//        addToFront(v);
//    else if(v<head->value) {
//        addToFront(v);
//    }
//    else {
//        Node* p = head;
//        while (p->next!=nullptr)
//        {
//            if (v >= p->value && v <= p->next->value)
//                break;
//            p = p->next;
//        }
//        Node* latest = new Node;
//        latest->value = v;
//        latest->next = p->next;
//        p->next = latest;
//    }
//}
//
//
//void LinkedList::deleteItem(string v) {
//    //if the list empty return 
//    //if the fist node has the item 
//        //create a node to hold the head
//        //head point to second node
//        //delete the target 
//        //return done
//    //if the target is somewhere middle
//        //traverse to the node above teh target that we want to delete
//        //if we found the target node 
//            //create a node to hold the target
//            //link above node to the node below
//            //delete the target 
//            //return done
//
//    if (head == nullptr)return;
//    
//    if (head->value == v) {
//        Node* killMe = head;
//        head = killMe->next;
//        delete killMe;
//        return;
//    }
//    else {
//        Node* p = head;
//        while (p!=nullptr)
//        {
//            if (p->next != nullptr && p->next->value == v)
//                break;
//            p = p->next;
//        }
//        if (p != nullptr) {
//            Node* killMe = p->next;
//            p->next = killMe->next;
//            delete killMe;
//        }
//    }
//}
//
//
//bool LinkedList::findItem(string v) {
//    //create a pointer object
//    //traverse untill it matchs
//    //return true or false
//    Node* p = head;
//    while (p->next != nullptr )
//    {
//        if (p->value == v)
//            return true;
//        p = p->next;
//    }
//
//    return false;
//}
//
//LinkedList::~LinkedList() {
//    Node* p;
//    p = head;
//    while (p!=nullptr)
//    {
//        Node* n = p->next;
//        delete p;
//        p = n; //how can we access the thing that we already deleted
//    }
//}
//
//
//
//int main()
//{
//   
//    return 0;
//}
