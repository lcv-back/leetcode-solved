#include<iostream>
#include<vector>
using namespace std;

/*
define bad pair:
	(i,j) is bad pair if:
		+ i < j and j - i != nums[j] - nums[i]
constraint:
	+ 1 <= nums.l <= 10^5
	+ 1 <= nums[i] <= 10^9
	=> max size: 10^14
*/

class Solution {
public:
	// brute force
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        for(int i=0; i<nums.size(); i++){
        	for(int j=0; j<nums.size(); j++){
        		if(i < j && j-i != nums[j]-nums[i]){
        			res++;
        		}
        	}
        }
        return res;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {4,1,3,3};
	long long res = sol.countBadPairs(nums);
	cout << res;
	return 0;
}