#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int x = 0, i = grid[0].size()-1;
        int total = 0;
        while(i >= 0 && x < n) {
            if(grid[x][i] < 0) {
                total += n - x;
                i--;
            } else {
                x++;
            }
        }
        return total;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << s.countNegatives(grid) << endl;
    return 0;
}