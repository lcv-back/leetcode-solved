#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int minus = upper_bound(nums.begin(), nums.end(), -1)-nums.begin();
        int plus= lower_bound(nums.begin(), nums.end(), 1)-nums.begin();
        int Minus = minus;
        int Plus = nums.size()-plus;
        return max(Minus,Plus);
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1,1};
    cout<<s.maximumCount(nums)<<endl;
    return 0;
}