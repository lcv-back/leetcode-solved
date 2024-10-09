#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int min=0;
        stack<char> st;

        for(int i=0; i<s.length(); i++) {
            char curChar = s[i];
            if(st.empty()) st.push(curChar);
            else {
                if(st.top() == '(' && curChar == ')') st.pop();
                else st.push(curChar);
            }
        }

        return st.size();
    }
};

/*
    Time complexity: O(n)
    Space complexity: O(n)
    n is the length of the input string s
*/

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main() {
    Solution sol;
    string s1 = "()))";
    cout << sol.minAddToMakeValid(s1) << endl;

    string s2 = "(((";
    cout << sol.minAddToMakeValid(s2) << endl;
    return 0;
}