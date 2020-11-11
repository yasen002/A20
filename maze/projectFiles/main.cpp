// DEFINE YOUR TEST
//#define RUN01  //general queue and stack testing
#define RUN02  //testing the game
//#define RUN03  //queue testing 
//#define RUN04  //stack testing 

//#define RUN09

#ifdef RUN09
#include<string>
#include<vector>
#include<iostream>
using std::string;

int mystery1(int a, int b) {
	if (b == 0) return 1;

	if (b % 2 == 0) return mystery1(a * a, b / 2);

	return mystery1(a * a, b / 2) * a;
}

int sumOfDigits(int num) {
	//1. devide num by 10 and + (num %10) and pass it to itself
	//2. if *1/10 ==0 return num

	if ((num / 10) == 0)
		return num;
	return sumOfDigits(num/10) + (num%10);

	return 0;
}

bool isPalindrome(const char* s, int size) {
	if (size <= 1) return true;
	if (s[0] == s[size - 1]) {
		return isPalindrome(s + 1, size - 2);
	}
	else {
		return false;
	}
}

struct Node {
	int val;
	Node* next;
};
//
//Node* inPlaceMerge(Node* list1, Node* list2) {
//	Node* first,* second, *newList, *smallest;
//	first = list1->next;
//	second = first->next;
//	if (first == nullptr || second == nullptr) {
//		return nullptr;
//	}
//
//	 smallest = inPlaceMerge(second, first);
//
//	if (list1->val < list2->val) {
//		newList->val = list1->val;
//		newList->next = list2;
//		return newList;
//	}else {
//		newList->val = list2->val;
//		newList->next = list1;
//		return newList;
//	}
//
//
//	return newList;
//
//}
//
//
//struct vNode {
//	int val=0;
//	std::vector<vNode*> children;
//};
//
//
//
//int nodeCount(vNode* node) {
//	int child_count = 1;
//	int size = node->children.size();
//	if (size) {
//		for (int i = 0; i < size; i++) {
//			child_count += nodeCount(node->children[i]);
//		}
//	}
//
//	return child_count;
//}
//
//int leafCount(vNode* node) {
//	int leaf_count = 0;
//	int size = node->children.size();
//
//	if (!size)leaf_count += 1;
//	for (int i = 0; i < size; i++) {
//		leaf_count += leafCount(node->children[i]);
//	}
//	return leaf_count;
//
//}
//
//int edgeCount(vNode* node) {
//
//	if(nodeCount(node) >1)
//
//}

int main() {



	//vNode* a,b,c,d, *e, *e2, *e3, *e4, *e5, *e6, *e7, *e8, *e9,*e10,*e11;
	//b.val = 2;
	//a = new vNode;
	//a->val = 1;
	//e = new vNode;
	//e->val = 3;
	//e2 = new vNode;
	//e2->val = 4;
	//e3 = new vNode;
	//e3->val = 5;
	//e4 = new vNode;
	//e4->val = 6;
	//e5 = new vNode;
	//e5->val = 7;
	//e6 = new vNode;
	//e6->val = 8;
	//e7 = new vNode;
	//e7->val = 9;
	//e8 = new vNode;
	//e8->val = 10;
	//e9 = new vNode;
	//e9->val = 11;
	//e10 = new vNode;
	//e10->val = 12;
	//e11 = new vNode;
	//e11->val = 13;

	//e2->children.push_back(e4);
	//e2->children.push_back(e5);
	//a->children.push_back(e);
	//a->children.push_back(e2);
	//a->children.push_back(e3);
	//
	/*e2->children.push_back(e4);
	e2->children.push_back(e5);
	e3->children.push_back(e3);
	e4->children.push_back(e6);
	e4->children.push_back(e7);
	e7->children.push_back(e8);
	e7->children.push_back(e9);
	e9->children.push_back(e10);
	e9->children.push_back(e11);*/



	//int aaa = e11->children.size();
	//int num = nodeCount(a);

	//int b = l1 + l2 + l3;
	//std::cout<<sumOfDigits(12345);
	//mystery1(3, 3);
	//std::cout << 1/ 10;
	//std::cout << 1 % 2;
	return 0;
}

#endif




#ifdef RUN01

#include<string>
using std::string;
#include"stack.h"
#include"queue.h"

int main() {

	Stack<std::string> stack;
	Queue<std::string> queue;

	stack.push("Feynman");
	stack.push("Turing");
	stack.push("Einstein");
	stack.push("Bohr");
	stack.push("Sanchez");

	stack.print();

	queue.push(stack.peek());
	stack.pop();

	queue.push(stack.peek());
	stack.pop();

	queue.push(stack.peek());
	stack.pop();

	queue.push(stack.peek());
	stack.pop();

	queue.pop();
	queue.pop();

	queue.print();
	
	return 0;
}

#elif defined(RUN02) //Test the game

#include"game.h"
#include"queue.h"
#include <iostream>
#include <fstream>

int main() {
	
	//Setup game
	Game g("settings.ini");

	g.play();
	int a;

	
	return 0;
}
#elif defined(RUN03) //Test the Queue

#define MAKE_MEMBERS_PUBLIC  //make private member public for testing purpose

#include <assert.h>     /* assert */
#include"game.h"
#include"queue.h"
#include <iostream>
#include <fstream>

int main() {

	Queue<int> q;

	//Empty()
	assert(q.empty()==true);

	//Push()
	q.push(1);
	assert(q.empty() == false);
	q.push(2);
	q.push(3);
	q.print();
	assert(q.empty() == false);

	//Pop
	q.pop();
	assert(q.m_list.num_nodes == 2); // have 2 node left
	assert(q.m_list.head->item == 2); // remove fron the front
	q.pop();
	assert(q.m_list.num_nodes == 1); // have 1 node left
	assert(q.m_list.head->item == 3); // remove fron the front
	q.pop();
	assert(q.m_list.num_nodes == 0); // have 0 node left
	assert(q.empty() == true);
	q.pop();
	q.pop();

	//Peek()
	q.push(333);
	assert( q.peek()==333);  //what should i return for an empty peek?????
	q.push(4);
	q.push(5);
	q.push(6);
	assert(q.peek() == 333);

	//printf()
	q.print();

	return 0;
}

#elif defined(RUN04) //Test the Stack

//#define MAKE_MEMBERS_PUBLIC  //make private member public for testing purpose

#include <assert.h>     /* assert for testing*/
#include"game.h"
#include"stack.h"
#include <iostream>
#include <fstream>

int main() {
	
	Stack<std::string> s;  //as long as it works properly can i assume the front and end of the stack myself?????

	//Empty()
	assert(s.empty() == true);

	//Push 
	s.push("helllo");
	s.push("helllo2");
	s.push("helllo3");
	assert(s.empty() == false);

	//Peek, //Pop
	s.pop();
	assert(s.peek() == "helllo2");
	s.pop();
	assert(s.peek() == "helllo");
	s.pop();
	assert(s.peek()=="");
	s.push("helllo");
	s.push("helllo2");
	s.push("helllo3");
	assert(s.empty() == false);
	
	//Print
	s.print(); //they way i should add to the front of back affact the way how is it printed?????
			   //what is the front and back of stack with respact to list. 
	return 0;
}
#else

//what could go in there?????
#endif
