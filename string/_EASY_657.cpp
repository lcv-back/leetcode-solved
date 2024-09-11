#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
    	// special cases
        if(moves.size() % 2 == 1) return false;
        if(moves.size() == 0) return true;

        vector<int> freq(4);

        fill(freq.begin(), freq.end(), 0);

        for(auto c : moves){
        	if(c == 'R') freq[0] += -1;
        	else if(c == 'L') freq[1] += 1;
        	else if(c == 'U') freq[2] += 1;
        	else if(c == 'D') freq[3] += -1;
        	else return false; // different character R, L, U, D
        }

        if(freq[0]+freq[1]==0 && freq[2]+freq[3]==0) return true;
        return false;
    }
};

int main(){
	string moves = "UD";
	Solution sol;
	cout << sol.judgeCircle(moves);
	return 0;
}