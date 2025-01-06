#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
    	for(auto shift : shifts){
    		int start = shift[0];
    		int end = shift[1];
    		int dic = shift[2];

    		for(int i=start; i<=end; i++){
    			if(dic == 1){
	    			s[i] = (char) (((int)s[i] - (int)'a' + 1) % 26 + (int)'a');
	    		} else {
	    			s[i] = (char) (((int)s[i] - (int)'a' - 1) % 26 + (int)'a');
	    		}
    		}
    	}
    	return s;
    }
};

int main(){
	Solution sol;
	string s = "abc";
	vector<vector<int>> shifts = {{0,1,0}, {1,2,1}, {0,2,1}};

	string s1 = "dztz";
	vector<vector<int>> shifts1 = {{0,0,0}, {1,1,1}};
	cout << sol.shiftingLetters(s1, shifts1) << endl;
	return 0;
}