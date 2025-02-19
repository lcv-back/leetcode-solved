#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void backtrack(int start, string tiles, string cur_substring, unordered_set<string>& uniques_substrings){
    	if (!cur_substring.empty()) {
	        uniques_substrings.insert(cur_substring);
	    }

	    for (int i = start; i < tiles.length(); i++) {
	        backtrack(i + 1, tiles, cur_substring + tiles[i], uniques_substrings);
	    }
    }

    int numTilePossibilities(string tiles) {
    	unordered_set<string> uniques_substrings;
    	backtrack(0, tiles, "", uniques_substrings);
		return uniques_substrings.size();
    }
};

int main(){
	Solution sol;
	string tiles = "AAB";
	cout << sol.numTilePossibilities(tiles);
	return 0;
}