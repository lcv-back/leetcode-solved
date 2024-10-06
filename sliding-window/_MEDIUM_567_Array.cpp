#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if (m > n) return false;

        int s1arr[26] = {0}; 
        int s2arr[26] = {0}; 

        for (auto c : s1) s1arr[c - 'a']++;

        for (int i = 0; i < m; i++) {
            s2arr[s2[i] - 'a']++;
        }

        if (compareArray(s1arr, s2arr)) return true;

        for (int i = m; i < n; i++) {
            s2arr[s2[i] - 'a']++;              
            s2arr[s2[i - m] - 'a']--;          

            if (compareArray(s1arr, s2arr)) return true;
        }

        return false;
    }

private:
    bool compareArray(int s1arr[], int s2arr[]) {
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] != s2arr[i]) return false;
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution sol;
    cout << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl;
    return 0;
}
