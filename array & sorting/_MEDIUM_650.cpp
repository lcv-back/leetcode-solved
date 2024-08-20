#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int d = 2;
        while (n > 1) {
            // If d is prime factor, keep dividing
            // n by d until is no longer divisible
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};

int main() {
	Solution sol;
	int tc1 = 3, tc2 = 1;
	cout << "Testcase 1: " << sol.minSteps(tc1) << endl;
	cout << "Testcase 2: " << sol.minSteps(tc2) << endl;
	return 0;
}
