#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n=3;
        vector<int> rows(n);
        vector<int> cols(n);
        int diag1 = 0;
        int diag2 = 0;
        int currPlayer = 1;

        for(vector<int> currMove : moves){
        	rows[currMove[0]] += currPlayer;
        	cols[currMove[1]] += currPlayer;
        	diag1 = currMove[0] == currMove[1] ? diag1 + currPlayer : diag1;
        	diag2 = currMove[0] + currMove[1] == n-1 ? diag2 + currPlayer : diag2;

        	if(abs(rows[currMove[0]]) == n || abs(cols[currMove[1]]) == n || abs(diag1) == n || abs(diag2) == n){
        		return currPlayer == 1 ? "A" : "B";
        	}

        	currPlayer *= -1;
        }

        return moves.size() < 9 ? "Pending" : "Draw";
    }
};

int main(){
	Solution sol;
	vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
	cout << sol.tictactoe(moves);
	return 0;
}