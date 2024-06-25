#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        int n = address.size();
        for(int i=0;i<n;i++)
        {
            if(address[i] == '.')
            {
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');
            }
            else
            {
                s.push_back(address[i]);
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    cout<<s.defangIPaddr("1.1.1.1")<<endl;
    return 0;
}