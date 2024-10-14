#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end()); // first i will sort by start time = interval[0]

    	vector<vector<int>> merged; // store result
    	vector<int> prev = intervals[0]; // point to previous interval

    	for(int i=1; i < intervals.size(); i++){ // minus 0 because will compare start time at i and end time at i-1, 0 at here
    		vector<int> interval = intervals[i];
    		if(interval[0] <= prev[1]){ // if start time at i less than or equal with end time at i-1 => can reduce interval
    			prev[1] = max(prev[1], interval[1]); // why find max? because if less than case occur => interval at i is a child of interval at i-1
    		} else {
    			merged.push_back(prev); // save
    			prev = interval; // next interval need to process
    		}
    	}

    	merged.push_back(prev); // push last element
    	return merged;
    }
};

// time: O(n)
// space: O(n) 

int main(){
	vector<vector<int>> interval = {
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18},
	};
	Solution sol;
	vector<vector<int>> result = sol.merge(interval);
	for(int i=0; i < result.size(); i++){
		for(int j=0; j < result[0].size(); j++){
			cout << result[i][j] << " ";
		}
		
	}

	return 0;
}
