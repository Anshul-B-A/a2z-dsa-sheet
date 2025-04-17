/*
Implement Stack using Arrays
100
Hint
Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the top element of the stack.
int top(): Returns the top element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.



Please note that this section might seem a bit difficult without prior knowledge on what stacks is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!
Examples:
Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
[[], [5], [10], [], [], []]
Output: [null, null, null, 10, 10, false]
Explanation:
ArrayStack stack = new ArrayStack();
stack.push(5);
stack.push(10);
stack.top(); // returns 10
stack.pop(); // returns 10
stack.isEmpty(); // returns false
Input: ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]
[[], [], [1], [], []]
Output: [null, true, null, 1, true]
Explanation: 
ArrayStack stack = new ArrayStack();
stack.push(1);
stack.pop(); // returns 1
stack.isEmpty(); // returns true
Input: ["ArrayStack", "isEmpty"]
[[], []]
[null, true]
[null, false]
[false, false]
[true, true]

Submit
Unlock Gamification Challenge

Access comprehensive solutions, in-depth editorials, and additional learning resources.

Upgrade to Plus
Constraints:
1 <= numbers of calls made <= 100
1 <= x <= 100
*/

class ArrayStack {
    public:
     //int ST_SIZE = 100;
     int st[100];
     int ptr;
 
     ArrayStack() {
         ptr = -1;
     }
 
     void push(int x) {
         if (ptr+1 >= 100) return;
         st[++ptr] = x;
     }
 
     int pop() {
         if (ptr == -1) return -1;
         return st[ptr--];
     }
 
     int top() {
         if (ptr == -1) return -1;
         return st[ptr];
     }
 
     bool isEmpty() {
         return ptr==-1;
     }
 };