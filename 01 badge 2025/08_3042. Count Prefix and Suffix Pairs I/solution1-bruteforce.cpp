#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int pairs = 0;
        int n = words.size();

        for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        if (i == j) continue;

		        string& str1 = words[i];
		        string& str2 = words[j];

		        if (str1.size() <= str2.size() && isPrefixAndSuffix(str1, str2)) {
		            pairs++;
		        }
		    }
		}

        return pairs;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int str1Len = str1.size();
        int str2Len = str2.size();

        // Check prefix and suffix conditions
        bool isPrefix = str2.substr(0, str1Len) == str1;
        bool isSuffix = str2.substr(str2Len - str1Len) == str1;

        return isPrefix && isSuffix;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abab","ab"};
    cout << sol.countPrefixSuffixPairs(words) << endl;
    return 0;
}
