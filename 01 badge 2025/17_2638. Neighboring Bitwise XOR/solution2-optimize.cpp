#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n);

        for(int i=0; i<n-1; i++) original[i+1] = original[i] ^ derived[i];

        if(original[n-1] ^ original[0] != derived[n-1]) return false;
    	return true;
    }
};

int main(){
	Solution sol;
	vector<int> derived = {1,0};

	cout << "Result:: " << sol.doesValidArrayExist(derived) << " ";
	return 0;
}