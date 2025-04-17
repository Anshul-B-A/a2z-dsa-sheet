/*
Implement Queue using Arrays
100
Hint
Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.
Examples:
Input:
["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]
[[], [5], [10], [], [], []]
Output: [null, null, null, 5, 5, false]
Explanation:
ArrayQueue queue = new ArrayQueue();
queue.push(5);
queue.push(10);
queue.peek(); // returns 5
queue.pop(); // returns 5
queue.isEmpty(); // returns false
Input:
["ArrayQueue", "isEmpty"]
[[]]
Output:[null, true]
Explanation:
ArrayQueue queue = new ArrayQueue();
queue.isEmpty(); // returns true
Input:
["ArrayQueue", "push", "pop", "isEmpty"]
[[], [1], [], []]
[null, null, 1, 1]
[null, null, 1, true]
[null, null, 1, false]
[null, null, 0, true]

Submit
Unlock Gamification Challenge

Access comprehensive solutions, in-depth editorials, and additional learning resources.

Upgrade to Plus
Constraints:
1 <= numbers of calls made <= 100
1 <= x <= 100
*/
class ArrayQueue {
    public:
        int size=100, front=-1, rear=-1, curSize=0;
        int q[100];
    
        ArrayQueue() {
        }
        
        void push(int x) {
            //full-empty-normal
            if(curSize == 100) return;
            else if(curSize == 0) //doing this coz circular queue
            {
                front=0;
                rear=0; 
            }
            else rear = (rear + 1) % 100;
            q[rear] = x;
            curSize++;
        }
        
        int pop() {
            //empty-singleElem-normal
            if(curSize==0) return -1;
            
            int elem = q[front];
            if(curSize==1)
            {
                front = rear = -1;
            }
            else 
            {
                front = (front + 1) % 100;
            }
            curSize--;
            return elem;
        }
        
        int peek() {
            //empty-normal
            if(curSize==0) return -1;
            return q[front];
        }
        
        bool isEmpty() {
            return (curSize==0);
        }
    };