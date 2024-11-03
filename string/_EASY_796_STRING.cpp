#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }
};

int main(){
	Solution sol;
	string s = "abcde";
	string goal = "cdeab";
	cout << sol.rotateString(s, goal) << endl;
	return 0;
}