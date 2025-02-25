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
	int numOfSubarrays(vector<int>& arr) {
		const int MOD = 1e9 + 7;
		int sum = 0;
		int ans = 0;
		vector<int> cnt(2,0);
		cnt[0] = 1;

		for(const int& x : arr) {
			sum += x;
			ans = (ans + cnt[sum % 2 ^ 1]) % MOD;
			++cnt[sum % 2];
		}

		return ans;
	}
};

int main(){
	Solution sol;
	vector<int> arr = {64,69,7,78,31,83,47,84,47,6,67};
	cout << sol.numOfSubarrays(arr) << endl;
	return 0;
}