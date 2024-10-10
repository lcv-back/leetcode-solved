#include <iostream>
#include <vector>

using namespace std;

/*
	input: given an integer array nums
	output: the max width of ramp in nums, no ramp in nums return 0
	which i < j and nums[i] <= nums[j]. The width of ramp is j - i 
	contraints:
		- 2 <= nums.length <= 5 * 10^4
		- 0 <= nums[i] <= 5 * 10^4
	processing:
		brute force:
			- if length the nums less than 2, return 0
			- otherwise:
				maxWidth = -1;
				for loop from i=0 to nums.length - 1:
					for loop from j=i+1 to nums.length - 1:
						if(j > i and nums[j] >= nums[i])
							maxWidth = max(maxWidth, j - i)
				return maxWidth
			


*/

class Solution {
public:
	/* 
		Brute force 
		Time complexity: O(n^2)
		Space complexity: O(n)
		with n is the length of the array
	*/
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int maxWidth = -1;
        for(int i=0; i<n; i++){
        	for(int j=i+1; j<n; j++){
        		if(j > i && nums[j] >= nums[i])
        			maxWidth = max(maxWidth, j-i);
        	}
        }
        return maxWidth;
    }
};

auto init = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
};

int main(){
	vector<int> nums1 = {6,0,8,2,1,5};
	Solution sol;
	cout << sol.maxWidthRamp(nums1) << endl;

	vector<int> nums2 = {9,8,1,0,1,9,4,0,4,1};
	cout << sol.maxWidthRamp(nums2) << endl; 
	return 0;
}