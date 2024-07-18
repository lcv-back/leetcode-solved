#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = indexChar(word, ch);
        reverse(word.begin(), word.begin()+index+1);
        return word;
    }

    int indexChar(string word, char ch) {
        for(int i=0; i < word.size(); i++){
            if(word[i] == ch){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.reversePrefix("abcdedfss", 'd') << endl;
    return 0;
}