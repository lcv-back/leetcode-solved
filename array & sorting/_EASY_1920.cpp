#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            nums[i] += n * (nums[nums[i]] % n);       
        }
        for(int i=0; i<n; i++) {
            nums[i] /= n;
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<int> ans = s.buildArray(nums);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}