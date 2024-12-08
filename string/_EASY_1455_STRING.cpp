#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        return (searchWord.find(sentence) != string::npos) ? 
    }
};

int main() {
    Solution sol;
    string tc1 = "i love eating burger";
    string sw1 = "burg";
    string tc2 = "this problem is an easy problem";
    string sw2 = "pro";
    string tc3 = "i am tired";
    string sw3 = "you";

    int res1 = sol.isPrefixOfWord(tc1, sw1);
    int res2 = sol.isPrefixOfWord(tc2, sw2);
    int res3 = sol.isPrefixOfWord(tc3, sw3);
    string pass = "pass";
    string fail = "fail";
    if(res1 == 4) cout << pass; else cout << fail;
    if(res2 == 2) cout << pass; else cout << fail;
    if(res3 == -1) cout << pass; else cout << fail;
}