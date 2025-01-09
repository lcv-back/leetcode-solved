#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
    	int cnt = 0;
        for(int i=0; i<words.size(); i++){
        	if(words[i].find(pref) == 0) cnt++;
        }

    	return cnt;
    }
};

int main(){
	Solution sol;
	vector<string> words = {"pay","attention","practice","attend"};
	string pref = "at";
	cout << sol.prefixCount(words, pref);
	return 0;
}