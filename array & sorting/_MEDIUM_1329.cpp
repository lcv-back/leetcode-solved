#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diag(m + n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diag[i - j + m].push_back(mat[i][j]);
            }
        }
        for (auto& d : diag) {
            sort(d.rbegin(), d.rend());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = diag[i - j + m].back();
                diag[i - j + m].pop_back();
            }
        }
        return mat;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    s.diagonalSort(mat);
    return 0;
}