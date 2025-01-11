#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            // If the current box contains a ball, calculate the number of moves
            // for every box.
            if (boxes[currentBox] == '1') {
                for (int newPosition = 0; newPosition < boxes.length();
                     newPosition++) {
                    answer[newPosition] += abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
};
int main(){
	Solution sol;
	string boxes = "110";
	vector<int> res = sol.minOperations(boxes);
	for(int x: res) cout << x << " ";
	return 0;
}