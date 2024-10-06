#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string word;

        deque<string> deque1, deque2;

        stringstream ss1(sentence1), ss2(sentence2);
        while (ss1 >> word) deque1.push_back(word);
        while (ss2 >> word) deque2.push_back(word);

        while (!deque1.empty() && !deque2.empty() && deque1.front() == deque2.front()){
            deque1.pop_front();
            deque2.pop_front();
        }

        while (!deque1.empty() && !deque2.empty() && deque1.back() == deque2.back()){
            deque1.pop_back();
            deque2.pop_back();
        }

        return deque1.empty() || deque2.empty();

        // Time complexity: O(m + n), Space complexity: O(m + n)
        // m is number of words sentence1, n is number of sentence2
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main(){
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";
    Solution sol;
    cout << sol.areSentencesSimilar(sentence1, sentence2) << endl;
    return 0;
}