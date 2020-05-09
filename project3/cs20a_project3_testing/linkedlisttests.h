#ifndef PROJECT3_LLTEST_H
#define PROJECT3_LLTEST_H
#define MAKE_MEMBERS_PUBLIC

#include<iostream>
#include <fstream>
#include <sstream> 
#include<string>
#include<iterator>
#include<vector>
#include<assert.h>
#ifdef _MSC_VER // Visual Studio
#define __func__ __FUNCTION__
#endif
#include"debugmem.h"
#include"list.h"


//Test empty
int test_empty(int testNum) {
	std::cout <<__func__ <<testNum << std::endl;

	switch (testNum) {
	case 0: {//Test with empty list
		
		List<int> l;
		assert(l.empty() == true);
		break;
	}
	case 1: {//Test with non-empty list
		
		//Make some control nodes
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.empty() == false);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}


//Test push_front
int test_push_front(int testNum) {
	std::cout << __func__ << testNum << std::endl;



	switch (testNum) {
	case 0: {//Test with empty list

	

		List<int> l;
		l.push_front(99);
		assert(l.head->prev == nullptr);
		assert(l.head->next == nullptr);
		assert(l.head != nullptr);
		assert(l.tail != nullptr);
		assert(l.head->item == 99);
		assert(l.num_nodes == 1);
		break;
	}
	case 1: {//Test with non-empty list
	
		//Make some control nodes
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for push_front;
		l.push_front("Zero");

		//Examing the final state of our list after call
		assert(l.num_nodes == 4);
		assert(l.head->prev == nullptr);
		assert(l.head == first->prev);
		assert(l.head->next == first);
		assert(l.head->item == "Zero");
		assert(l.tail == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}

//Test push_back
int test_push_back(int testNum) {
	std::cout << __func__ << testNum << std::endl;

	switch (testNum) {
	case 0: {//Test with empty list

		List<int> l;
		l.push_back(99);

		assert(l.head->prev == nullptr);
		assert(l.head->next == nullptr);
		assert(l.head != nullptr);
		assert(l.tail != nullptr);
		assert(l.head->item == 99);
		assert(l.num_nodes == 1);
		break;
	}
	case 1: {//Test with non-empty list

			 //Make some control nodes
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.
		//For example we can use this as one test for push_back;
		l.push_back("forth");

		//Examing the final state of our list after call
		assert(l.num_nodes == 4);
		assert(l.head == first);
		assert(l.tail->next == nullptr);
		assert(l.tail->item == "forth");
		assert(l.tail->prev == third);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}

//Test add_at
int test_add(int testNum) {




	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {//Test with empty list
		//Assume Constructor Correctly Implemented
		
		List<int> l;

		l.add_at(0, 1);

		assert(l.num_nodes == 1);
		assert(l.head->item == 1);
		assert(l.head == l.tail);
		assert(l.head != nullptr);
		assert(l.tail != nullptr);
		assert(l.head->next == nullptr);
		assert(l.head->prev == nullptr);
		break;
		
	}
	case 1: {//Test with empty list
	
		List<int> l;

		l.add_at(-1, 1);

		assert(l.num_nodes == 1);
		assert(l.head->item == 1);
		assert(l.head == l.tail);
		assert(l.head != nullptr);
		assert(l.tail != nullptr);
		assert(l.head->next == nullptr);
		assert(l.head->prev == nullptr);
		break;
	}
	case 2: {
		List<int> l;

		l.add_at(99, 1);

		assert(l.head->item == 1);
		assert(l.num_nodes == 1);
		assert(l.head == l.tail);
		assert(l.head != nullptr);
		assert(l.tail != nullptr);
		assert(l.head->next == nullptr);
		assert(l.head->prev == nullptr);
		break;
	}
	case 3: {//Test with non-empty list
		//Make some control nodes
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = second;
		l.num_nodes = 2;

		l.add_at(0, "Zero");


		//Examing the final state of our list after call
		//assert(l.head != nullptr);
		assert(l.num_nodes == 3);
		assert(l.head->prev == nullptr);
		assert(l.head == first->prev);
		assert(l.head->next == first);
		assert(l.head->item == "Zero");
		assert(l.tail == second);

		break;
	}
	case 4: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = second;
		l.num_nodes = 2;

		l.add_at(-1, "Zero");


		//Examing the final state of our list after call
		assert(l.num_nodes == 3);
		assert(l.head->prev == nullptr);
		assert(l.head == first->prev);
		assert(l.head->next == first);
		assert(l.head->item == "Zero");
		assert(l.tail == second);

		break;
	}
	case 5: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;

		//Link together to make a valid linked list
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = second;
		l.num_nodes = 2;

		l.add_at(4, "third");
	
		//Examing the final state of our list after call
		assert(l.num_nodes == 3);
		assert(l.head == first);
		assert(l.tail->next == nullptr);
		assert(l.tail->item == "third");
		assert(l.tail->prev == second);
		break;
	}
	case 6: { //Insert between two nodes
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = second;
		l.num_nodes = 2;

		l.add_at(1, "half");
	
		
		//Examing the final state of our list after call
		assert(l.num_nodes == 3);
		
		assert(l.head == first);
		
		assert(l.head->prev == nullptr); 
		assert(l.head->next->item == "half"); 
		assert(l.tail->prev == l.head->next); 
		assert(l.tail == second); 
		assert(l.tail->next == nullptr); 
		assert(l.head->next->next == l.tail); 
		assert(l.head == l.tail->prev->prev); 
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}

//Test find
int test_find(int testNum) {

	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.find(100)==-1);
		break;
	}
	case 1: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		//Now with the list given a complete and correct starting state
		//We can test various member functions for correctness.


		//Examing the final state of our list after call
		assert(l.find("Zero") == -1);
		assert(l.find("first") == 0);
		assert(l.find("second") == 1);
		assert(l.find("third") == 2);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}

//Test front
int test_front(int testNum) {
	
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::Node* first = new List<std::string>::Node;
		
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.front() == "first");
		break;
	}
	case 1: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.front() == "first");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}


//Test rear
int test_rear(int testNum) {

	
	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::Node* first = new List<std::string>::Node;
		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.rear() == "first");
		break;
	}
	case 1: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.rear() == "third");
		break;
	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}
//Test get_at
int test_get_at(int testNum) {

	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {
		List<std::string>::Node* first = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.get_at(0) == "first");
		break;
	}
	case 1: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.get_at(0) == "first");
		assert(l.get_at(1) == "second");
		assert(l.get_at(2) == "third");
		break;
	}
	
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}

//Test pop_front
int test_pop_front(int testNum) {

	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.pop_front() == false);
		break;
	}
	case 1: {
		List<std::string>::Node* first = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.pop_front() == true);
		assert(l.num_nodes == 0);
		assert(l.head == nullptr);
		assert(l.tail == nullptr);
		break;
	}
	case 2: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.pop_front() == true);
		assert(l.num_nodes == 2);
		assert(l.head == second);
		assert(l.tail == third);
		assert(l.head->prev == nullptr);
		break;
	}
	
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}
//Test pop_rear
int test_pop_rear(int testNum) {

	std::cout << __func__ << testNum << std::endl;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.pop_rear() == false);

	}
	case 1: {//Test with empty list
		List<std::string>::Node* first = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.pop_rear() == true);
		assert(l.num_nodes == 0);
		assert(l.head == nullptr);
		assert(l.tail == nullptr);
		break;
	}
	case 2: {
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.pop_rear() == true);
		assert(l.num_nodes == 2);
		assert(l.head == first);
		assert(l.tail == second);
		assert(l.tail->next == nullptr);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}


int test_pop_at(int testNum) {

	std::cout << __func__ << testNum << std::endl <<std::flush;
	switch (testNum) {
	case 0: {//Test with empty list
		List<int> l;
		assert(l.pop_at(-1) == false);

	}
	case 1: {//Test with empty list
		List<int> l;
		assert(l.pop_at(9999) == false);
		break;
	}
	case 2: {//Test with one node index out of bounds 
		List<std::string>::Node* first = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.pop_at(-1) == false);

		break;
	}
	case 3: {//Test with one node index out of bounds 
		List<std::string>::Node* first = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.pop_at(9999) == false);

		break;
	}
	case 4: {//Test with one node index in bounds 
		List<std::string>::Node* first = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = nullptr;


		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = first;
		l.num_nodes = 1;

		assert(l.pop_at(0) == true);
		assert(l.num_nodes == 0);
		assert(l.head == nullptr);
		assert(l.tail == nullptr);
		break;
	}
	case 5: { // Three nodes, delete first node
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.pop_at(0) == true);
		assert(l.num_nodes == 2);
		assert(l.head == second);
		assert(l.head->prev == nullptr);
		assert(l.tail == third);
		break;

	}
	case 6: { // Three nodes, delete last node
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.pop_at(2) == true);
		assert(l.num_nodes == 2);
		assert(l.head == first);
		assert(l.tail->next == nullptr);
		assert(l.tail == second);
		break;

	}
	case 7: { // Three nodes, delete middle node
		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = "first";
		first->prev = nullptr;
		first->next = second;

		second->item = "second";
		second->prev = first;
		second->next = third;

		third->item = "third";
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.pop_at(1) == true);
		assert(l.num_nodes == 2);

		assert(l.head == first);
		assert(l.tail == third);

		assert(l.head->next == third);
		assert(l.tail->prev == first);
		break;


	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}


int test_print(int testNum) {

	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		std::string test_string1("Tom Dick Mary\n"); //Without lagging space
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		List<std::string>::Node* first = new List<std::string>::Node;
		List<std::string>::Node* second = new List<std::string>::Node;
		List<std::string>::Node* third = new List<std::string>::Node;

		//Link together to make a valid linked list 
		first->item = test_vector[0];
		first->prev = nullptr;
		first->next = second;

		second->item = test_vector[1];
		second->prev = first;
		second->next = third;

		third->item = test_vector[2];
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

		l.print();
		std::cout.rdbuf(old);

		std::string text = buffer.str();

		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length());
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}



		break;

	}
	case 1: {

		std::string test_string1(""); //Without lagging space
		std::stringstream buffer(test_string1);
		std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
		buffer.str("");

		//Assume Constructor Correctly Implemented
		List<std::string> l;

		std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

		l.print();
		std::cout.rdbuf(old);

		std::string text = buffer.str();
		std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
			std::istream_iterator<std::string>() };

		assert(text.length() == test_string1.length() );
		assert(text == test_string1);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i] == test_vector[i]);
		}

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;

}
int test_size(int testNum) {

	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		assert(l.size() == 3);

		break;

	}
	case 1: {
		List<std::string> l;
		assert(l.size() == 0);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;

}

int test_copyCtor(int testNum) {

	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int> l;
		List<int> p(l);

		//Set up the initial state of the list to test
		assert(p.head==nullptr);
		assert(p.tail == nullptr);
		assert(p.num_nodes == 0);

		break;

	}

	case 1: {


		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;
		 
		List<int> p(l);

		assert(p.head != nullptr );
		assert(p.tail != nullptr);
		assert(p.num_nodes == 3);

		assert(p.head->item == first->item);
		assert(p.head->next->item == second->item);
		assert(p.tail->prev->item == second->item);
		assert(p.tail->item == third->item);

		assert(p.head != first);
		assert(p.tail != third);

		break;


	}
	case 2: {
		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		List<int> p(l);

		assert(p.head != nullptr);
		assert(p.tail != nullptr);
		assert(p.num_nodes == 3);

		assert(p.head->item == first->item);
		assert(p.head->next->item == second->item);
		assert(p.tail->prev->item == second->item);
		assert(p.tail->item == third->item);


		//check aliasing
		assert(p.head != first);
		assert(p.head != second);
		assert(p.head != third);

		assert(p.head->next != first);
		assert(p.head->next != second);
		assert(p.head->next != third);

		assert(p.tail != first);
		assert(p.tail != second);
		assert(p.tail != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;

}


int test_assgnOper(int testNum) {

	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {

		List<int> l;
		List<int> p;

		p = l;
		//Set up the initial state of the list to test

		assert(p.head == nullptr);
		assert(p.tail == nullptr);
		assert(p.num_nodes == 0);

		break;

	}

	case 1: {

		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		List<int> p;

		p = l;

		assert(p.head != nullptr);
		assert(p.tail != nullptr);
		assert(p.num_nodes == 3);

		assert(p.head->item == first->item);
		assert(p.head->next->item == second->item);
		assert(p.tail->prev->item == second->item);
		assert(p.tail->item == third->item);

		assert(p.head != first);
		assert(p.tail != third);

		break;


	}
	
	case 2: {
		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;

		List<int> p;

		p = l;

		assert(p.head != nullptr);
		assert(p.tail != nullptr);
		assert(p.num_nodes == 3);

		assert(p.head->item == first->item);
		assert(p.head->next->item == second->item);
		assert(p.tail->prev->item == second->item);
		assert(p.tail->item == third->item);


		//check aliasing
		assert(p.head != first);
		assert(p.head != second);
		assert(p.head != third);

		assert(p.head->next != first);
		assert(p.head->next != second);
		assert(p.head->next != third);

		assert(p.tail != first);
		assert(p.tail != second);
		assert(p.tail != third);

		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;

}


int test_mem_destructor(int testNum) {

	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		RESET();
		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		{
			List<int> l;

			//Set up the initial state of the list to test
			l.head = first;
			l.tail = third;
			l.num_nodes = 3;
		} //destructor

		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Destructor: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);

		break;

	}

	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;
}

int test_mem_assgnOper(int testNum) {

	std::cout << __func__ << testNum << std::endl << std::flush;
	switch (testNum) {
	case 0: {
		RESET();
		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;
		
		List<int> p;
		l = p;
		//GETMEMORYREPORT();
		if (SIZE() != 0) {
			std::cerr << "Assign Op: Memory Leak detected" << std::endl;
		}
		assert(SIZE() == 0);
		break;
	}
	case 1: {
		RESET();
		List<int>::Node* first = new List<int>::Node;
		List<int>::Node* second = new List<int>::Node;
		List<int>::Node* third = new List<int>::Node;

		//Link together to make a valid linked list 
		first->item = 2;
		first->prev = nullptr;
		first->next = second;

		second->item = 4;
		second->prev = first;
		second->next = third;

		third->item = 76;
		third->prev = second;
		third->next = nullptr;

		//Assume Constructor Correctly Implemented
		List<int> l;

		//Set up the initial state of the list to test
		l.head = first;
		l.tail = third;
		l.num_nodes = 3;
		//GETMEMORYREPORT();

		l = l;
		if (SIZE() != 3) {
			std::cerr << "Assign Op: Improper assignment" << std::endl;
		}
		assert(SIZE() == 3);
		break;
	}
	default:
		std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
		return -1;
		break;

	}
	return 0;

}

#endif
