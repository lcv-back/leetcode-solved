#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;
              // To store both arrival and leave events

        // Populate events with {arrival, friendIndex} and {leave, -friendIndex}
        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], i});   // Friend arrives
            events.push_back({times[i][1], ~i});  // Friend leaves
        }

        sort(events.begin(), events.end());  // Sort events by time

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        // Min-heap for available chairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;
        // Min-heap to track when chairs will be vacated

        for (int i = 0; i < n; i++)
            availableChairs.push(i);  // Initially all chairs are free

        for (auto& event : events) {
            int time = event.first;
            int friendIndex = event.second;

            // Free up chairs when friends leave
            while (!occupiedChairs.empty() &&
                   occupiedChairs.top().first <= time) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (friendIndex >= 0) {  // Friend arrives
                int chair = availableChairs.top();
                availableChairs.pop();
                if (friendIndex == targetFriend) return chair;
                occupiedChairs.push(
                    {times[friendIndex][1],
                     chair});  // Mark when the chair will be vacated
            }
        }

        return -1;  // Should never reach here
    }
};

/*
    Time: O(nlogn), Space: O(n)
*/

int main(){
    Solution sol;
    vector<vector<int>> times1 = {{1,4},{2,3}, {4, 6}};
    int targetFriend1 = 1;
    cout << "Test case 1 result: " << sol.smallestChair(times1, targetFriend1) << endl;

    vector<vector<int>> times2 = {{3,10},{1,5}, {2,6}};
    int targetFriend2 = 0;
    cout << "Test case 2 result: " << sol.smallestChair(times2, targetFriend2) << endl;
    return 0;
}