#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std; //remove these 3 import if using online compiler
// leetcode 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            // optimal: monotonic decreasing stack
            // tc: O(nums1.size() + nums2.size())
            // sc: stack+map together take O(nums2.size()), output vector takes
            // O(nums1.size())
            unordered_map<int, int> nge; // map from element to its nge
            stack<int> st;               // monotonic
            int n = nums2.size();
    
            // loop thru nums2
            for (int i = n - 1; i >= 0; i--) {
                // #1: check monotonicity in stack
                while (!st.empty() && st.top() <= nums2[i])
                    st.pop();
    
                // #2: fill nge from stack
                if (st.empty())
                    nge[nums2[i]] = -1;
                else
                    nge[nums2[i]] = st.top();
    
                // #3: fill stack from arr
                st.push(nums2[i]);
            }
    
            vector<int> ans;
            for (int num : nums1)
                ans.push_back(nge[num]);
            return ans;
        }
    };