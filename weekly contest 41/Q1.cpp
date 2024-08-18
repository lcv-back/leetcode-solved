/*
    Title: Count Substrings That Satisfy K-Constraint I

    Description: 
        You are given a binary string s and an integer k.
        A binary string satisfies the k-constraint if either of the following conditions holds:
        The number of 0's in the string is at most k.
        The number of 1's in the string is at most k.
        Return an integer denoting the number of substrings of s that satisfy the k-constraint.

    Example 1:
        Input: s = "10101", k = 1
        Output: 12
        Explanation: 
        Substrings that satisfy the k-constraint are: 
        "10", "01", "10", "101", "010", "1010", "10101", "01010", "101010", "010101", "1010101", "0101010".
    
    Example 2:
        Input: s = "1010101", k = 2
        Ouput: 25
        Explanation:
        Substrings that satisfy the k-constraint are:
        "10", "01", "10", "101", "010", "1010", "10101", "01010", "101010", "010101", "1010101", "0101010", 
        "101", "010", "1010", "0101", ...

    Example 3: 
        Input: s = "11111", k = 1
        Output: 15
        Explanation:
        Substrings that satisfy the k-constraint are: 
        "1", "11", "111", "1111", "11111", "111111", "1111111", "11111111", "111111111", 
        "1111111111", "11111111111", "1111111111, ...
    
    Contraints: 
        1 <= s.length <= 50
        1 <= k < s.length
        s[i] is either '0' or '1'
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;

        for(int i=0; i<n; i++) {
            int zeroCount = 0, oneCount = 0;
            for(int j=i; j<n; j++) {
                if(s[j] == '0') zeroCount++;
                else oneCount++;

                if(zeroCount <= k || oneCount <= k) count++;
                else break;
            }
        }

        return count;
    }
};


int main() {
    Solution sol;

    // Example 1
    string s1 = "10101";
    int k1 = 1;
    cout << "Example 1: " << sol.countKConstraintSubstrings(s1, k1) << endl; // Output: 12

    // Example 2
    string s2 = "1010101";
    int k2 = 2;
    cout << "Example 2: " << sol.countKConstraintSubstrings(s2, k2) << endl; // Output: 25

    // Example 3
    string s3 = "11111";
    int k3 = 1;
    cout << "Example 3: " << sol.countKConstraintSubstrings(s3, k3) << endl; // Output: 15

    return 0;
}