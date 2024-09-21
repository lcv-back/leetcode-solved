#include<bits/stdc++.h>
using namespace std;

/*
	description: 
		- Given a 0-indexed integer array nums of size n and two integers lower and upper, 
		return the number of fair pairs.
		- A pair (i, j) is fair if:
			- 0 <= i < j < n, and
			- lower <= nums[i] + nums[j] <= upper
*/

/*
	solution:
		traversal of nums
		check lower and upper
*/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) 
    {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            int lb=lower_bound(nums.begin()+i+1,nums.end(),l-nums[i])-nums.begin();
            int ub=upper_bound(nums.begin()+i+1,nums.end(),u-nums[i])-nums.begin();
            if(ub>=lb)ans+=ub-lb;
        }
        return ans;
        
    }
};

int main(){
	Solution sol;
	vector<int> nums = {0,1,7,4,4,5};
	int lower = 3;
	int upper = 6;
	long long result = sol.countFairPairs(nums, lower, upper);
	cout << result;
}
