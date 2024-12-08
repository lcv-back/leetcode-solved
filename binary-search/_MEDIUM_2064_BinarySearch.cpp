#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDistribute(int x, vector<int>& quantities, int n) {
        int j = 0; // the pointer have the purpose is point to current any stores
        int remaining = quantities[j]; // init

        for(int i=0; i<n; i++){
        	if(remaining <= x){ // needed condition => mandatory condition
        		j++; // point to the next store
        		if(j == quantities.size()){ // roll to destination is array size
        			return true;
        		} else {
        			remaining = quantities[j]; // not destination
        		}
        	} else {
        		remaining -= x; // distributed perform
        	}
        }

        return false;
    }

    int minimizedMaximum(int n, vector<int> quantities){
    	int left = 0;
    	int right = *max_element(quantities.begin(), quantities.end());

    	while(left < right){
    		int middle = left + ((right-left) / 2);
    		if(canDistribute(middle, quantities, n)){ // if true but needed to find the the minimum of x
    			// try with smarter value
    			right = middle;
    		} else {
    			// transform scope
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