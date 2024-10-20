#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count) {
        if (currentOR == maxOR) count++;
        for (int i = index; i < nums.size(); ++i) backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
    }

    int countMaxOrSubsets(vector<int> &nums) {
        int maxOR = 0;

        // Step 1: Compute the maximum OR
        for (int num : nums) maxOR |= num;

        int count = 0;
        // Step 2: Backtrack to count the subsets
        backtrack(nums, 0, 0, maxOR, count);

        return count;
    }
};

/*
    Time complexity: 2^n and Space complexity: O(n)
*/

int main(){
    Solution sol;
    vector<int> nums1 = {3,1};
    vector<int> nums2 = {2,2,2};
    vector<int> nums3 = {3,2,1,5};

    cout << "Test case 1 result: " << sol.countMaxOrSubsets(nums1) << endl; // Output: 2
    cout << "Test case 2 result: " << sol.countMaxOrSubsets(nums2) << endl; // Output: 7
    cout << "Test case 3 result: " << sol.countMaxOrSubsets(nums3) << endl; // Output: 6
    return 0;
}