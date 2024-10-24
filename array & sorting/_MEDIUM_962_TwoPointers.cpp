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
		if nums length < 2: return 0
		otherwise:
			maxWidth = 0
			- initialize the rightMax array to storage the max value from each index to last element
			- asign the last element rightMax to the last of array nums
			- for loop from the second last element to the first element
				- asign each index to the max of rightMax on i+1 and nums on i

			- use pointer left and right both start from 0
			- initialize maxWidth to storage the max width ramp possible

			for loop on condition right less than n
				- if satisfied pointer left less than right and nums[left] greater than rightMax[right]
					- increment pointer left
				- update the maxWidth to the max of previous maxWidth and current width
				- increment right
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        int left = 0, right = 0, maxWidth = 0;
        while(right < n){
            while(left < right && nums[left] > rightMax[right]) left++;
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
};

/*
    Two pointers
    Time complexity: O(n)
    Space complexity: O(n)
    with n is the length of the rightMax array
*/

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