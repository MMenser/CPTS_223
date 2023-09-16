// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

#include "testQueue.h"

/*
1. Having the queue class along with it's function definitions and declarations in main.cpp clogs up main and makes it super hard to read.
    I would consider this poor practice, and this programmer should consider splitting up classes into their own header and cpp files. 

2. Class names should always be capitalized. When declaring the 'queue' class, it should really be declared as the 'Queue' class for simpiflication and 
    readiblity purposes.

3. In queue's implementation, the function size() is used redundantly in the isEmpty and isFull functions. There is a attribute count that is the exact same
    as size(), meaning that these functions could simply access the attribute count instead of calling size().

4. Using an array and queue's current implementaion means that there is a fixed amount of elements that the queue could have. Instead, a linked list would be better 
    so that there is no limit/capacity on number of elements. 

5. There are no comments explaining how the enqueue and dequeue mechanism actually work (taking the mod of capacity). It's confusing to read without comments, and the 
    programmer who made the algorithm should write comments about how the algorithm works so people don't have to track through it. 
*/

// main function
int main()
{
    // call your test functions here!

    std::cout << "Size() Test" << endl;
    testSize();
    std::cout << "\n\nisEmpty() Test" << endl;
    testEmpty();
    std::cout << "\n\nisFull() Test" << endl;
    testFull();
    std::cout << "\n\ndequeue() Test for Empty Q" << endl;
    testDeQWithEmptyQ();
    std::cout << "\n\ndequeue() Test for NonEmpty Q" << endl;
    testDeQWithNonEmptyQ();
    std::cout << "\n\nenqueue() Test for Full Q" << endl;
    testEnQWithFullQ();
    std::cout << "\n\nenqueue() Test for NonFull Q" << endl;
    testEnQWithNonFullQ();
    std::cout << "\n\npeek() Test for Empty Q" << endl;
    testPeekWithEmptyQ();
    std::cout << "\n\npeek() Test for NonEmpty Q" << endl;
    testPeekWithNonEmptyQ();


    return 0;
}

