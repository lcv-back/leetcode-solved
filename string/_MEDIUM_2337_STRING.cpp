#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
    	int n = start.size();
    	int cntL1 = 0, cntR1 = 0, cntL2 = 0, cntR2 = 0;
    	for(int i=0; i<n; i++){
    		if(start[i] == 'L') cntL1++;
    		if(start[i] == 'R') cntR1++;
    		if(target[i] == 'L') cntL2++;
    		if(target[i] == 'R') cntR2++;
    	}

    	if(cntL1 != cntL2 || cntR1 != cntR2) return false;

    	int i=0, j=0;
    	while(i < n && j < n){
    		while(i < n && start[i] == '_') i++;
    		while(j < n && target[j] == '_') j++;

    		if(i==n && j==n) break;

    		if(i<n && j<n){
    			if(start[i] != target[j]){ // character dont same
    				return false;
    			}

    			if(start[i] == 'L' && i < j){ // L cannt be moved
    				return false;
    			}

    			if(start[i] == 'R' && i > j){ // R cannt be moved
    				return false;
    			}

    			i++;
    			j++;
    		}
    	}

    	return true;
    }
};

int main() {
	Solution sol;
	string start = "_L__R__R_";
	string target = "L______RR";
	cout << sol.canChange(start, target) << endl;
	return 0;
}