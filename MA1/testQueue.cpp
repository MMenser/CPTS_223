#include "queue.h"

#include "testQueue.h"

void testSize() {
	queue q;

	if (q.size() == 0) {
		std::cout << "Test passed!" << endl;
	}
	else {
		std::cout << "Test failed! :(" << endl;
	}

}
/*
Test ID : Size of queue check
Unit : queue::size()
Description : test to determine if queue::size() returns the correct size 
Test steps :
1. Construct an empty queue object 
2. Invoke queue::isSize()
3. Conditionally evaluate the valued returned by queue::size()
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object is still empty
Expected result : size is 0
Actual result : size is not 0
Status : failed
*/


void testEmpty() {
	queue q(0);

	if (q.isEmpty() == true) {
		std::cout << "Test passed!" << endl;
	}
	else {
		std::cout << "Test failed! :(" << endl;
	}
}
/*
TestID : Empty queue check
Unit : queue::isEmpty()
Description : test to determine if queue::isEmpty() returns 1 if a
queue object is empty
Test steps :
1. Construct an empty queue object
2. Invoke queue::isEmpty()
3. Conditionally evaluate the valued returned by
queue::isEmpty()
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object is still empty
Expected result : queue is empty; true is returned
Actual result : queue is empty; false is returned
Status : failed
*/

void testFull() {
	queue q(5);
	if (q.isFull() == false) {
		std::cout << "Test passed!" << endl;
	}
	else {
		std::cout << "Test failed! :(" << endl;
	}
}
/*
Test ID : Full queue check - EQC
Unit : queue::isFull()
Description : test to determine if queue::isFull() returns false if a
queue object is not full
Test steps :
1. Construct an empty queue object
2. Invoke queue::isFull()
3. Conditionally evaluate the valued returned by
queue::isFull()
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object is still empty
Expected result : queue is empty; false is returned
Actual result : queue is empty; false is returned
Status : passed
*/

void testDeQWithEmptyQ() {
	queue q(5);
	std::cout << "Expected: UnderFlow\nProgram Terminated\n" << endl;
	std::cout << "Result: ";
	q.dequeue();
}
/*
Test ID : Dequeue with empty queue
Unit : queue::dequeuel()
Description : test to determine if queue::dequeue() returns an error message
Test steps :
1. Construct an empty queue object
2. Invoke queue::dequeue()
3. Conditionally evaluate the valued returned by
queue::dequeue()
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object is still empty
Expected result : print to console: UnderFlow\nProgram Terminated\n
Actual result : print to console: Removing (memory address)
Status : failed
*/


void testDeQWithNonEmptyQ() {
	queue q(5);
	q.enqueue(1);
	std::cout << "Expected: Removing 1" << endl;
	std::cout << "Result: ";
	q.dequeue();
}
/*
Test ID : Dequeue with nonempty queue
Unit : queue::dequeue()
Description : test to determine if queue::dequeue() correctly dequeues an element
Test steps :
1. Construct an empty queue object
2. Enqueue an element in the queue object
3. Invoke queue::dequeue()
4. Conditionally evaluate the valued returned by
queue::dequeue()
Test data : size = 1
Precondition : object contains one element
Postcondition : queue object is empty
Expected result : print to console: Removing 1
Actual result : print to console: Removing 1
Status : sucess
*/
void testEnQWithNonFullQ() {
	queue q(5);
	
	std::cout << "Expected: Inserting 1" << endl;
	std::cout << "Result: ";
	q.enqueue(1);
}
/*
Test ID : Enqueue with nonfull queue
Unit : queue::enqueue()
Description : test to determine if queue::enqueue() correctly inserts an element in a non empty queue
Test steps :
1. Construct an empty queue object
2. Invoke queue::enqueue()
3. Conditionally evaluate the valued returned by queue::enqueue()
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object has one element
Expected result : print to console: Inserting 1
Actual result : print to console: Inserting 1
Status : sucess
*/
void testEnQWithFullQ() {
	queue q(2);
	q.enqueue(1);
	q.enqueue(2);
	std::cout << "Expected: UnderFlow\nProgram Terminated\n" << endl;
	std::cout << "Result: ";
	q.enqueue(3);
}
/*
Test ID : Enqueue with full queue
Unit : queue::enqueue()
Description : test to determine if queue::enqueue() correctly prints an error message
Test steps :
1. Construct an empty queue object with size 2
2. Invoke queue::enqueue() twice so that the queue is full
3. Invoke queue:enqueue()
3. Conditionally evaluate the valued returned by queue::enqueue()
Test data : size = 2
Precondition : queue object is full with 2 elements
Postcondition : queue object is full with 2 elements
Expected result : print to console: UnderFlow\nProgram Terminated\n
Actual result : print to console:UnderFlow\nProgram Terminated\n
Status : sucess
*/

void testPeekWithEmptyQ() {
	queue q(2);
	std::cout << "Expected: UnderFlow\nProgram Terminated\n" << endl;
	std::cout << "Result: ";
	q.peek();
}
/*
Test ID : Peek with empty queue
Unit : queue::peek()
Description : test to determine if queue::peek() correctly prints an error message
Test steps :
1. Construct an empty queue object
3. Invoke queue:peek()
3. Conditionally evaluate the valued returned by queue::enqueue()
Test data : size = 0
Precondition : queue object is empty
Postcondition : queue object is empty
Expected result : print to console: UnderFlow\nProgram Terminated\n
Actual result : print to console: 
Status : failed
*/
void testPeekWithNonEmptyQ() {
	queue q(3);
	q.enqueue(1);
	q.enqueue(2);
	if (q.peek() == 1) {
		std::cout << "Test passed!" << endl;
	}
	else {
		std::cout << "Test failed! :(" << endl;
	}

}
/*
Test ID : Peek with nonempty queue
Unit : queue::peek()
Description : test to determine if queue::peek() correctly returns 1
Test steps :
1. Construct an empty queue object
2. Enqueue element 1
3. Enqueue element 2
4. Invoke queue:peek()
5. Conditionally evaluate the valued returned by queue::enqueue()
Test data : size = 0
Precondition : queue object has two elements
Postcondition : queue object has two elements
Expected result : peek() returns 1
Actual result : peek() doesn't return 1
Status : failed
*/