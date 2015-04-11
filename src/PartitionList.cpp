struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode *partition(ListNode *head, int x){
		ListNode *dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1);
		ListNode *cur1 = dummy1, *cur2 = dummy2, *cur = head;
		while(cur != nullptr){
			if(cur->val < x){
				cur1->next = cur;
				cur1 = cur;
			}
			else{
				cur2->next = cur;
				cur2 = cur;
			}
			cur = cur->next;
		}
		cur2->next = nullptr;
		cur1->next = dummy2->next;
		return dummy1->next;
	}
};