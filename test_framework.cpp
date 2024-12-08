#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <F:/DSA/leetcode_solved/include/json.hpp> 

using json = nlohmann::json;
using namespace std;

// Hàm cần kiểm tra
int exampleFunction(int a, int b) {
    return a + b; // Thay bằng hàm bài toán
}

// Hàm kiểm tra testcase
bool runTestCase(const json& testcase) {
    vector<int> input = testcase["input"];
    int expectedOutput = testcase["output"];
    
    // Gọi hàm cần kiểm tra
    int result = exampleFunction(input[0], input[1]);

    // So sánh kết quả
    if (result == expectedOutput) {
        cout << "PASS: " << testcase["description"] << endl;
        return true;
    } else {
        cout << "FAIL: " << testcase["description"] << endl;
        cout << "Expected: " << expectedOutput << ", but got: " << result << endl;
        return false;
    }
}

int main() {
    // Đọc file testcase
    ifstream file("testcases.json");
    if (!file.is_open()) {
        cerr << "Unable to open testcase file!" << endl;
        return 1;
    }

    json testcases;
    file >> testcases;

    // Chạy tất cả testcase
    int passCount = 0, totalCount = testcases.size();
    for (const auto& testcase : testcases) {
        if (runTestCase(testcase)) {
            passCount++;
        }
    }

    // Kết quả tổng quát
    cout << "Summary: " << passCount << "/" << totalCount << " test cases passed." << endl;

    return 0;
}
