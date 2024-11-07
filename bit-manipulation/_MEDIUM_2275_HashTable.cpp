#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCount(24,0);
        for(int i=0; i<bitCount.size(); i++){
        	for(auto num : candidates){
        		if((num & (1 << i)) != 0) bitCount[i]++;
        	}
        }
        return *max_element(bitCount.begin(), bitCount.end());
    }
};

/*
    Time: O(n) and Space: O(1)
*/

int main(){
	Solution sol;
	vector<int> candidates = {16,17,71,62,12,24,14};
	cout << sol.largestCombination(candidates) << endl;
	return 0;
}