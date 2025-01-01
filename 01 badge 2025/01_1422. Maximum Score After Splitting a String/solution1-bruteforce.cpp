#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
    	// brute force
    	int max = -1;
    	int n=s.size();
        for(int i=0; i<s.size()-1;i++){
        	int charZeros = 0;
        	int charOnes = 0;

        	string s1 = s.substr(0, i+1);
        	for(char c : s1) if(c=='0') charZeros++;
        	string s2 = s.substr(i+1, n-i-1);
        	for(char c : s2) if(c=='1') charOnes++;

        	if((charZeros+charOnes) > max) max = charZeros+charOnes;
        }
        return max;
    }
};

int main(){
	Solution sol;
	string s = "011101";
	cout << sol.maxScore(s);
}