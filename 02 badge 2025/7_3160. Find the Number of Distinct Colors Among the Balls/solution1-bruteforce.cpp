#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    	unordered_map<int, int> ballColor; // Map ball label to color
    	unordered_set<int> distinctColors; // Store distinct colors
    	vector<int> colors;

    	for(const auto& q : queries){
    		int ballLabel = q[0];
    		int newColor = q[1];

    		// Check if the ball had a previour color
    		if(ballColor.count(ballLabel)){
    			int oddColor = ballColor[ballLabel];

    			// Remove the old color from the distinctColors set if it's no longer associated with any ball
    			bool colorStillUsed = false;
    			for(auto& pair : ballColor){
    				if(pair.first != ballLabel && pair.second == oddColor){
    					colorStillUsed = true;
    					break;
    				}
    			}

    			if(!colorStillUsed){
    				distinctColors.erase(oddColor);
    			}

    		}

    		// Update the ball's color
    		ballColor[ballLabel] = newColor;
    		distinctColors.insert(newColor);

    		colors.push_back(distinctColors.size());
    	}
    	

		return colors;
    }
};

int main(){
	Solution sol;
	int limit = 4;
	vector<vector<int>> queries = {{1,4}, {2,5}, {1,3}, {3,4}};
	vector<int> res = sol.queryResults(limit, queries);
	for(int i : res) cout << i << " ";
	cout << endl;
	return 0;
}