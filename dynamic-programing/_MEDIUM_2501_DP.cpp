#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

/*
	Description:
		Given an integer array
		Return the length of the longest square streak in array, otherwise return -1

	Explain:
		A subsequence of array is called a square streak if:
			The length of the subsequence is at least 2
			After sorting the subsequence, each element is the square of the previous number

	Constraints:
		2 <= nums.length <= 10^5
		2 <= nums[i] <= 10^5
*/
/*
    Optimized Solution:
    Time Complexity: O(n) where n is the length of nums
    Space Complexity: O(n) for the hashset
    
    The original solution:
    - Time: O(n log n) due to sorting
    - Space: O(n) for storing perfect squares array and set
    
    Improvements made:
    1. Eliminate the need for sorting by using a hashset approach
    2. Remove the separate perfect squares array
    3. Process numbers directly without pre-filtering perfect squares
    4. Calculate streaks in a single pass through the data
    
    Key idea:
    - For each number x, check if x is part of a streak by looking for x^2
    - Use hashset for O(1) lookups
    - Track the longest streak by starting from smallest numbers
*/


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
		unordered_set<int> numSet(nums.begin(), nums.end());
		int longestStreak = -1;
		
		// For each number, try to find the longest streak starting from it
		for (int num : nums) {
			// Skip if we've already found a longer streak starting from a smaller number
			if (numSet.find(sqrt(num)) != numSet.end()) {
				continue; // This number is part of a streak starting from a smaller number
			}
			
			// Try to build a streak starting from this number
			long long current = num;
			int currentStreak = 1;
			
			while (current <= INT_MAX && numSet.find(current * current) != numSet.end()) {
				current = current * current;
				currentStreak++;
			}
			
			if (currentStreak >= 2) {
				longestStreak = max(longestStreak, currentStreak);
			}
		}
		
		return longestStreak;
	}
};

auto init = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
};

int main(){
	Solution sol;

	cout << "testcase1: ";
	vector<int> testcase1 = {4,3,6,16,8,2};
	string resForTC1 = "";
	if(sol.longestSquareStreak(testcase1) == 3) cout << "pass";
	else cout << "fail";
	cout << endl;

	cout << "testcase2: ";
	vector<int> testcase2 = {2,3,5,6,7};
	if(sol.longestSquareStreak(testcase2) == -1) cout << "pass";
	else cout << "fail";
	cout << endl;

	cout << "testcase3: ";
	vector<int> testcase3 = {2,4};
	if(sol.longestSquareStreak(testcase3) == 2) cout << "pass";
	else cout << "fail";
	cout << endl;

	cout << "testcase4: ";
	vector<int> testcase4 = {4,5,4};
	if(sol.longestSquareStreak(testcase4) == -1) cout << "pass";
	else cout << "fail";
	cout << endl;

	cout << "testcase5: ";
	vector<int> testcase5 = {10,2,13,16,8,9,13};
	if(sol.longestSquareStreak(testcase5) == -1) cout << "pass";
	else cout << "fail";
	cout << endl;

	cout << "testcase6: ";
	vector<int> testcase6 = {17,19,4,17,10,18,9,3,14};
	if(sol.longestSquareStreak(testcase6) == 2) cout << "pass";
	else cout << "fail";
	cout << endl;
	return 0;
}