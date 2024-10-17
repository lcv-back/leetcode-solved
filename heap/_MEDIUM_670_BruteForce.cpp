#include <iostream>
#include <string>
#include <utility>
#include <cmath>
using namespace std;

/*Constraints: 0 <= num <= 10^8*/

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int maxNum = num;
        for(int i = 0; i < numStr.length(); i++){
            for (int j=i+1; j<numStr.length(); j++) {
                swap(numStr[i], numStr[j]);
                maxNum = max(maxNum, stoi(numStr));
                swap(numStr[i], numStr[j]);
            }
        }
        return maxNum;
    }
};

/*
    Time complexity: O(n^2) and Space complexity: O(n)
*/

int main(){
	Solution sol;
	int num1 = 2736;
	cout << sol.maximumSwap(num1) << endl;

	int num2 = 9973;
	cout << sol.maximumSwap(num2) << endl;
	return 0;
}