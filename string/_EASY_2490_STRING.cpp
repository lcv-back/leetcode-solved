#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
    	int n = sentence.size();
        // check special case: first character on first word is different with last character on last word 
        if(sentence[0] != sentence[n-1]) return false;

        for(int i=0; i<n; i++){
        	// process if character is another string difference last string
        	if(sentence[i+1] == ' '){
        		if(sentence[i] != sentence[i+2]) return false;
        	}
        }

        return true;
    }
};

int main(){
	Solution sol;
	string sentence1 = "leetcode exercises sound delightful";
	string sentence2 = "eetcode";
	string sentence3 = "Leetcode is cool";

	cout << sol.isCircularSentence(sentence1) << endl; //true
	cout << sol.isCircularSentence(sentence2) << endl; //true
	cout << sol.isCircularSentence(sentence3) << endl; //false
	return 0;
}