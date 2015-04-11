struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		ListNode dummy(INT_MIN);
		dummy.next = head;
		ListNode *cur = head, *pre = &dummy;
		while(cur != nullptr){
			if(cur->val == pre->val)
				pre->next = cur->next;
			else
				pre = cur;
			cur = cur->next;
		}
		return dummy.next;
	}
};

int main(){
	return 0;
}