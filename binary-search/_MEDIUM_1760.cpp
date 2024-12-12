#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // methodlody: binary search

        int left = 1, right = -1;
        for(int x : nums) right = max(right, x);

        while(left < right){
        	int mid = (left + right) / 2;
        	if(canAchievePenalty(nums, mid, maxOperations)){
        		right = mid;
        	} else {
        		left = mid+1;
        	}
        }
        return left;
    }

    bool canAchievePenalty(vector<int>& nums,int maxPenalty,int maxOperations){
    	int operations = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i] > maxPenalty){
    			operations += (nums[i]-1) / maxPenalty;
    		}

    		if(operations > maxOperations) return false;
    	}
    	return true;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {9};
	int maxOperations = 2;
	cout << sol.minimumSize(nums, maxOperations) << endl;
	return 0;
}