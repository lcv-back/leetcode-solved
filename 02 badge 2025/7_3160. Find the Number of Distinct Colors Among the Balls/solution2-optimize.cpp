#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColors;
        unordered_map<int, int> colorCounts; // Track count of each color
        unordered_set<int> distinctColors;
        vector<int> result;

        for (const auto& q : queries) {
            int ballLabel = q[0];
            int newColor = q[1];

            // Check if the ball had a previous color
            if (ballColors.count(ballLabel)) {
                int oldColor = ballColors[ballLabel];
                colorCounts[oldColor]--; // Decrement count of the old color
                if (colorCounts[oldColor] == 0) {
                    distinctColors.erase(oldColor);
                }
            }

            // Update the ball's color
            ballColors[ballLabel] = newColor;

            // Increment count of the new color
            colorCounts[newColor]++;
            distinctColors.insert(newColor);

            result.push_back(distinctColors.size());
        }

        return result;
    }
};

int main() {
    Solution sol;
    int limit = 4;
    vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    vector<int> res = sol.queryResults(limit, queries);
    for (int i : res) cout << i << " ";
    cout << endl; // Output: 1 2 2 2
    return 0;
}