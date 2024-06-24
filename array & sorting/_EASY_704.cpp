#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            int number=nums[mid];
            if(number==target){
                return mid;
            }
            if(number<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums={-1,0,3,5,9,12};
    int target=9;
    cout<<s.search(nums,target)<<endl;
    return 0;
}