#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.length(); i++)
        {
            s[i]=tolower(s[i]);
        }
        return s;
    }
};

int main(){
    Solution s;
    cout<<s.toLowerCase("Hello");
    return 0;
}