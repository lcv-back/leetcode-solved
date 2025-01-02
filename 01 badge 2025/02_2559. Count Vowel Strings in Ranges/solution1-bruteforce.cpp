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
        vector<int> res;
        for(auto& q : queries){
        	int cnt=0;
        	if(q[0] < 0 || q[1] > words.size()-1){
        		res.push_back(0);
        		continue;
        	}
        	for(int i=q[0]; i<=q[1]; i++){
        		if(isVowel(words[i])) ++cnt;
        	}
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