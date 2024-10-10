#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0, close_needed = 0;
        for(char c : s) {
            if(c == '(')
                open_needed++;
            else 
                open_needed > 0 ? open_needed-- : close_needed++;
        }
        return open_needed + close_needed;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main(){
    Solution sol;
    string s1 = "())";
    cout << sol.minAddToMakeValid(s1) << endl; // Output: 2

    string s2 = "(((";
    cout << sol.minAddToMakeValid(s2) << endl; // Output: 3
    return 0;
}