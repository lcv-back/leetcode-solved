#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) {
                rem += k;
            }
            freq[rem]++;
        }
        
        if (freq[0] % 2 != 0) {
            return false;
        }
        
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k = 5;
    cout << s.canArrange(arr, k) << endl; // Output: true
    return 0;
}