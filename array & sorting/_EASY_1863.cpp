#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalSum = 0;
        backstrack(nums, 0, 0, totalSum);
        return totalSum;
    }

    void backstrack(vector<int>& nums, int index, int curSum, int& totalSum){
    	totalSum += curSum;
    	for(int i=index; i<nums.size(); i++){
    		backstrack(nums, i+1, curSum^nums[i], totalSum);
    	}
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3};
    cout<<s.subsetXORSum(nums)<<endl;
    return 0;
}