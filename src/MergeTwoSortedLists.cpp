#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
		ListNode dummy(-1), *head = &dummy, *cur = head;
		while(l1 != nullptr && l2 != nullptr){
			if(l1->val < l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if(l1 == nullptr)
			cur->next = l2;
		if(l2 == nullptr)
			cur->next = l1;
		return dummy.next;
	}
};

int main(){
	return 0;
}