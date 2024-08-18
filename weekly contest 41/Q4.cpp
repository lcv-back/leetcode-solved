/*
    Title: Count Substrings that Satisfy K-constraints II

    Description:
        You are given a binary string s and an integer k.

        You are also given a 2D integer array queries, where queries[i] = [li, ri].

        A binary string satisfies the k-constraint if either of the following conditions holds:
            The number of 0's in the string is at most k.
            The number of 1's in the string is at most k.

        Return an integer array answer, where answer[i] is the number of substrings of s[li..ri] that satisfy the k-constraint.

    Example 1:
        Input: s = "0001111", k = 2, queries = [[0,6]]
        Output: [26]
        Explanation: The 26 substrings that satisfy the k-constraint are:
        "000", "001", "011", "111", "0001", "0011", "0111", "1111", "00000", "00001", "00011", "00111", "01111", "11111", 
        "000000", "00000

        For the query [0, 6], all substrings of s[0..6] = "0001111" satisfy the k-constraint except for the 
        substrings s[0..5] = "000111" and s[0..6] = "0001111".

    Example 2:
        Input: s = "010101", k=1, queries = [[0,5], [1,4], [2,3]]
        Output: [15, 9, 3]
        Explanation: The substrings of s with a length greater than 3 do not satisfy the k-constraint.

    Contraints:
        1 <= s.length < 10^5
        s[i] is ether '0' or '1'
        1 <= k <= s.length
        1 <= queries.length < 10^5
        queries[i] == [li, ri]
        0 <= li <= ri < s.length
        All queries are distinct
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        
    }
};

int main(){
    // Example 1
    Solution sol;
    string s1 = "0001111";
    int k1 = 2;
    vector<vector<int>> queries1 = {{0,6}};
    vector<long long> result1 = sol.countKConstraintSubstrings(s1, k1, queries1);
    cout << "Example 1: ";
    for(int i = 0; i < result1.size(); i++)
        cout << result1[i] << " ";
    cout << endl;

    // Example 2
    string s2 = "010101";
    int k2 = 1;
    vector<vector<int>> queries2 = {{0,5}, {1,4}, {2,3}};
    vector<long long> result2 = sol.countKConstraintSubstrings(s2, k2, queries2);
    cout << "Example 2: ";  
}