#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> uniqueSet(nums.begin(), nums.end());
        nums.assign(uniqueSet.begin(), uniqueSet.end());

        int l=0, r=nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};

int main(){
	Solution sol;
	vector<int> nums = {2,2,2,0,1};
	cout << sol.findMin(nums) << endl;
	return 0;
}