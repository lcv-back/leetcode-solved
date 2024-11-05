#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        for(int i=0; i<s.size(); i += 2) if(s[i] != s[i+1]) cnt++;
        return cnt;
    }
};

int main(){
	Solution sol;
	string s = "1001";
	cout << sol.minChanges(s) << endl; 
	return 0;
}