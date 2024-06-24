#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}