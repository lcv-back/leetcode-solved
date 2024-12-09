#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool checkEven(int num){
		return num % 2 == 0;
	}

	vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries){
		if(nums.size() <= 1 && queries.size() == 1) return {true};
		vector<bool> res;
		for(int i=0; i<queries.size(); i++){
			vector<int> cur = queries[i];

			// handle special cases
			if(cur[0] == cur[1]){
				res.push_back(true);
				continue;
			}

			if(cur[0] < 0 || cur[1] >= nums.size()){
				res.push_back(false);
				continue;
			}

			bool isSpecial = true;
			bool isEven = false, isOdd = false;
			bool prev = checkEven(nums[cur[0]]);
			int isFlag = 0;
			for(int x = cur[0]+1; x <= cur[1]; x++){
				bool curEven = checkEven(nums[x]);
				if(curEven == prev){
					isSpecial = false;
					break;
				}
				prev = checkEven(nums[x]);
			}
			res.push_back(isSpecial);
		}

		return res;
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