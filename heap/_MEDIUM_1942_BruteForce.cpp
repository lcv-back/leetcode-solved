#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Input: An array 0-indexed, a integer representation of target friend
    Output: The index of the smallest chair that can accommodate the friends will sit on
    Brute Force with nested loop
    Idea:
    - The first approach we'll look at is simulating the process. We'll start by sorting the input 
    so that we can process the people in chronological order. We can then iterate over the people 
    in order of when they arrive and determine which chair each person will take until we determine 
    the chair for the target person.

    - To accomplish this, we'll use an array chairTime with a length of n. Even though there are an 
    infinite number of chairs, we only need to worry about the first n - even if everybody is at the 
    party simultaneously, we won't need more than n chairs. chairTime[i] will represent the time the i th
    chair becomes available. Initially, all values of chairTime are 0, because every chair is available 
    at the beginning.

    For each person (arrival, leaving), we will iterate over chairTime and find the first chair with 
    a value less than or equal to arrival. This is the chair that the current person will take. Let's 
    say that it is the i th chair. 
    We can then set chairTime[i] = leaving since that's when the chair will become available again.

    We can immediately return the answer when we figure out which seat targetFriend will take.
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

/*
    Time: O(n^2); Space: O(n)
*/

int main() {
    Solution sol;
    vector<vector<int>> times1 = {{1,4},{2,3}, {4, 6}};
    int targetFriend1 = 1;
    cout << sol.smallestChair(times1, targetFriend1) << endl; // Output: 1

    vector<vector<int>> times2 = {{3,10},{1,5}, {2, 6}};
    int targetFriend2 = 0;
    cout << sol.smallestChair(times2, targetFriend2) << endl; // Output: 2
    return 0;
}
