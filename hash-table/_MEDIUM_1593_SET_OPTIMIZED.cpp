#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        int maxSplits = 0;
        unordered_set<string> seen;
        backstract(0, s, seen, 0, maxSplits);
        return maxSplits;
    }
private:
	void backstract(int start, const string& s, unordered_set<string>& seen, int count, int& maxSplits) {
		// use pruning technique to reduce branchs
		if(count + (s.size() - start) <= maxSplits) return;
		if(start == s.size()){
			maxSplits = max(maxSplits, count);
			return;
		}
		for(int end = start + 1; end <= s.size(); end++){
			string subString = s.substr(start, end-start);
			if(seen.find(subString) == seen.end()){
				seen.insert(subString);
				backstract(end, s, seen, count+1, maxSplits);
				seen.erase(subString);
			}
		}
	}
};

int main(){
	Solution sol;
	cout << sol.maxUniqueSplit("ababccc") << endl;
	cout << sol.maxUniqueSplit("abc") << endl;
	cout << sol.maxUniqueSplit("aa") << endl;
	return 0;
}