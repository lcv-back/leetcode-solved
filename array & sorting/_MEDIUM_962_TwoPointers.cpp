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