struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode* removeElements(ListNode *head, int val){
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *cur = &dummy;
		while(cur->next != nullptr){
			if(cur->next->val == val){
				ListNode *tmp = cur->next;
				cur->next = tmp->next;
				delete tmp;
			}
			else
				cur = cur->next;
		}
		return dummy.next;
	}
};
