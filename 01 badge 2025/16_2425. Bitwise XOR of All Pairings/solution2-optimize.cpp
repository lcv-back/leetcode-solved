#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        if(nums1.size() % 2 == 1){
            for(int n : nums2) res ^= n;
        }
        if(nums2.size() % 2 == 1){
            for(int n : nums1) res ^= n;
        }
        return res;
    }
};

// Time: O(n)

int main(){
	Solution sol;
	vector<int> nums1 = {2,1,3};
	vector<int> nums2 = {10,2,5,0};
	cout << sol.xorAllNums(nums1, nums2) << endl;
	return 0;
}