#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
	Solution() {
		vowels = {'a', 'e', 'u', 'i', 'o'};
	}

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (isVowel(words[i]) ? 1 : 0);
        }
        
        vector<int> res;
        for (auto& q : queries) {
            int cnt = prefix[q[1] + 1] - prefix[q[0]];
            res.push_back(cnt);
        }

        return res;
    }
private:
	set<char> vowels;

	bool isVowel(string& s){
		return (vowels.find(s[0]) != vowels.end()) && (vowels.find(s[s.size()-1]) != vowels.end());
	}
};

int main(){
	Solution sol;
	vector<string> words = {"aba","bcb","ece","aa","e"};
	vector<vector<int>> queries = {{0,2}, {1,4}, {1,1}};
	vector<int> vowelstrings = sol.vowelStrings(words, queries);
	for(int i : vowelstrings) cout << i << ' ';
	cout << endl;
	return 0;
}