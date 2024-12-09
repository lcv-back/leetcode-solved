#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0); // Initialize prefix array with size n
        
        // Calculate the prefix array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }

        vector<bool> ans; // Result vector
        
        // Process the queries
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }

        return ans; // Return the result
    }
};

int main(){
	Solution sol;
	vector<int> nums1 = {3,4,1,2,6};
	vector<vector<int>> queries1 = {{0,4}};

	vector<int> nums2 = {4,3,1,6};
	vector<vector<int>> queries2 = {{0,2},{2,3}};

	vector<int> nums3 = {1,1};
	vector<vector<int>> queries3 = {{0,1}};

	vector<bool> arraySpecial = sol.isArraySpecial(nums3, queries3);
	for(bool x : arraySpecial){
		cout << x << ' ';
	}
	return 0;
}