#include <string>
#include<iostream>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        while (true) {
            bool found = false; // Đánh dấu nếu có thao tác xóa trong vòng lặp
            for (int i = 0; i < s.size(); ++i) {
                if (canProcess(s, i)) {
                    // Tìm vị trí gần nhất bên trái và bên phải có ký tự giống với s[i]
                    int left = i - 1;
                    while (left >= 0 && s[left] != s[i]) --left;
                    int right = i + 1;
                    while (right < s.size() && s[right] != s[i]) ++right;

                    // Xóa ký tự bên trái và bên phải
                    if (left >= 0 && right < s.size()) {
                        s.erase(right, 1); // Xóa phải trước
                        s.erase(left, 1);  // Xóa trái sau
                        found = true;      // Đánh dấu đã thực hiện xóa
                        break;             // Dừng lại để bắt đầu lại từ đầu
                    }
                }
            }
            if (!found) break; // Không còn gì để xóa, thoát vòng lặp
        }
        return s.size(); // Trả về độ dài cuối cùng của chuỗi
    }

private:
    // Hàm kiểm tra xem vị trí i có hợp lệ để xử lý không
    bool canProcess(const string& s, int i) {
        if (i <= 0 || i >= s.size() - 1) return false; // Kiểm tra giới hạn
        char target = s[i];
        bool left_found = false, right_found = false;
        // Kiểm tra bên trái
        for (int j = 0; j < i; ++j) {
            if (s[j] == target) {
                left_found = true;
                break;
            }
        }
        // Kiểm tra bên phải
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[j] == target) {
                right_found = true;
                break;
            }
        }
        return left_found && right_found;
    }
};


int main(){
	Solution sol;
	string s = "abaacbcbb";
	cout << sol.minimumLength(s) << endl;
	return 0;
}