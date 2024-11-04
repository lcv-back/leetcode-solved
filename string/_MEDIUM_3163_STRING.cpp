#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        if(word.size() == 0) return comp;
        word += " ";
        int mp[27] = {0};
        char prev = word[0];
        mp[prev-'a']++;

        for(int i=1; i < word.size(); i++){
        	if(word[i] == prev){
        		mp[prev-'a']++;
        	} else {
        		if(mp[prev-'a'] == 0) continue;
        		while(mp[prev-'a'] > 9){
        			comp += '9';
        			comp += prev;
        			mp[prev-'a'] -= 9;
        		}
        		if(mp[prev-'a'] != 0){
        			comp += to_string(mp[prev-'a']);
        			comp += prev;
        			mp[prev-'a'] = 0;
        		}
        		prev = word[i];
        		mp[(word[i]-'a') >= 0 ? word[i]-'a' : 26]++;
        	}
        }

        // special case: string only one character
        for(auto i : mp){
        	if((i >= 0 ? i : 26) != 0){
        		while(mp[i]>9){
        			comp += '9';
        			comp += char(i+'a');
        			mp[i] -= 9; 
        		}
        	}
        }

        return comp;
    }
};

auto init = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
};

int main() {
	Solution sol;
	string word = "abcde";
	cout << sol.compressedString(word) << endl; // output: 1a1b1c1d1e

	string word1 = "mrm";
	cout << sol.compressedString(word1) << endl; // output: 1m1r1m
	return 0;
}