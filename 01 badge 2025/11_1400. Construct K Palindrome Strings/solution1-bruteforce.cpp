#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        if(s.size() == k) return true;
        vector<int> freq(26);

        // counting frequencies of character
        for(char c : s) freq[c - 'a']++;

        // if in map has many characters have the frequency is odd => return false 
        int oddFrequency = 0;
        for(int i=0; i<26; i++){
        	if(freq[i] % 2 == 1) oddFrequency++;
        }

        return oddFrequency <= k;
    }
};

int main(){
	Solution sol;
	string s = "annabelle";
	string s1 = "true";
	string s2 = "messi";

	int k = 2;
	int k1 = 4;
	int k2 = 3;
	cout << "Testcase 1: " << sol.canConstruct(s, k) << " " << endl;
	cout << "Testcase 2: " << sol.canConstruct(s1, k1) << " " << endl;
	cout << "Testcase 3: " << sol.canConstruct(s2, k2) << " " << endl;
	return 0;
}