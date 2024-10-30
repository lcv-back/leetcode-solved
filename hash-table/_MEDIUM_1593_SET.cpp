#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backstract(0, s, seen);
    }
private:
    int backstract(int start, const string& s, unordered_set<string> seen){
        if(start == s.size()) return 0;
        int maxSplits = 0;
        for(int end = start+1; end <= s.size(); end++){
            string subStr = s.substr(start, end-start);
            if(seen.find(subStr) == seen.end()){
                seen.insert(subStr);
                maxSplits = max(maxSplits, 1 + backstract(end, s, seen));
                seen.erase(subStr);
            }
        }
        return maxSplits;
    }

};

int main() {
    Solution sol;
    cout << sol.maxUniqueSplit("ababcc") << endl; // Output: 5
    cout << sol.maxUniqueSplit("aba") << endl; // Output: 2
    cout << sol.maxUniqueSplit("wwwzfvedwfvhsww") << endl; // Output: 11
    return 0;
}