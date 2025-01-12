#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

    	int m = grid.size();
    	int n = grid[0].size();

    	vector<int> ans;
        for(int i=0; i<m; i++){
        	
        }

        return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> grid = {{1,2}, {3,4}};
	vector<int> res = sol.zigzagTraversal(grid);
	for(int x : res) cout << x << " ";
	return 0;
}