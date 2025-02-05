#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
    	if(s1 == s2) return true;
    	int cnt = 0;
    	vector<int> diff;
    	
    	for(int i=0; i<s1.size(); i++) 
    		if(s1[i] != s2[i]){
    			diff.push_back(i);
    			cnt++;
    		}
    	if(cnt > 2) return false;

    	// what else equal 2
    	if(diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]) return true;

    	return false;
    }
};

int main(){
	Solution sol;
	string s1 = "bank";
	string s2 = "kanb";
	cout << sol.areAlmostEqual(s1, s2);
	cout << endl;

	s1 = "abcd";
	s2 = "dcba";
	cout << sol.areAlmostEqual(s1, s2);
	cout << endl;

	s1 = "qgqeg";
	s2 = "gqgeq";
	cout << sol.areAlmostEqual(s1, s2);
	cout << endl;
	return 0;
}