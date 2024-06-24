#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
       //solving this using two pointer approach
       sort(nums.begin(),nums.end());
       int answer=0;
       int start=0;
       int end=nums.size()-1;

       while(start<end)
       {
        if(nums[start]+nums[end]<target)
        {
            answer+=(end-start);
            start++;
            
        }
        else
        {
            end--;
        }
       }
       return answer;
        
    }
};

int main(){
    Solution s;
    vector<int> nums={1,3,2,6,1,2};
    int target=7;
    cout<<s.countPairs(nums,target)<<endl;
    return 0;
}