#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0) return 0.0;
        double minAverage = 51.0;

        // find the smallest element and the biggest element
        sort(nums.begin(), nums.end());
        int left = 0, right = n-1;

        for(int i=0; i < n/2; i++){
            double avg = (nums[left] + nums[right]) / 2.0;

            left++; right--;

            // calculate the minimum 
            minAverage = min(minAverage, avg);
        }

        
        return minAverage;       
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 10, 3, 7, 5, 9, 4, 6, 8, 2};
    cout << s.minimumAverage(nums) << endl;
    return 0;
}

