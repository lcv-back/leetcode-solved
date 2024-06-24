#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // T?o m?ng d?m t?n su?t cho m?i ký t?
        int cnt[256] = {0};
        for(char c : s){
            cnt[c]++;
        }

        // T?o vector các c?p (t?n su?t, ký t?)
        vector<pair<int, char>> freq;
        for(int i = 0; i < 256; i++){
            if(cnt[i] > 0){
                freq.push_back({cnt[i], (char)i});
            }
        }

        // S?p x?p vector d?a trên t?n su?t (gi?m d?n)
        sort(freq.begin(), freq.end(), greater<pair<int, char>>());

        // Xây d?ng chu?i k?t qu?
        string res = "";
        for(auto& p : freq){
            res.append(p.first, p.second);
        }

        return res;
    }
};

int main(){
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;
    return 0;
}