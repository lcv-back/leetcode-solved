#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		int count = 0;
		
		ListNode* cur1 = list1;
		ListNode* cur2 = list2;
		ListNode* startLink = nullptr;
		ListNode* endLink = nullptr;
		
		// find the front a'th node
		while(count < a-1) {
			cur1 = cur1->next; // keep at a-1'th node
			count++;
		}
		startLink = cur1; // a-1
		
		// find the back b'th node
		while(count < b) {
			cur1 = cur1->next; // keep at b'th node
			count++;
		}
		endLink = cur1; // b

		// connect start link with list2
		startLink->next = cur2;		

		while(cur2->next != nullptr) {
			cur2 = cur2->next;
		}

		// connect the last node of list2 with end node
		cur2->next = endLink->next;

		return list1;
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

int main() {
	Solution sol;
	
	// list1
	ListNode* node6 = new ListNode(5);
	ListNode* node5 = new ListNode(9, node5);
	ListNode* node4 = new ListNode(6, node5);
	ListNode* node3 = new ListNode(13, node4);
	ListNode* node2 = new ListNode(1, node3);
	ListNode* list1 = new ListNode(10, node2);
	
	int a=3, b=4;
	
	// list2
	ListNode* node8 = new ListNode(1000002);
	ListNode* node7 = new ListNode(1000001, node8);
	ListNode* list2 = new ListNode(1000000, node7);
	
	ListNode* result = sol.mergeInBetween(list1, a, b, list2);
	
	printLL(result);
	
	return 0;
}
