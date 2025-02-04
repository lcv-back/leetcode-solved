#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int tempSum = nums[0];
        int sum = nums[0];

        for(int i=1; i<n; i++){
        	if(nums[i] > nums[i-1]){
				tempSum += nums[i];
        	}
        	else {
        		tempSum = nums[i];        	
        	}
        	sum = max(sum, tempSum);
        }

        return sum;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {100,10,1};
	cout << "result:: " << sol.maxAscendingSum(nums) << endl;
	return 0; 
}