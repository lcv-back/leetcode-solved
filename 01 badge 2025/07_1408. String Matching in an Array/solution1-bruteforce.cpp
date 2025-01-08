#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        unordered_set<int> mp;
        for(int i=0; i<words.size(); i++){
        	string curString = words[i];
        	for(int j=0; j<words.size(); j++){
        		if(j != i && curString.find(words[j]) != string::npos && mp.find(j) == mp.end()){
        			mp.insert(j);
        			ans.push_back(words[j]);
        		}
        	}
        }
        return ans;
    }
};

int main(){
	Solution sol;
	vector<string> words = {"mass", "as", "hero", "superhero"};
	vector<string> res = sol.stringMatching(words);
	for(string s: res) cout << s << " ";
	return 0;
}