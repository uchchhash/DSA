#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Declaring a priority queue
    priority_queue<int> myPQ; // Default is a max-heap (largest element has the highest priority)

    // Adding elements to the priority queue using push
    myPQ.push(30); // Adds 30 to the queue
    myPQ.push(10); // Adds 10 to the queue
    myPQ.push(20); // Adds 20 to the queue

    // Visualizing the Priority Queue after push operations:
    // -------------------------------------------------
    //   | 30 |   <----- top()
    // -------------------------------------------------
    //   | 10 |   
    // -------------------------------------------------
    //   | 20 |   
    // -------------------------------------------------

    // Accessing the top element (highest priority)
    cout << "Top element (highest priority): " << myPQ.top() << endl; // Should print 30

    // Displaying the size of the priority queue
    cout << "Size of the priority queue: " << myPQ.size() << endl; // Size is 3

    // Removing elements from the priority queue
    myPQ.pop(); // Removes the top element (30)

    // Visualizing the Priority Queue after pop operation:
    // -------------------------------------------------
    //   | 20 |   <----- top()
    // -------------------------------------------------
    //   | 10 |   
    // -------------------------------------------------

    // Displaying the top element after popping
    cout << "After popping, top element: " << myPQ.top() << endl; // Should now print 20
    cout << "Size of the priority queue after popping: " << myPQ.size() << endl; // Size is 2

    // Adding more elements to the priority queue
    myPQ.push(50); // Adds 50 to the queue
    myPQ.push(5);  // Adds 5 to the queue

    // Visualizing the Priority Queue after adding more elements:
    // -------------------------------------------------
    //   | 50 |   <----- top()
    // -------------------------------------------------
    //   | 20 |   
    // -------------------------------------------------
    //   | 10 |   
    // -------------------------------------------------
    //   | 5  |   
    // -------------------------------------------------

    // Displaying the current state of the priority queue
    cout << "Current top element: " << myPQ.top() << endl; // Should print 50
    cout << "Size of the priority queue: " << myPQ.size() << endl; // Size should be 4

    // Removing elements from the priority queue until it is empty
    while (!myPQ.empty()) {
        cout << "Removing top element: " << myPQ.top() << endl; // Print and remove the top element
        myPQ.pop(); // Removes the top element
    }

    // Check if the priority queue is empty now
    cout << "Size of the priority queue after clearing: " << myPQ.size() << endl; // Size should be 0
    cout << "Is the priority queue empty now? " << (myPQ.empty() ? "Yes" : "No") << endl; // Should print "Yes"

    return 0;
}
