#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int indexInSortedList = 0;

        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string &currentString,
                              int &indexInSortedList, string &result) {
        if (currentString.size() == n) {
            indexInSortedList++;  // Increment the count of generated strings

            // If this is the k-th string, store it in the result
            if (indexInSortedList == k) result = currentString;
            return;
        }

        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            currentString += currentChar;

            generateHappyStrings(n, k, currentString, indexInSortedList,
                                 result);

            if (result != "") return;

            // Backtrack by removing the last character
            currentString.pop_back();
        }
    }
};

int main(){
	Solution sol;
	int n = 1;
	int k = 3;

	string res = sol.getHappyString(n, k);
	cout << res;
	return 0;
}