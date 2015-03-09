struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNumbers {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode dummy(-1);
		ListNode *cur = &dummy, *left = nullptr;
		int carry = 0, sum;
		while(l1 != nullptr && l2 != nullptr){
			sum = l1->val + l2->val + carry;
			if(sum >= 10){
				sum -= 10;
				carry = 1;
			}
			else
				carry = 0;
			cur->next = new ListNode(sum);
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		if(l1 != nullptr)
			left = l1;
		else
			left = l2;
		while(left != nullptr){
			sum = left->val + carry;
			if(sum >= 10){
				sum -= 10;
				carry = 1;
			}
			else
				carry = 0;
			cur->next = new ListNode(sum);
			cur = cur->next;
			left = left->next;
		}
		if(carry > 0){
			cur->next = new ListNode(carry);
		}
		return dummy.next;
	}
};

int main(){
	return 0;
}