#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
    	stack<char> st;
    	for(char ch : s){
    		if(isdigit(ch)){
    			if(!st.empty()){
    				st.pop();
    			}
    		} else {
    			st.push(ch);
    		}
    	}

    	string res = "";
    	while(!st.empty()){
    		res = st.top() + res;
    		st.pop();
    	}

    	return res;
    }
};

int main(){
	Solution sol;
	string s = "ab45";
	cout << sol.clearDigits(s);
	return 0;
}