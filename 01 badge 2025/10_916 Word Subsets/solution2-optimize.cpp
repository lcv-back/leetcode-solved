#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        int maxCharFreq[26] = {0};
        int tempCharFreq[26];
        
        for (const auto& word : requiredWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }
        
        vector<string> universalWords;
        
        for (const auto& word : mainWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (maxCharFreq[i] > tempCharFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        
        return universalWords;
    }
};

int main(){
	Solution sol;
	vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
	vector<string> words2 = {"e","o"};
	vector<string> ans = sol.wordSubsets(words1, words2);
	cout << "Testcase 1: Processing ->>>>>" << " ";
	for(string x:ans) cout << x << " ";
	cout << endl;

	vector<string> words3 = {"amazon","apple","facebook","google","leetcode"};
	vector<string> words4 = {"l","e"};
	vector<string> ans1 = sol.wordSubsets(words3, words4);
	cout << "Testcase 2: Processing ->>>>>" << " ";
	for(string x:ans1) cout << x << " ";
	cout << endl;
	return 0;
}