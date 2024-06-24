#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int nc=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                return 0;
            }
            if(nums[i]<0){
                nc++;
            }
        }
        if(nc % 2 == 0){
            return 1;
        }
        else{
            return -1;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums={-3,-2,-1,0,1,2,3};
    cout<<s.arraySign(nums)<<endl;
    return 0;
}