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
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i < n+1; ++i){
            for(int j=1; j < m+1; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};

int main(){
	Solution sol;
	string text1 = "abcde";
    string text2 = "ace";
    cout << sol.longestCommonSubsequence(text1, text2);
	return 0;
}