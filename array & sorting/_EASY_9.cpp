#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from right to left to add one
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // Early return if no carry
            } else {
                digits[i] = 0; // Set current digit to 0 and carry 1
            }
        }

        // If we're here, it means all digits were 9
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};

int main(){
    Solution s;
    vector<int> digits = {1,2,3};
    vector<int> result = s.plusOne(digits);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}