/*
    Title: Find the largest Palindrome Divisible by K

    Description:
        You are given two positive integers n and k.

        An integer x is called k-palindromic if:
            x is a palindrome
            x is divisible by k.
        Return the largest integer having n digits (as a string) that is k-palindromic.

        Note that the integer must not have leading zeros.

    Example 1:
        Input: n = 3, k =5
        Output: "595"
        Explanation: 595 is the largest 3-digit k-palindromic integer.

    Example 2:
        Input: n=1, k=4
        Output: 8
        Explanation: 4 and 8 are the only k-palindromic integers with 1 digit.

    Example 3: 
        Input: n=5, k=6
        Output: "89898"

    Contraints:
        1 <= n <= 10^5
        1 <= k <= 9
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindrome(int n, int k) {
        
    }
};

int main() {
    Solution s;
    cout << s.largestPalindrome(3, 5) << endl; // Output: "595"
    cout << s.largestPalindrome(1, 4) << endl; // Output: "8"
    cout << s.largestPalindrome(5, 6) << endl; // Output: "89898"
    return 0;
}