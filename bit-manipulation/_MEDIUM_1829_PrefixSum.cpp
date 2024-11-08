#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];

        for(int i=1; i<n; i++)
        	prefixXOR[i] = prefixXOR[i-1] ^ nums[i];

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;

        for(int i=0; i<n; i++){
        	int currentXOR = prefixXOR[n-i-1];
        	ans[i] = currentXOR ^ mask;
        }

        return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {0,1,1,3};
	int maximumBit = 2;
	vector<int> res = sol.getMaximumXor(nums, maximumBit);
	for(int i : res) cout << i << " ";
	cout << endl;
	return 0;
}