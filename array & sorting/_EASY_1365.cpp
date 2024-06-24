#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int count;
        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i]) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {8,1,2,2,3};
    vector<int> ans = s.smallerNumbersThanCurrent(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}