#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int result = 0;

        // using two pointers to find the middle node
        ListNode* slow = head;
        ListNode* fast = head;

        // find the middle node
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // after the loop ended was found the middle node, will reverse the ll at the slow node
        ListNode* secondHaft = reverse(slow);
        ListNode* firstHaft = head;

        // calculate the sum of the paired of the first and corresponding node
        while(secondHaft) {
            result = max(result, firstHaft->val + secondHaft->val);
            firstHaft = firstHaft->next;
            secondHaft = secondHaft->next;
        }

        return result;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur != nullptr) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        head = prev;

        return head;
    }
};

int main(){
    Solution sol;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << sol.pairSum(head) << endl; // Output: 6
    return 0;
}