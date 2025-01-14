#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    	unordered_set<int> seen;
    	int n = A.size();
    	vector<int> res(n);

    	int cnt = 0;

		// processing
    	for(int i=0; i<n; i++){
    		if(seen.count(A[i])) cnt++;
    		else seen.insert(A[i]);

    		if(seen.count(B[i])) cnt++;
    		else seen.insert(B[i]);

    		res[i] = cnt;
    	}
    	return res;
    }
};

int main(){
	Solution sol;
	// Testcase 1
	vector<int> A = {1,3,2,4};
	vector<int> B = {3,1,2,4};

	// Testcase 2
	vector<int> C = {2,3,1};
	vector<int> D = {3,1,2};

	vector<int> res = sol.findThePrefixCommonArray(C, D);
	for(int x : res) cout << x << " ";
	return 0;
}