#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        int curMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            res = max(res, (curMax - 1) * (nums[i] - 1));
            curMax = max(curMax, nums[i]);
        }

        return res;        
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,-2,4};
    cout << s.maxProduct(nums) << endl;
    return 0;
}