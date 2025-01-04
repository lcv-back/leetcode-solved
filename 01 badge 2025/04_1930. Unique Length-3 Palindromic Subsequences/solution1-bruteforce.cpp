#include<iostream>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
    	int n = s.size();
    	set<string> mp;
    	for(int i=0; i<n; i++){
    		for(int j=i+1; j<n; j++){
    			for(int k=j+1; k<n; k++){
    				if(s[i] == s[k]){
    					string tmp = "";
    					tmp = (char)s[i] + (char)s[j] + (char)s[k];
    					mp.insert(tmp);
    				}
    			}
    		}
    	}
    	return mp.size();
    }
};

int main(){
	Solution sol;
	string s = "aabca";
	cout << sol.countPalindromicSubsequence(s);
	return 0;
}