#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	1942. The number of the smallest unoccupied chair
	- input: array 0-indexed 2 dimensional times, integer targetFriend
	- processing: 
		1. Extract the arrival time of the target friend
		2. Sort the times array based on arrival times
		3. Initialize a vector to keep track of chair occupancy times
		4. Iterate through the sorted times:
			- Find the smallest unoccupied chair (chair with occupancy time <= current arrival time)
			- Update the chair's occupancy time with the current leaving time
			- If the current friend is the target friend, return the chair number
	- output: the smallest chair number that the target friend will sit on
	- Time complexity: O(n^2) where n is the number of friends
	- Space complexity: O(n) for the chair occupancy vector

*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> targetTime = times[targetFriend];
        sort(times.begin(), times.end());

        int n = times.size();
        vector<int> chairTime(n);

        for (auto time : times) {
            for (int i = 0; i < n; i++) {
                if (chairTime[i] <= time[0]) {
                    chairTime[i] = time[1];
                    if (time == targetTime) return i;
                    break;
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> times1 = {{1,4}, {2,3}, {4,6}};
    int targetFriend1 = 1;
    cout << "Test case 1 result: " << sol.smallestChair(times1, targetFriend1) << endl;

    vector<vector<int>> times2 = {{3,10}, {1,5}, {2,6}};
    int targetFriend2 = 0;
    cout << "Test case 2 result: " << sol.smallestChair(times2, targetFriend2) << endl;

    cout << "Program completed successfully." << endl;
    cout.flush(); // Ensure all output is flushed
    return 0;
}