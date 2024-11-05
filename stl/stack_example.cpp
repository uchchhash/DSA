#include <iostream>
#include <stack>

// LAST IN FIRST OUT :: LIFO

int main() {
    // Declare a stack of integers
    std::stack<int> myStack;

    // Visualizing the Stack before any operations:
    // ---------------------------------------------
    // |      | stack.top()
    // |      | 
    // |      | 
    // |      | 
    // |______| 
    // (empty stack)
    // ---------------------------------------------

    // Push elements onto the stack
    myStack.push(10); // Adding 10 to the stack
    // Visualizing the Stack after push operation:
    // ---------------------------------------------
    // |  10  | stack.top()
    // |      | 
    // |      | 
    // |      | 
    // |______| 
    // ---------------------------------------------

    myStack.push(20); // Adding 20 to the stack
    // Visualizing the Stack after push operation:
    // ---------------------------------------------
    // |  20  | stack.top()
    // |  10  | 
    // |      | 
    // |      | 
    // |______| 
    // ---------------------------------------------

    myStack.push(30); // Adding 30 to the stack
    // Visualizing the Stack after push operation:
    // ---------------------------------------------
    // |  30  | stack.top()
    // |  20  | 
    // |  10  | 
    // |      | 
    // |______| 
    // ---------------------------------------------

    // Display the top element
    std::cout << "Top element is: " << myStack.top() << std::endl; // Output: 30

    // Size of the stack
    std::cout << "Size of stack: " << myStack.size() << std::endl; // Output: 3

    // Pop the top element
    myStack.pop(); // Removing the top element (30)
    // Visualizing the Stack after pop operation:
    // ---------------------------------------------
    // |  20  | stack.top()
    // |  10  | 
    // |      | 
    // |      | 
    // |______| 
    // ---------------------------------------------
    
    std::cout << "After popping, top element is: " << myStack.top() << std::endl; // Output: 20

    // Checking if the stack is empty
    if (!myStack.empty()) {
        std::cout << "Stack is not empty." << std::endl; // Output: Stack is not empty.
    }

    // Pop all elements from the stack
    myStack.pop(); // Removing 20
    myStack.pop(); // Removing 10

    // Now the stack should be empty
    std::cout << "Size of stack after popping all elements: " << myStack.size() << std::endl; // Output: 0

    // Checking if the stack is empty again
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl; // Output: Stack is empty.
    }

    return 0;
}
