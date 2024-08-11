#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode* prev = nullptr;
    	ListNode* cur = head;
    	while(cur != nullptr){
    		ListNode* nextNode = cur->next;
    		cur->next = prev;
    		prev = cur;
    		cur = nextNode;
		}
		
		return prev;
    }
};

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);
    
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    
    // Printing the reversed linked list
    ListNode* current = reversedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}

