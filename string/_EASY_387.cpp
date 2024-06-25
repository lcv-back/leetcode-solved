#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26, 0);
        for(auto i : s) mp[i-'a']++;
        for(int i  = 0;i < s.length();i++)
            if(mp[s[i] - 'a'] == 1) return i;
        
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.firstUniqChar("leetcode")<<endl;
    return 0;
}