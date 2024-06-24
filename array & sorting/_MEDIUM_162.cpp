#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        int a;
        for (int i = 0; i < n; i++) {
            if (i == 0 && nums[i] > nums[i + 1]) {
                return i;
            } else if (i == n - 1 && nums[i] > nums[i - 1]) {
                return i;
            } else if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
                return i;
            }
        }
        return a;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout<<s.findPeakElement(nums)<<endl;
    return 0;
}