#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int arr[256] = {0};

        for(int i=0; i<s.size(); i++){
            arr[s[i]]++;
            arr[t[i]]--;
        }

        for(int i=0; i< 256; i++) if(arr[i]) return false;
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isAnagram("listen", "silent") << endl;  // true
    cout << s.isAnagram("hello", "world") << endl;  // false
    return 0;
}