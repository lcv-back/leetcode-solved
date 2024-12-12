#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
	    sort(nums.begin(), nums.end());
	    int n = nums.size();

	    int maxBeauty = 1;
	    int i=0;
	    
	    for(int j=0; j<n; j++){
	    	while(nums[j]-nums[i] > 2 * k){
	    		i++;
	    	}

	    	maxBeauty = max(maxBeauty, j-i+1);
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