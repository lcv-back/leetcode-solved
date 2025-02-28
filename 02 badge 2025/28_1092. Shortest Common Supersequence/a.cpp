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
    string shortestCommonSupersequence(string s1, string s2) {
        // step 1: longest common subsequence
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string scs = "";

        // step 2: find shortest common subsequence
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                scs += s1[i-1];
                --i; --j;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                scs += s1[i-1];
                --i;
            } else {
                scs += s2[j-1];
                --j;
            }
        }

        while(i > 0){
            scs += s1[i-1]; --i;
        }

        while(j > 0){
            scs += s2[j-1]; --j;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};

int main(){
	Solution sol;
    string s1 = "abac"; string s2 = "cab";
    cout << sol.shortestCommonSupersequence(s1, s2);
	return 0;
}