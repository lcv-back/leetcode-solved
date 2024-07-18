#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,string> URLs ;

    string RandomGenerator(){
        string str = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890" , ans = "";
        int c = time(0);
        while(c){
            ans = ans + str[c%str.size()];  c/=str.size();
        }
        return ans ;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = RandomGenerator();
        URLs[shortUrl] = longUrl ; 
        return shortUrl ; 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return URLs[shortUrl] ; 
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(){
    Solution s ;
    cout << s.encode("https://leetcode.com/problems/design-tinyurl") << endl ;
    cout << s.decode("http://tinyurl.com/4e9iAk") << endl ;
    return 0 ;
}