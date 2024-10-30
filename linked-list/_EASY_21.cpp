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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while(list1 != nullptr && list2 != nullptr) {
        	if(list1->val <= list2->val) {
        		tail->next = list1;
        		list1 = list1->next;
			} else {
				tail->next = list2;
				list2 = list2->next;
			}
			tail = tail->next;
		}
		
		if(list1 != nullptr) {
			tail->next = list1;
		} else {
			tail->next = list2;
		}
		
		return dummy.next;
    }
};

void printLL(ListNode* head) {
	ListNode* cur = head;
	while(cur != nullptr) {
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << "null";
}

int main(){
	Solution sol;
	
	// list 1
	ListNode* node3 = new ListNode(4);
	ListNode* node2 = new ListNode(2, node3);
	ListNode* list1 = new ListNode(1, node2);
	
	// list 2
	ListNode* node5 = new ListNode(4);
	ListNode* node4 = new ListNode(3, node5);
	ListNode* list2 = new ListNode(1, node4);
	
	ListNode* result = sol.mergeTwoLists(list1, list2);
	
	printLL(result);
	
	return 0;
}
