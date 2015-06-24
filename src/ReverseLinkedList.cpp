struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode* reverseList(ListNode *head){
		ListNode *ret = nullptr;
		while(head !=  nullptr){
			ListNode *cur = head;
			head = head->next;
			cur->next = ret;
			ret = cur;
		}
		return ret;
	}
};