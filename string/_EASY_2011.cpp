#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const std::string& var : operations) {
            if (var == "X++" || var == "++X") {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};

int main(){
    Solution s;
    vector<string> operations = {"++X", "X++"};
    cout << s.finalValueAfterOperations(operations) << endl;
    return 0;
}