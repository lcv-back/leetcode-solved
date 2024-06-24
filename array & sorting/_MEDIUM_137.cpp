#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto x: nums){
            m[x]++;
        }

        for(auto x: m){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,2,3,2};
    cout << s.singleNumber(nums) << endl;
    return 0;
}