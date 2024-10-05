#include <iostream>
#include <algorithm>

using namespace std;

/*
    Sliding window
    - Sort the short string
    - Use sliding window for the length of the short string
    - Sort the sliding window
    - Compare the sorted short string with the sorted window in s2
    - Return
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int m = s1.length();
        int n = s2.length();

        if(m > n) return false;

        for(int i=0; i<n; i++){
            string window = s2.substr(i, m);
            sort(window.begin(), window.end());
            if(window == s1) return true;
        }

        return false;
    }

};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};



int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    Solution sol;
    bool res = sol.checkInclusion(s1, s2);
    cout << res << endl;
    return 0;
}