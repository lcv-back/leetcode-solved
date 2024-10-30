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

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longestStreak = 0;
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());
        for (int startNumber : nums) {
            int currentStreak = 0;
            long long current = startNumber;

            while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
                currentStreak++;
                if (current * current > 1e5) break;

                current *= current;
            }

            // Update the longest streak if necessary
            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak < 2 ? -1 : longestStreak;
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