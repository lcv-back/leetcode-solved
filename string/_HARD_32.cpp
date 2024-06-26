#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.size() == 0) {
                    st.push(i);
                } else {
                    len = max(len, i - st.top());
                }
            }
        }
        return len;
    }
};

int main(){
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
    return 0;
}