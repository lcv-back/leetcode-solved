#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        partition(nums.begin(),nums.end(),[](int n){return n%2==0;});
            return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,2,4};
    vector<int> res = s.sortArrayByParity(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
