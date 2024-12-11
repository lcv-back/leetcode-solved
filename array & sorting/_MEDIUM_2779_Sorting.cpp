#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
	    sort(nums.begin(), nums.end());
	    
	    unordered_map<int, int> count;
	    int maxBeauty = 1;
	    
	    for (int i = 0; i < nums.size(); ++i) {
	        int lowerBound = nums[i] - k;
	        int upperBound = nums[i] + k;
	        
	        for (int j = lowerBound; j <= upperBound; ++j) {
	            count[j]++;
	            maxBeauty = max(maxBeauty, count[j]);
	        }
	    }
	    
	    return maxBeauty;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {4,6,1,2};
	int k = 2;
	cout << sol.maximumBeauty(nums, k) << endl;
}