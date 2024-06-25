#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {

         vector<int>v(26,0);

        for(int i=0;i<t.length();i++){
            v[t[i]-'a']++;
        }

        for(int i=0;i<s.length();i++){
            v[s[i]-'a']--;
        }

        for(int i=0;i<v.size();i++){
            if(v[i]==1)return i+'a';//index se char--i me a ki ascii value add
        }

        
        return 0;

        
    }
};

int main(){
    Solution s;
    cout<<s.findTheDifference("abcd","abcde")<<endl;
    return 0;
}