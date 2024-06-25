#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int count = 0;
        unordered_map<char, int> map;
        for(int i = 0; i < t.size(); i++){
            map[t[i]] = i;
        }

        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) > 0){
                int idx = map[s[i]];
                count += abs(idx - i);
            }
        }

        return count;
    }
};

int main(){
    Solution s;
    cout << s.findPermutationDifference("123456789", "987654321") << endl;
    return 0;
}