struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		if(head == nullptr)
			return head;
		ListNode dummy(INT_MIN);
		dummy.next = head;
		ListNode *dis = &dummy, *pre = head, *cur = head->next;
		bool flag = false;
		while(cur != nullptr){
			if(cur->val == pre->val)
				flag = true;
			else{
				if(flag){
					dis->next = cur;
					flag = false;
				}
				else{
					dis = pre;
				}
			}
			pre = cur;
			cur = cur->next;
		}
		if(flag)
			dis->next = cur;
		return dummy.next;
	}
};

int main(){
	return 0;
}