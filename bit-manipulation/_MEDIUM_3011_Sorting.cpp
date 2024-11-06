#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        int prevMax = INT_MIN;
        int currMax = nums[0];
        int currMin = nums[0];
        int setBits = countBits(nums[0]);

        for (size_t i = 1; i < nums.size(); i++) {
            if (setBits == countBits(nums[i])) {
                currMax = std::max(currMax, nums[i]);
                currMin = std::min(currMin, nums[i]);
            } else {
                if (currMin < prevMax)
                    return false;

                prevMax = currMax;
                setBits = countBits(nums[i]);
                currMin = nums[i];
                currMax = nums[i];
            }
        }

        return currMin > prevMax;
    }

private:
    int countBits(int num) {
        return bitset<32>(num).count();
    }
};

int main() {
	Solution sol;
	vector<int> nums= {8,4,2,30,15};
	cout << sol.canSortArray(nums) << endl;
	return 0;
}