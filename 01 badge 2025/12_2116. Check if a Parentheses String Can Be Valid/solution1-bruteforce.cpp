#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; // Nếu chuỗi có độ dài lẻ, không thể hợp lệ.

        int open = 0, flexible = 0;

        // Duyệt từ trái sang phải
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                flexible++; // Có thể thay đổi ký tự này.
            } else if (s[i] == '(') {
                open++; // Đếm ngoặc mở cố định.
            } else {
                // Nếu gặp ngoặc đóng
                if (open > 0) {
                    open--; // Sử dụng một ngoặc mở để cân bằng.
                } else if (flexible > 0) {
                    flexible--; // Sử dụng một ký tự có thể thay đổi để cân bằng.
                } else {
                    return false; // Không thể cân bằng được ngoặc.
                }
            }
        }

        // Kiểm tra số ngoặc mở còn dư sau khi duyệt từ trái sang phải.
        if (open > flexible) return false;

        open = 0, flexible = 0;

        // Duyệt từ phải sang trái
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                flexible++;
            } else if (s[i] == ')') {
                open++;
            } else {
                // Nếu gặp ngoặc mở
                if (open > 0) {
                    open--;
                } else if (flexible > 0) {
                    flexible--;
                } else {
                    return false;
                }
            }
        }

        return open <= flexible;
    }
};

int main() {
    Solution sol;
    string s = "(()))()))(()((()()(((()))()()()()()())))()()(()())()(()((()()((()((((((()(()()(()()())(((((())((()))))()(((((((()()())()))())((((((()(())())()((())()()((())((((())(((())(())()()))(((()()())())))((()))))()()()((()))())(())(((()()((())(())(())())()((()))())(())()(()())((((()(((())((()()())(((()(((((()))()))))))(()((())())(())))))(())(((())()()(()))())())))(((())))()()))()())))))())()(()()))(())(()())))())()))((((())(()))()(((())())(()(()))()))((()(())()()))))())(()(((((()";
    string locked = "110001111001011100000100011110101000100110010010011001110010111111100111000100000000101111101001111111011101001110011001001100100001100000000010100010101101100000100001000110111000111110110010111011010010100011111101110011100010010001111001010001001000111101101111111011001000100111100110101000100011011001001100110011111111111100101000100111111100000100101101000101111101000011110001001011111010011010000100100000000011101011001110000110011000100001110101100101111111110100";
    cout << sol.canBeValid(s, locked);
    return 0;
}
