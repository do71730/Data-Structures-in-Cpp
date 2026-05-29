#include "structure.h"
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

    //erase an element from the structure
    myStruct.erase(1);
    // Display the structure again
    cout << "Structure contents after erasing index 1: ";
    myStruct.display();

    // Sort the structure
    myStruct.sort();
    // Display the structure again
    cout << "Structure contents after sorting: ";
    myStruct.display();

    //pop front element from the structure
    myStruct.pop_front();
    // Display the structure again
    cout << "Structure contents after pop_front: ";
    myStruct.display();

    //pop back element from the structure
    myStruct.pop_back();
    // Display the structure again
    cout << "Structure contents after pop_back: ";

    myStruct.display();

    // Check if the structure is empty
    cout << "Is the structure empty? " << (myStruct.empty() ? "Yes" : "No") << endl;

    //delete the structure
    myStruct.deleted();
    // Display the structure again  
    cout << "Structure contents after deletion: ";
    myStruct.display();

    return 0;
}