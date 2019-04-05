#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//206. Reverse Linked List
ListNode* reverseList(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode* pre = NULL;
	ListNode* curr = head;

	while (curr != NULL) {
		ListNode* next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	return pre;
}

//83. Remove Duplicates from Sorted List
ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL)
		return head;

	ListNode* newNode = new ListNode(0);
	newNode->next = head;

	ListNode* pre = newNode;
	ListNode* curr = newNode->next;

	while (curr != NULL) {
		ListNode* next = curr->next;
		if (next == NULL)
			break;
		if (curr->val == next->val) {
			ListNode* delNode = next;
			curr->next = delNode->next;
			delete delNode;
		}
		else {
			pre = curr;
			curr = next;
		}
	}
	delete newNode;
	return head;
}

//86. Partition List
ListNode* partition(ListNode* head, int x) {
	if (head == NULL)
		return head;
	ListNode* newNode = new ListNode(0);
	newNode->next = head;

	ListNode* pre = newNode;
	ListNode* curr = newNode;

	while (curr->next != NULL) {
		if (curr->next->val >= x) {

		}
		if (curr->next->val < x) {
			ListNode* next = curr->next;
			curr->next = next->next;
			next->next = pre->next;
			pre->next = next;
			pre = pre->next;
		}
		else {

		}
	}

}

