#include <iostream>
#include <stack>
using namespace std;

/*
	analysis requirements
	- input: string s
	- processing: 
		- use stack
		- initialization stack store character 
		- if stack is empty, push character to stack
		- if stack dont empty, current character is 'B' and stack's top is 'A' remove stack's top
		- if stack dont empty, current character is 'D' and stack's top is 'C' remove stack's top
		- the stack's size is the minimum length of string
	- output: the minimum length string operations after removed
*/

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