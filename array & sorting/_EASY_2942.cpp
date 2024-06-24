#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> res;
        for(int i = 0; i < words.size(); i++){
        	if(words[i].find(x) != string::npos){
        		res.push_back(i);
        	}
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words;
    words.push_back("abc");
    words.push_back("def");
    words.push_back("ghi");
    words.push_back("jkl");
    words.push_back("mno");
    words.push_back("pqrs");
    words.push_back("tuv");
    words.push_back("wxyz");
    vector<int> res = s.findWordsContaining(words, 'p');
    for(int i = 0; i < res.size(); i++){
        cout<<words[res[i]]<<endl;
    }
    return 0;
}