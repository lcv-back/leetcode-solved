#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncFlag=0;
        if(nums[0]<nums[nums.size()-1]) isIncFlag=1;
        else isIncFlag=0;

        if(isIncFlag){
        	for(int i=0; i<nums.size()-1; i++) if(nums[i]>nums[i+1]) return false; 
        } else{
        	for(int i=0; i<nums.size()-1; i++) if(nums[i]<nums[i+1]) return false;
        }

    	return true;
    }
};

int main(){
	vector<int> nums = {1,4,3};
	Solution sol;
	cout << sol.isMonotonic(nums);
	return 0;
}