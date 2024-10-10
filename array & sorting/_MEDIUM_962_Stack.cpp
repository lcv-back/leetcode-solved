#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;
        stack<int> st;

        // fill to the stack
        for(int i=0; i<n; i++) 
            if(st.empty() || nums[i] < nums[st.top()]) st.push(i);

        // traversal from the end to the start
        for(int i=n-1; i>0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]){
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main(){
    Solution sol;
    vector<int> nums1 = {6,0,8,2,1,5};
    cout << sol.maxWidthRamp(nums1) << endl; // Output: 3

    vector<int> nums2 = {9,8,1,0,1,9,4,0,4,1};
    cout << sol.maxWidthRamp(nums2) << endl; // Output: 2
    return 0;
}