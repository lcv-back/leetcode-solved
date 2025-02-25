#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v1(n+1,0);
        vector<int> v2(n+1,0);

        for(auto& v : trust){
        	v1[v[0]]++;
        	v2[v[1]]++;
        }

        for(int i=1; i <= n; i++){
        	if(v1[i]==0 && v2[i]==n-1) return i;
        }

        return -1;
    }
};

int main(){
	Solution sol;
	int n = 3;
	vector<vector<int>> trust = {{1,2},{2,3}};
	cout << sol.findJudge(n, trust);
	return 0;
}