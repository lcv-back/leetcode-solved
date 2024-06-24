#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findpermutation(vector<int>& nums, vector<vector<int>>&ans, vector<int>&ds,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                findpermutation(nums,ans,ds,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;

        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }

        findpermutation(nums,ans,ds,freq);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums={1,2,3};
    vector<vector<int>>ans=s.permute(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}