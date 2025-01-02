#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
    	int ones = 0, zeros = 0;
        int max=-1;
        for(char c : s) if(c == '1') ones++;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '0') zeros++;
            else ones--;
            if(zeros+ones>max) max=zeros+ones;
        }
        return max;
    }
};

int main(){
	Solution sol;
	string s = "011101";
	cout << sol.maxScore(s);
}