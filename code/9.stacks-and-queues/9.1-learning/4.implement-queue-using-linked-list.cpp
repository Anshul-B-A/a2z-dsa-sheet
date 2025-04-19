/*
Implement queue using Linkedlist
100
Hint
Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support the following operations: push, pop, peek, and isEmpty.

Implement the LinkedListQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.
Examples:
Input:
["LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"]
[[], [3], [7], [], [], []]
Output:[null, null, null, 3, 3, false]
Explanation:
LinkedListQueue queue = new LinkedListQueue();
queue.push(3);
queue.push(7);
queue.peek(); // returns 3
queue.pop(); // returns 3
queue.isEmpty(); // returns false
Input:
["LinkedListQueue", "push", "pop", "isEmpty"]
[[], [2], [], []]
Output: [null, null, 2, true]
Explanation:
LinkedListQueue queue = new LinkedListQueue();
queue.push(2);
queue.pop(); // returns 2
queue.isEmpty(); // returns true
Input:["LinkedListQueue", "isEmpty"]
[[]]
[null, null, true, true]
[null, null, 2, false]
[null, 2, true]
[null, null, 2, true]


Constraints:
1 <= numbers of calls made <= 100
1 <= x <= 100
*/
// Definition of a single node in the linked list
class Node {
    public:
        int data;       // Value stored in the node
        Node* next;     // Pointer to the next node in the list
    
        // Constructor to initialize the node with a value and null next pointer
        Node(int value) {
            data = value;
            next = nullptr;
        }
    };
    
    // Queue implementation using a singly linked list
    class LinkedListQueue {
    public:
        Node* start;    // Points to the front of the queue
        Node* end;      // Points to the rear of the queue
        int size;       // Keeps track of the number of elements in the queue
    
        // Constructor to initialize an empty queue
        LinkedListQueue() {
            start = nullptr;
            end = nullptr;
            size = 0;
        }
        
        // Adds an element to the end of the queue
        void push(int x) {
            Node* temp = new Node(x);  // Create a new node with the given value
    
            // If the queue is empty, both start and end point to the new node
            if(start == nullptr){
                start = temp;
                end = temp;
            } else {
                end->next = temp;  // Link the new node at the end
                end = temp;        // Update the end pointer
            }
            size++;  // Increase the size of the queue
        }
        
        // Removes and returns the front element of the queue
        int pop() {
            if(start == nullptr) return -1;  // Return -1 if the queue is empty
    
            int res = start->data;       // Store the data to return
            Node* temp = start;          // Temporarily hold the front node
            start = start->next;         // Move the start pointer to the next node
            delete temp;                 // Free the memory of the removed node
    
            size--;                      // Decrease the size of the queue
            return res;                  // Return the removed value
        }
        
        // Returns the front element without removing it
        int peek() {
            if(start == nullptr) return -1;  // Return -1 if the queue is empty
            return start->data;              // Return the front element
        }
        
        // Checks if the queue is empty
        bool isEmpty() {
            return (size == 0);  // Return true if size is zero
        }
    };
    