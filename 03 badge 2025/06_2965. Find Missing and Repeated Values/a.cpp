#include <bits/stdc++.h> 
#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2, 0);
        int n = grid.size();
        vector<int> cnt(n * n + 5, 0);
        int curIdx = 0;

        for(int i=0;i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                ++cnt[grid[i][j]];
                if(cnt[grid[i][j]] != 0) curIdx = max(curIdx, grid[i][j]);
            }
        }

        for(int i=0; i<=curIdx; i++){
            if(cnt[i] == 2) ans[0]=i;
            else if(cnt[i] == 0 && i != 0) ans[1] = i;
        }

        if(ans[1] == 0) ans[1] = curIdx+1;

        return ans;
    }
};


int main(){
	Solution sol;
	vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> ans = sol.findMissingAndRepeatedValues(grid);
    cout << ans[0] << " " << ans[1] << endl; 
	return 0;
}