struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	bool isPalindrome(ListNode * head){
		if(head == nullptr)
			return true;
		ListNode *mid = findMiddle(head);
		ListNode *l1 = head, *l2 = reverse(mid->next);
		while(l1 != nullptr && l2 != nullptr && l1->val == l2->val){
			l1 = l1->next;
			l2 = l2->next;
		}
		return l2 == nullptr;
	}
	
	ListNode *findMiddle(ListNode *head){
		if(head == nullptr)
			return head;
		ListNode *fast = head, *slow = head;
		while(fast->next !=  nullptr && fast->next->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	
	ListNode *reverse(ListNode *head){
		ListNode *rev = nullptr, *cur = head;
		while(cur != nullptr){
			ListNode *tc = cur;
			cur = cur->next;
			tc->next = rev;
			rev = tc;
		}
		return rev;
	}
};