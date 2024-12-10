#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
    	int n = s.size();
        unordered_map<string, int> subStrCount;

        for(int i=0; i<n; i++){
        	string curSubStr = "";
        	for(int j=i; j<n; j++){
        		if(s[j] == s[i]){
        			curSubStr += s[j];
        			subStrCount[curSubStr]++;
        		} else {
        			break;
        		}
        	}
        }

        int maxLen = -1;
        for(const auto& it : subStrCount){
        	if(it.second >= 3){
        		maxLen = max(maxLen, (int)it.first.length());
        	}
        }

        return maxLen;
    }
};

int main(){
	string s = "aaaa";
	Solution sol;
	cout << sol.maximumLength(s) << endl;
	return 0;
}