#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        unordered_set<char> letters;
        for(char c : s) letters.insert(c);

        for(char letter : letters){
        	int i = -1;
        	int j = 0;

        	for(int k=0; k < n; k++){
        		if(s[k] == letter){
        			if(i == -1){
        				i = k;
        			}
        			j = k;
        		}
        	}

        	unordered_set<char> between;
        	for(int k=i+1; k<j; k++){
        		between.insert(s[k]);
        	}

        	ans += between.size();
        }

        return ans;
    }
};



int main(){
	Solution sol;
	string s = "aabca";
	string s1 = "bbcbaba";
	cout << sol.countPalindromicSubsequence(s1);
	return 0;
}