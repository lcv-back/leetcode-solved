#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        DPSolver;
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1]* nums[nums.size()-2]) - (nums[0]*nums[1]); 
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,6,2,7,4};
    cout << s.maxProductDifference(nums) << endl;
    return 0;
}