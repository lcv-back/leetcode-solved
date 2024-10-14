#include <queue>
#include <iostream>
#include <bits/stdc++.h>
#include <deque>
using namespace std;
/*
	input: an integer array, a integer number k
	process: 
	In one operation:
		- choose an index i such that 0 <= i < nums.length
		- increase your score by nums[i], and
		- replace nums[i] with ceil(nums[i] / 3).
		The ceiling function ceil(val) is the least integer greater than or equal to val.
	output: the maximum possible score you can attain after applying exactly k operations
*/

/*
    Idea:
        We are given an integer array nums and a number k. The goal is to maximize a starting score of 0 
        by performing an operation exactly k times. In each operation, we choose an index i, add nums[i] 
        to the score, and replace nums[i] with nums[i] / 3.

        We can solve this using a max heap, which allows us to access the largest element in the array 
        efficiently. We need to select the largest number, add it to the score, and then replace it with 
        one-third of its value, doing this k times.

        First, we build a max heap from the numbers in nums. For each operation, we extract the largest number, 
        add it to the score, and replace it with its one-third value. We then push this new value back into the 
        heap. Repeating this process k times ensures that the score is maximized.

        Algorithm
            - Initialize an integer ans to store the total score:
            - Create a max-heap (priority_queue) given by pq and push all elements of the vector nums into the heap.
            - Repeat the following steps k times:
                - Extract the largest element from the heap using pq.top(), and remove it from the heap using pq.pop().
                - Add this largest element to ans to update the total score.
                - Push the one-third value of the largest element (rounded up) into the heap.
            Return the value of ans.
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int ans = 0;
        // Create max-heap to store the elements.
        priority_queue<int> pq;
        for (auto& i : nums) {
            pq.push(i);
        }

        while (k--) {
            // Add the maxElement in ans and push it's one-third value in the priority queue.
            int maxElement = pq.top();
            ans += maxElement;
            pq.pop();
            pq.push(ceil(maxElement / 3.0));
        }
        return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {10,10,10,10,10};
	int k=5;
	cout << sol.maxKelements(nums, k) << endl;

	vector<int> nums1 = {1,10,3,3,3};
	int k1=3;
	cout << sol.maxKelements(nums1, k1) << endl;
	return 0;
}