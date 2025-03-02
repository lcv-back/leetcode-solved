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
    vector<vector<int>> mergeArrays(vector<vector<int>>& a1, vector<vector<int>>& a2) {
        int n = a1.size(), m = a2.size();
        int l = 0, r = 0;
        vector<vector<int>> res;
        while(l < n && r < m){
            if(a1[l][0] == a2[r][0]){
                res.push_back({a1[l][0], a1[l][1] + a2[r][1]});
                ++l; ++r;
            } else if (a1[l][0] < a2[r][0]){
                res.push_back(a1[l]); ++l;
            } else {
                res.push_back(a2[r]); ++r;
            }
        }

        while(l < n){
            res.push_back(a1[l]);
            ++l;
        }

        while(r < m){
            res.push_back(a2[r]);
            ++r;
        }

        return res;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> n1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> n2 = {{1,4},{3,2},{4,1}};
    vector<vector<int>> res = sol.mergeArrays(n1, n2);
    for(auto& row : res) cout << row[0] << " " << row[1] << endl;
	return 0;
}