#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<char, int> P; //Utility...
    string frequencySort(string s) {
       vector<P> helper(123);
       for(char &ch : s){
           int frequency = helper[ch].second; // Frequency of characters present in vector helper...
           helper[ch] = {ch, frequency + 1};
       }
       auto lambda = [&](P&p1, P&p2){
           return p1.second > p2.second; // Comparator...
       };
       sort(begin(helper), end(helper), lambda); // Sort the vector helper...
       string ans = "";
       for(int i = 0; i < 123; ++i){
           if(helper[i].second > 0){
               char ch = helper[i].first;
               int frequency = helper[i].second;
               string reference = string(frequency, ch);
               ans += reference;
           }
       }
       return ans;
    }
};

int main(){
    Solution s;
    cout << s.frequencySort("tree") << endl;
    return 0;
}