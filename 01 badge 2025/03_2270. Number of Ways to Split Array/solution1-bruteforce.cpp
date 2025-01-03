#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long left=0, right=0;
        int res=0;
        for(int i=0; i<nums.size(); i++) right += nums[i];
        for(int i=0; i<nums.size()-1; i++){
        	left += nums[i];
        	right -= nums[i];
        	if(left>=right) res++;
        }
        return res;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {10,4,-8,7};
	cout << sol.waysToSplitArray(nums) << endl;
	return 0;
}