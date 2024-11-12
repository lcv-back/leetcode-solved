#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int binary_search(vector<vector<int>>& a, int target){
		int l = 0;
		int r = a.size() - 1;
		int maximum = 0;
		while(l <= r){
			int m = (l + r) / 2;
			if(target >= a[m][0]) {
				maximum = max(maximum, a[m][1]);
				l = m+1;
			} else {
				r = m-1;
			}
		}
		return maximum;
	}

	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries){
		// brute force
		vector<int> ans(queries.size());

		// sort the items by price increasing order
		sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0];
		});
		// store max beauti from start to current i
		for(int i=1; i<items.size(); i++){
			items[i][1] = max(items[i][1], items[i-1][1]);
		}

		for(int i=0; i<queries.size(); i++){
			ans[i] = binary_search(items, queries[i]);
		}

		return ans;
	}
};



int main(){
	Solution sol;
	vector<vector<int>> items = {{1,2}, {3,2}, {2,4}, {5,6}, {3,5}};
	vector<int> queries = {1,2,3,4,5,6};
	vector<int> ans = sol.maximumBeauty(items, queries);
	for(int i : ans) cout << i << ' '; // output: 2,4,5,5,6,6
	return 0;
}