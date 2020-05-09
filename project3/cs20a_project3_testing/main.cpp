

#include"linkedlisttests.h"

int main() {

	test_empty(0);
	test_empty(1);

	test_push_front(0); 
	test_push_front(1);

	test_push_back(0);
	test_push_back(1);

	test_add(0);
	test_add(1);
	test_add(2);
	test_add(3);
	test_add(4);
	test_add(5);
	test_add(6);
	
	test_find(0);
	test_find(1);

	test_front(0);
	test_front(1);
		
	test_rear(0);
	test_rear(1);
	
	test_get_at(0);
	test_get_at(1);
	
	test_pop_front(0);
	test_pop_front(1);
	test_pop_front(2);

	test_pop_rear(0);
	test_pop_rear(1);
	test_pop_rear(2);
	
	test_pop_at(0);
	test_pop_at(1);
	test_pop_at(2);
	test_pop_at(3);
	test_pop_at(4);
	test_pop_at(5);
	test_pop_at(6);
	test_pop_at(7);

	test_print(0);
	test_print(1);

	test_size(0);
	test_size(1);
	
	test_copyCtor(0);
	test_copyCtor(1);
	test_copyCtor(2);

	test_assgnOper(0);
	test_assgnOper(1);
	test_assgnOper(2);

	test_mem_destructor(0);
	test_mem_assgnOper(0);
	test_mem_assgnOper(1);
}

