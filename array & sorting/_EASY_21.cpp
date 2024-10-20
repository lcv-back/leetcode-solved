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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* dummy;
        
        // brute force
        
        while(cur1 != nullptr) {
        	// find the first element then cur2 < cur1
        	while(cur2 != nullptr) {
        		if(cur2->val >= cur1->val) {
        			ListNode* temp = cur1->next;
        			cur1->next = cur2;
        			cur2->next = temp;
        			
				}
				cur2 = cur2->next;
			}
			cur1 = cur1->next;
		}
		return cur1;
    }
};

int main() {
	// a linked list 1
    ListNode* node3 = new ListNode(4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head1 = new ListNode(1, node2);
    
    // a linked list 2
    ListNode* node5 = new ListNode(4);
    ListNode* node4 = new ListNode(3, node5);
    ListNode* head2 = new ListNode(1, node4);
    
    Solution sol;
    ListNode* result = sol.mergeTwoLists(head1, head2);
    
    // printing the merged two sorted list
    ListNode* cur = result;
    while(cur != nullptr){
    	cout << cur->val << "->";
    	cur = cur->next;
	}
	return 0;
}
