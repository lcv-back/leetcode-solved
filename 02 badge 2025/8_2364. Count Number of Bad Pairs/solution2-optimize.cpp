#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int, int> map;
		long long goodPairs = 0;

		for(int j=0; j<n; j++){
			int key = j - nums[j];
			if(map.find(key) != map.end()){
				goodPairs += map[key];
			}

			if(map.find(key) != map.end()){
				map[key] += 1;
			} else {
				map[key] = 1;
			}
		}

		long long totalPairs = (long long)n * (n-1) / 2;
		long long badPairs = (long long) totalPairs - goodPairs;

		return badPairs;        
    }
};

int main(){
	Solution sol;
	vector<int> nums = {4,1,3,3};
	long long res = sol.countBadPairs(nums);
	cout << res;
	return 0;
}