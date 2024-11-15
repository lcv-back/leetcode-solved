#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDistribute(int x, vector<int>& quantities, int n) {
        int j = 0;
        int remaining = quantities[j];

        for(int i=0; i<n; i++){
        	if(remaining <= x){
        		j++;
        		if(j == quantities.size()){
        			return true;
        		} else {
        			remaining = quantities[j];
        		}
        	} else {
        		remaining -= x;
        	}
        }

        return false;
    }

    int minimizedMaximum(int n, vector<int> quantities){
    	int left = 0;
    	int right = *max_element(quantities.begin(), quantities.end());

    	while(left < right){
    		int middle = left + ((right-left) / 2);
    		if(canDistribute(middle, quantities, n)){
    			right = middle;
    		} else {
    			left = middle+1;
    		}
    	}

    	return left;
    }
};

int main(){
	Solution sol;
	int n = 6;
	vector<int> quantities = {11,6};
	cout << sol.minimizedMaximum(n, quantities) << endl;
}