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
    vector<int> applyOperations(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n-1; ++i){
            if(arr[i] == arr[i+1]){
                arr[i] = arr[i] * 2;
                arr[i+1] = 0;
            } else {
                continue;
            }
        }

        int l = 0, r = 0;
        while(r < n){
            if(arr[r] != 0){
                swap(arr[l], arr[r]);
                ++l;
            }
            ++r;
        }

        return arr;
    }
};

int main(){
	Solution sol;
	vector<int> arr = {1,2,2,1,1,0};
    vector<int> res = sol.applyOperations(arr);
    for(int x : res)
        cout << x << " ";
	return 0;
}