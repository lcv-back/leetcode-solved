#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            int low = lower_bound(nums, i+1, nums.size()-1, lower - nums[i]);
            int high = lower_bound(nums, i+1, nums.size()-1, upper - nums[i]+1);
            ans += 1LL * (high-low);
        }
        return ans;
    }

    long long lower_bound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = low + ((high-low) / 2);
            if(nums[mid] >= target) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {0,1,7,4,4,5};
	int lower = 3;
	int upper = 6;
	cout << sol.countFairPairs(nums, lower, upper);
	cout << endl;
	return 0;
}