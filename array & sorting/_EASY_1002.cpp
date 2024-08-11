#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> freqAllWords(26, INT_MAX); // store frequencies of all the characters occurs on words

        /*
            Idea: I use a vector have 26 elements with initial values is INT_MAX
                Why is the size is 26 instead of other numbers? because 26 is the size of character table
                So why that is INT_MAX instead of other numbers? because i want to get the minimum frequency
                    - why is that? because if it is common characters, need to occur on each the word 
        */

        for(auto &word : words) {
            vector<int> freqEachWord(26, 0);
            // 26 is the same like freqAllWords
            // 0 is compare with INT_MAX of the freqAllWords 

            for(auto &c : word)
                freqEachWord[c - 'a']++; // couting the frequencies of all the characters occurs on word

            for(int i=0; i < freqAllWords.size(); i++)
                freqAllWords[i] = min(freqAllWords[i], freqEachWord[i]); // find the minimum of the frequencies meaning common characters
        }

        for(int i=0; i < freqAllWords.size(); i++) {
                for(int j=0; j < freqAllWords[i]; j++) // pushing all the common characters with frequencies
                    result.push_back(string(1, i+'a')); // need to convert to string pre push
            }


        return result;
    }
};


int main(){
    vector<string> words = {"bella","label","roller"};
    Solution sol;
    vector<string> result = sol.commonChars(words);
    for(auto str : result) cout << str << " ";
    return 0;
}