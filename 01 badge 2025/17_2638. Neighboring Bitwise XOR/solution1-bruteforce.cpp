#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n==0) return false;
        if(n==1) return derived[0] == 0;
        vector<int> res(n);

        for(int i=0; i<n; i++){
        	if(i == n-1){
        		res[i] = derived[0] ^ derived[n-1];
        	} else {
        		res[i] = derived[i] ^ derived[i+1];
        	}
        }

        int cntZeros = 0, cntOnes = 0;
        for(int i=0; i<n; i++){
        	if(res[i]==0) cntZeros++;
        	else cntOnes++;
        }

       	if(n==2){
       		if(derived[0] == derived[1]) return true;
       		return false;
       	}

        return (cntZeros + cntOnes) == n;
    }
};

int main(){
	Solution sol;
	vector<int> derived = {1,0};

	cout << "Result:: " << sol.doesValidArrayExist(derived) << " ";
	return 0;
}