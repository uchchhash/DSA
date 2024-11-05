#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Declaring a queue
    queue<int> myQueue; // FIFO: First In, First Out

    // Adding elements to the queue using push and emplace
    myQueue.push(10);   // Adds 10 to the back of the queue
    myQueue.emplace(20); // Constructs and adds 20 to the back of the queue
    myQueue.push(30);   // Adds 30 to the back of the queue

    // Visualizing the Queue after push operations:
    // -------------------------------------------------
    //   | 10 | 20 | 30 |   <----- back()
    // -------------------------------------------------
    //       | 
    //       | front()
    // -------------------------------------------------

    // Accessing elements
    cout << "Front element: " << myQueue.front() << endl; // Accesses the first element (10)
    cout << "Back element: " << myQueue.back() << endl;   // Accesses the last element (30)

    // Displaying the size of the queue
    cout << "Size of the queue: " << myQueue.size() << endl; // Size is 3

    // Removing elements from the queue
    myQueue.pop(); // Removes the front element (10)

    // Visualizing the Queue after pop operation:
    // -------------------------------------------------
    //   | 20 | 30 |   <----- back()
    // -------------------------------------------------
    //       | 
    //       | front()
    // -------------------------------------------------

    // Displaying elements after popping
    cout << "After popping, front element: " << myQueue.front() << endl; // Now front is 20
    cout << "Size of the queue after popping: " << myQueue.size() << endl; // Size is 2

    // Adding more elements
    myQueue.push(40); // Adds 40 to the back of the queue
    myQueue.push(50); // Adds 50 to the back of the queue

    // Visualizing the Queue after adding more elements:
    // -------------------------------------------------
    //   | 20 | 30 | 40 | 50 |   <----- back()
    // -------------------------------------------------
    //       | 
    //       | front()
    // -------------------------------------------------

    // Displaying the current state of the queue
    cout << "Current front element: " << myQueue.front() << endl; // Should print 20
    cout << "Current back element: " << myQueue.back() << endl;   // Should print 50
    cout << "Size of the queue: " << myQueue.size() << endl; // Size should be 4

    // Removing elements from the queue until it is empty
    while (!myQueue.empty()) {
        cout << "Removing front element: " << myQueue.front() << endl; // Print and remove the front element
        myQueue.pop(); // Removes the front element
    }

    // Check if the queue is empty now
    cout << "Size of the queue after clearing: " << myQueue.size() << endl; // Size should be 0
    cout << "Is the queue empty now? " << (myQueue.empty() ? "Yes" : "No") << endl; // Should print "Yes"

    return 0;
}
