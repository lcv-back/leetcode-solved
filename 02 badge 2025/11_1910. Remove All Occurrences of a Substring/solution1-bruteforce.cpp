#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {  // Tìm vị trí xuất hiện của 'part' trong 's'
            size_t index = s.find(part);  // Lấy chỉ số của 'part' trong 's'
            s = s.substr(0, index) + s.substr(index + part.length());  // Cắt bỏ 'part' khỏi 's'
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "daabcbaabcbc";
    string part = "ab";
    cout << solution.removeOccurrences(s, part) << endl;  // In ra kết quả
    return 0;
}
