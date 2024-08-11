#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting nums
        vector<vector<int>> result;
        int n = nums.size();
        
        for(int i = 0; i < n - 2; i++) { // size: n-2 because need to keep 2 element to plus equal 0
            if(i > 0 && nums[i] == nums[i-1]) continue; // remove duplicate elements
            
            int newTarget = 0 - nums[i]; // keep first element of 3
            unordered_map<int, int> map; // use map to reduce time comlexity
            
            for(int j = i + 1; j < n; j++) { // finding after i
                int complement = newTarget - nums[j]; // keep second element of 3
                if(map.count(complement)) { // finding the last element of 3
                    result.push_back({nums[i], complement, nums[j]}); // push 3 elements into result vector
                    
                    while(j + 1 < n && nums[j] == nums[j + 1]) j++; // remove duplicate element after found the triplet
                }
                map[nums[j]] = j; // store nums[j] element
            }
        }
        
        return result;
    }
};

// time: O(n^2)
// space: O(n) needed to store all the elements of result

int main(){
	Solution sol;
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> result = sol.threeSum(nums);
	for(int i=0; i < result.size(); i++){
		for(int j=0; j < result[0].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
