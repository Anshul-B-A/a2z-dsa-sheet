/*
Implement stack using Linkedlist
100
Hint
Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support the following operations: push, pop, top, and isEmpty.

Implement the LinkedListStack class:

void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the top element of the stack.
int top(): Returns the top element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.
Examples:
Input:
["LinkedListStack", "push", "push", "pop", "top", "isEmpty"]
[[], [3], [7], [], [], []]

Output: [null, null, null, 7, 3, false]
Explanation:
LinkedListStack stack = new LinkedListStack();
stack.push(3);
stack.push(7);
stack.pop(); // returns 7
stack.top(); // returns 3
stack.isEmpty(); // returns false
Input:
["LinkedListStack", "isEmpty"]
[[]]

Output: [null, true]
Explanation:
LinkedListStack stack = new LinkedListStack();
stack.isEmpty(); // returns true
Input:
["LinkedListStack", "push", "pop", "isEmpty"]
[[], [2], [], []]
[null, null, true, true]
[null, null, 2, false]
[null, 2, true]
[null, null, 2, true]


Constraints:
1 <= numbers of calls made <= 100
1 <= x <= 100
*/

class stackNode {
    public:
     int data;
     stackNode* next;
 
     stackNode(int x) {
         data = x;
         next = nullptr;
     }
 };
 class LinkedListStack {
    public:
     int curSize = 0;
     stackNode* ptr = nullptr;
     LinkedListStack() {}
 
     void push(int x) {
         stackNode* temp = new stackNode(x);
         temp->next = ptr;
         ptr = temp;
         curSize++;
     }
 
     int pop() {
         if (ptr == nullptr) return -1;
         int topData = ptr->data;
 
         stackNode* temp = ptr;
         ptr = ptr->next;
         delete temp;
 
         curSize--;
         return topData;
     }
 
     int top() {
         if (ptr == nullptr) return -1;
         return ptr->data;
     }
 
     bool isEmpty() { return (curSize == 0); }
 };