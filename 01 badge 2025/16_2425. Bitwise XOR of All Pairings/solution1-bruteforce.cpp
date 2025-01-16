#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int res = 0;
        vector<int> nums3;

        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		nums3.push_back(nums1[i] ^ nums2[j]);
        	}
        }

        for(int i=0; i<nums3.size(); i++){
        	res ^= nums3[i];
        }

        return res;
    }
};

// Time: O(m*n) with m is length nums1 and n is length nums2

int main(){
	Solution sol;
	vector<int> nums1 = {2,1,3};
	vector<int> nums2 = {10,2,5,0};
	cout << sol.xorAllNums(nums1, nums2) << endl;
	return 0;
}