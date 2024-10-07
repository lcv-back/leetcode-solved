#include <string>
#include <iostream>

using namespace std;

/*
	analysis requirements:	
	- input: string s
	- processing: 
		- use sliding window
		- 
	- output: the minimum length string operations after removed
*/

class Solution {
public:
    int minLength(string s) {
    	int foundPair = 1;
    	while(foundPair==1){
    		foundPair=0;
    		if(s.length()<2)break;
    		for(int i=0;i<s.length()-1;i++){
    			string window = s.substr(i,2);
    			if(window == "AB" || window == "CD"){
    				s = s.substr(0,i) + s.substr(i+2);
    				foundPair=1;
    				break;
    			}
    		}
    	}
    	return s.length();
    }

    /*
		Time complexity: O(n^2)
		Space complexity: O(n)
    */
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