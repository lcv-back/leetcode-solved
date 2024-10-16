#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*
    Constraints:
        0 <= a,b,c <= 100
        a+b+c > 0
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> pq;

        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(res.size()>=2 && res.back()==top.second && res[res.size()-2]==top.second && (res.size()<3 || res[res.size()-3]!=top.second)){
                if(pq.empty()) break;
                auto next_top = pq.top();
                pq.pop();
                res += next_top.second;
                if(--next_top.first) pq.push(next_top);
                pq.push(top);
            } else {
                res += top.second;
                if(--top.first>0) pq.push(top);
            }
        }
        return res;
    }
};

int main(){
    int a1=1,b1=1,c1=7;
    Solution sol;
    cout << sol.longestDiverseString(a1,b1,c1) << endl;  // Output: ccaccbcc

    int a2=7,b2=1,c2=0;
    cout << sol.longestDiverseString(a2,b2,c2) << endl;  // Output: aabaa

    int a3 = 2, b3 = 2, c3 = 1;
    cout << sol.longestDiverseString(a3, b3, c3) << endl; // Output: aabbc 

    return 0;
}