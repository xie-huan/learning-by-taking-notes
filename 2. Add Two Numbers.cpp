#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	/*********************
	//下面的解法会溢出
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a = 0;
		int b = 0;
		int c;
		int n = 1;
		while (l1 != NULL) {
			a += l1->val*n;
			n = n * 10;
			l1 = l1->next;
		}
		n = 1;
		while (l2 != NULL) {
			b += l2->val*n;
			n = n * 10;
			l2 = l2->next;
		}

		c = a + b;
		
		ListNode* temp = new ListNode(0);
		ListNode* result = temp;
		while (c != 0){
			int x = c % 10;
			ListNode* next = new ListNode(x);
			temp->next = next;
			temp = temp->next;
			c = c / 10;
		}
		return result->next;
	}
	******************/

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* temp = new ListNode(0);
		ListNode* result = temp;

		int flag = 0;
		while (l1 != NULL && l2 != NULL) {
			int a = l1->val;
			int b = l2->val;
			int c = a + b;
			if (flag)
				c++;
			int d = 0;
			if (c >= 10) {
				d = c % 10;
				flag = 1;
			}
			else
			{
				d = c;
				flag = 0;
			}
			ListNode* next = new ListNode(d);
			temp->next = next;
			temp = temp->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != NULL || l2 != NULL) {
			if (l1 != NULL) {
				int a = l1->val;
				if (flag)
					a++;
				int d = 0;
				if (a == 10){
					d = 0;
					flag = 1;
				}
				else {
					d = a;
					flag = 0;
				}
				ListNode* next = new ListNode(d);
				temp->next = next;
				temp = temp->next;
				l1 = l1->next;
			}
			else if (l2 != NULL) {
				int a = l2->val;
				if (flag)
					a++;
				int d = 0;
				if (a == 10) {
					d = 0;
					flag = 1;
				}
				else {
					d = a;
					flag = 0;
				}
				ListNode* next = new ListNode(d);
				temp->next = next;
				temp = temp->next;
				l2 = l2->next;
			}
		}

		if (flag) {
			ListNode* next = new ListNode(1);
			temp->next = next;
			temp = temp->next;
		}
		
		return result->next;
	}
	
};

int main() {

	return 0;
}