#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longestStreak = 0;

       	// Set to keep track of numbers we've already processed
       	set<int> processedNumbers;

       	for(int current : nums){
       		if(processedNumbers.find(current) != processedNumbers.end()) continue;

       		int streak = current;
       		int streakLength = 1;

       		while(true){
       			if((long long) streak * (long long) streak > 1e5) break;

       			if(binarySearch(nums, streak * streak)){
       				streak *= streak;
       				processedNumbers.insert(streak);
       				streakLength++;
       			} else break;
       		}

       		// update the longest streak if necessary
       		longestStreak = max(longestStreak, streakLength);

       	}

       	return longestStreak < 2 ? -1 : longestStreak;
    }
private:
	// Binary search helper function to efficiently find a value in the sorted array
	bool binarySearch(vector<int>& nums, int target){
		if(target < 0) return false;

		int left = 0;
		int right = nums.size() - 1;

		while(left <= right){
			int mid = (left + right) / 2;
			if(nums[mid] == target) return true;
			if(nums[mid] < target) 
				left = mid+1;
			else
				right = mid-1;
		}
		
		return false;
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
	vector<int> nums = {4,3,6,16,8,2};
	cout << sol.longestSquareStreak(nums) << endl;
	return 0;
}