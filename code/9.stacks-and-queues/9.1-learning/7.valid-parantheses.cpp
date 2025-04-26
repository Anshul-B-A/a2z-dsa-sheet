#include <iostream>
#include <stack>
#include <string>
using namespace std; //remove these 3 import if using online compiler
// leetcode 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
class Solution {
    public:
        // time, space: O(n)
        bool isValid(string s) {
            // using stack store last opening bracket encountered
            stack<char> st; // char stack to store opening brackets in LIFO manner
    
            //  iterate over input string
            for (char c : s) {
    
                // if opening brackets -> push to stack
                if (c == '(' || c == '[' || c == '{')
                    st.push(c);
    
                // else closing brackets
                else {
                    // no corresponding opening bracket for current closing bracket
                    // encountered in the input string
                    if (st.empty())
                        return false;
                    char ch = st.top(); // pop out most recent opening bracket to
                                        // compare with current closing bracket
                                        // character in the input string
                    st.pop();
                    // if opening and closing brackets match, then continue
                    // iterating over input string
                    if ((ch == '(' and c == ')') or (ch == '[' and c == ']') or
                        (ch == '{' and c == '}'))
                        continue;
                    //  else not matching, terminate execution by returning false as
                    //  they don't match
                    else
                        return false;
                }
            }
            //  if you reach end of string and at same time stack is empty -> it is
            //  valid parantheses; else if stack had opening brackets remaining ->
            //  not every opening bracket had a corresponding closing bracket
            return st.empty();
        }
    };