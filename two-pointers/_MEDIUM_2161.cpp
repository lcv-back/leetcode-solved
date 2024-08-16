#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessThanPivot;
        vector<int> greaterThanPivot;
        vector<int> equalThanPivot;

        for(int num : nums) {
            if(num < pivot) lessThanPivot.push_back(num);
            else if(num > pivot) greaterThanPivot.push_back(num);
            else equalThanPivot.push_back(num);
        }

        int ind = 0;
        for(int x : lessThanPivot) nums[ind++] = x;

        for(int x : equalThanPivot) nums[ind++] = x;

        for(int x : greaterThanPivot) nums[ind++] = x;

        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {9,12,5,10,14,3, 10};
    int pivot = 10;

    vector<int> result = s.pivotArray(nums, pivot);
    for(int num : result)
        cout << num << " ";
    cout << endl;

    // what is output on fact?
    // 14 12 10 9 5 3 10


    return 0;
}

