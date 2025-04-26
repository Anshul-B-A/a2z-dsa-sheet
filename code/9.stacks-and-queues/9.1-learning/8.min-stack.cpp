#include<stack>
using namespace std;
class MinStack {
    public:
        //brute- use stack of pair(int,int)=pair(value, globalMinValue)
        // tc:O(1), sc:(2N)
        stack<pair<int, int>> st; // {value, minValue till that part of stack}
        MinStack() {}
        
        void push(int val) {
            if(st.empty())
                st.push({val, val});
            else
                st.push({val, min(val, st.top().second)});
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            if(!st.empty()) return st.top().first;
            return -1;
        }
        
        int getMin() {
            if(!st.empty()) return st.top().second;
            return -1;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */

     class MinStack {
        // APPROACH 2: mathematical encoding
        // tc: O(1), sc: O(n)
        stack<long long> st;
        long long mini;
    public:
        MinStack() {
            mini = INT_MAX;
        }
        
        void push(int val) {
            long long value= val;
            if(st.empty()){
                mini = value;
                st.push(value);
            } else {
                if(value < mini){
                    st.push(2 * value - mini); //encode modified value
                    mini=value;
                } else 
                    st.push(value);
            }
        }
        
        void pop() {
            if(st.empty()) return;
            long long el = st.top();
            st.pop();
    
            if(el < mini)
                mini = 2 * mini - el; // decode previous mini
        }
        
        int top() {
            if(st.empty()) return -1;
    
            long long el = st.top();
            if(el < mini) return mini; //if encoded, actual top is mini
            return el;
        }
        
        int getMin() {
            return mini;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */