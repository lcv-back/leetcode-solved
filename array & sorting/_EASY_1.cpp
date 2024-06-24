#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.count(target-nums[i]))
                return {map[target-nums[i]], i};
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}