#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;
        for(int i=0;i<sentences.size();i++){
            int count=0;
            for(int j=0;j<sentences[i].length();j++){
                if(sentences[i][j]==' '){
                    count++;
                maxi=max(count,maxi);}
            }
        }
        return maxi+1;  
    }
};

int main(){
    Solution s;
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout << s.mostWordsFound(sentences) << endl;
    return 0;
}