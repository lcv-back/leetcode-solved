#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> unit;

        for(int n : nums){
            if(seen.find(n) == seen.end()){
                unit.push_back(n);
                seen.insert(n);
            }
        }

        int l=0, r=unit.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(unit[mid] > unit[r]) l=mid+1;
            else if(unit[mid] < unit[r]) r=mid;
            else r--;
        }

        return unit[l];
    }
};

int main(){
	Solution sol;
	vector<int> nums = {2,2,2,0,1};
	cout << sol.findMin(nums) << endl;
	return 0;
}