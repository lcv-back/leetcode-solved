#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        
        for (int i = 1; i < arrays.size(); i++) {
            result = max(result, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i][0])));
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return result;
    }
};
int main() {
    Solution s;
    vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout << s.maxDistance(arrays) << endl;  // Output: 4
    return 0;
}