#include "container_structure.h"
#include <iostream>

using namespace std;

int main() {
    // Create an instance of the structure
    structure myStruct;

    // Add some elements to the structure
    myStruct.push_back(10);
    myStruct.push_back(20);
    myStruct.push_front(5);
    // Display the structure
    cout << "Structure contents: ";
    myStruct.display();


    
    // Remove an element from the structure
    myStruct.pop_back();
    // Display the structure again
    cout << "Structure contents after pop_back: ";
    myStruct.display();


    // Access elements using operator[]
    cout << "Element at index 0: " << myStruct[0] << endl;
    cout << "Element at index 1: " << myStruct[1] << endl;
    // Access elements using at()
    cout << "Element at index 0 using at(): " << myStruct.at(0) << endl;
    cout << "Element at index 1 using at(): " << myStruct.at(1) << endl;

    //add more elements to the structure
    myStruct.push_back(30);
    myStruct.push_back(40);
    myStruct.push_back(50);
    myStruct.push_back(1);
    // Display the structure again
    cout << "Structure contents after adding more elements: ";
    myStruct.display();

    
    myStruct.erase(0);
    myStruct.erase(0);
    myStruct.erase(2);
    myStruct.erase(0);
    myStruct.erase(0);
    myStruct.erase(0);
    cout << "Structure contents after Erasing more elements: ";
    myStruct.display();

    cout << "Structure contents after adding 1 more elements after repeated erasures: ";
    myStruct.push_back(1);
    myStruct.display();

    cout << "Structure contents after pop_back 1 element: ";
    myStruct.pop_back();
    myStruct.display();


    //add more elements to the structure
    myStruct.push_back(300);
    myStruct.push_back(90);
    myStruct.push_back(50);
    myStruct.push_back(1);
    // Display the structure again
    cout << "\n Structure contents after adding more elements: ";
    myStruct.display();
 

    // Sort the structure
    myStruct.sort();
    // Display the structure again
    cout << "Structure contents after sorting: ";
    myStruct.display();

    

    //pop front element from the structure
    myStruct.pop_front();
    myStruct.pop_front();
    myStruct.pop_front();
    myStruct.pop_front();
    // Display the structure again
    cout << "Structure contents after pop_fronting all: ";
    myStruct.display();

    // Check if the structure is empty
    cout << "Is the structure empty? " << (myStruct.empty() ? "Yes" : "No") << endl;

    //delete the structure
    myStruct.deleted();
    // Display the structure again  
    cout << "Structure contents after deletion: ";
    myStruct.display();
    
    //queue test
    queue myQueue;
    myQueue.push_back(10);
    myQueue.push_back(20);
    myQueue.push_back(30);
    cout << "\nQueue contents: ";
    myQueue.display();

    myQueue.pop_front();
    cout << "Queue contents after pop_front: ";
    myQueue.display();

    //is empty test
    cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    //delete the queue
    myQueue.deleted();
    cout << "Queue contents after deletion: ";  
    myQueue.display();

    //stack test
    stack myStack;
    myStack.push_back(10);
    myStack.push_back(20);
    myStack.push_back(30);
    cout << "\nStack contents: ";
    myStack.display();

    myStack.pop_back();
    cout << "Stack contents after pop_back: ";
    myStack.display();
    //is empty test
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;
    //delete the stack
    myStack.deleted();

    cout << "Stack contents after deletion: ";
    myStack.display();

    //add more elements to the stack
    myStack.push_back(100);
    myStack.push_back(200);
    cout << "Stack contents after adding more elements: ";
    myStack.display();

    //sort the stack
    myStack.sort();
    cout << "Stack contents after sorting: ";
    myStack.display();

    //pop all elements from the stack
    myStack.pop_back();
    myStack.pop_back(); 
    cout << "Stack contents after popping all elements: ";
    myStack.display();

    // Check if the stack is empty
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    //delete the stack
    myStack.deleted();
    cout << "Stack contents after deletion: ";
    myStack.display();

    //dequeue test
    dequeue myDequeue;
    myDequeue.push_back(10);
    myDequeue.push_back(20);
    myDequeue.push_back(30);
    cout << "\nDequeue contents: ";
    myDequeue.display();
    myDequeue.push_front(5);
    cout << "Dequeue contents after push_front: ";
    myDequeue.display();
    myDequeue.pop_front();
    cout << "Dequeue contents after pop_front: ";
    myDequeue.display();
    myDequeue.pop_back();
    cout << "Dequeue contents after pop_back: ";
    myDequeue.display();
    // Check if the dequeue is empty
    cout << "Is the dequeue empty? " << (myDequeue.empty() ? "Yes" : "No") << endl;
    //sort the dequeue
    myDequeue.sort();
    cout << "Dequeue contents after sorting: ";
    myDequeue.display();
    //[] operator test
    cout << "Element at index 0: " << myDequeue[0] << endl;
    cout << "Element at index 1: " << myDequeue[1] << endl;

    //at() operator test
    cout << "Element at index 0 using at(): " << myDequeue.at(0) << endl;
    cout << "Element at index 1 using at(): " << myDequeue.at(1) << endl;

    //delete the dequeue
    myDequeue.deleted();
    cout << "Dequeue contents after deletion: ";
    myDequeue.display();

    return 0;
}