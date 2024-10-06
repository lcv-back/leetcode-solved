#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1map;
        int m=s1.length();
        int n=s2.length();

        for(char c : s1) s1map[c]++;

        unordered_map<char, int> s2map;
        for(int i=0; i<n-m+i; i++){
            for(int j=i; j<m+i; j++) s2map[s2[j]]++;
            if(s1map == s2map) return true;
            s2map.clear();
        }

        return false;
    }

private:
    bool compareMaps(const std::unordered_map<char, int>& map1,
                    const std::unordered_map<char, int>& map2) {
        for (const auto& pair : map1) {
            if (map2.count(pair.first) == 0 || map2.at(pair.first) != pair.second) {
                return false;
            }
        }
    return true;
}
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution sol;
    cout << sol.checkInclusion(s1, s2) << endl;
    return 0;
}