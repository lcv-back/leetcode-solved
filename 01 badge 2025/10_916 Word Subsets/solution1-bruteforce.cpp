#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    	vector<string> ans;
        for(string w1 : words1){
        	bool notSub = false;
        	for(string w2 : words2){
        		if(w1.find(w2) == string::npos){
        			notSub = true;
        		}
        	}

        	if(!notSub) ans.push_back(w1);
        }

        return ans;
    }
};

// Fail on testcase 10

int main(){
	Solution sol;
	vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
	vector<string> words2 = {"e","o"};
	vector<string> ans = sol.wordSubsets(words1, words2);
	cout << "Testcase 1: Processing" << endl;
	for(string x:ans) cout << x << " ";
	cout << endl;

	vector<string> words3 = {"amazon","apple","facebook","google","leetcode"};
	vector<string> words4 = {"l","e"};
	vector<string> ans1 = sol.wordSubsets(words3, words4);
	cout << "Testcase 2: Processing" << endl;
	for(string x:ans1) cout << x << " ";
	cout << endl;
	return 0;
}