#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// using depth first search to mark all the land visited
	void dfs(vector<vector<char>>& grid, int i, int j){
		// check limited range and it is water around land
		if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') 
			return;
		grid[i][j] = '0'; // mark
		dfs(grid, i+1, j); // bottom
		dfs(grid, i-1, j); // top
		dfs(grid, i, j+1); // left
		dfs(grid, i, j-1); // right
	}
	
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i=0; i < grid.size(); i++){
        	for(int j=0; j < grid[0].size(); j++){
        		if(grid[i][j] == '1'){
        			result++;
        			dfs(grid, i, j); // call dfs method to mark all the land around
				}
			}
		}
		return result;
    }
};

// time: O(m*n)
// space: O(min(m*n))

int main(){
	vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    Solution sol;
	int result = sol.numIslands(grid);
    cout << result;
	return 0;
}
