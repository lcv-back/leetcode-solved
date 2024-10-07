#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
        	char currentChar = s[i];
        	if(st.empty()){
        		st.push(currentChar);
        	} else {
        		if(currentChar == 'B' && st.top() == 'A'){
        			st.pop();
        		} else if(currentChar == 'D' && st.top() == 'C'){
        			st.pop();
        		} else {
        			st.push(currentChar);
        		}
        	}
        }
        return st.size();
    }
};

auto init = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
};

int main(){
	string s = "ABFCACDB";
	Solution sol;
	cout << sol.minLength(s) << endl;
	return 0;
}