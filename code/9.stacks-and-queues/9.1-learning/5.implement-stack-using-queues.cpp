// LEETCODE 225. Implement Stack using Queues
#include <iostream>
#include <queue>
using namespace std; //remove these 3 import if using online compiler


class MyStack {
    private:
        // approach: using single queue and stl
        // tc: push->O(n), other methods->O(1)
        // sc: O(n)?
        // queue that acts as a stack(lifo)
        queue<int> q;
    
    public:
        // empty constructor
        MyStack() {}
    
        /*
        - add element to queue
        - rotate all previous elements behind it by popping and pushing again
        - keeps most recent element at front (simulates LIFO ie stack)
        */
        void push(int x) {
            q.push(x);
            for (int i = 0; i < q.size() - 1; i++) {
                q.push(q.front());      // push the front element to the back
                q.pop();            // pop the front element
            }
        }
    
        // store top element, pop the element coz cpp stl pop only removes, doesnt
        // return top element
        int pop() {
            int topElement = q.front();
            q.pop();
            return topElement;
        }
    
        // return top element
        int top() { return q.front(); }
    
        // check if empty- true if it is empty
        bool empty() { return q.empty(); }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */