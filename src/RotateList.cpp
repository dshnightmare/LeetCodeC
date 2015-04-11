using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k){
		ListNode *cur = head;
		int length = 0;
		while(cur != nullptr){
			cur = cur->next;
			length++;
		}
		if(length <= 1)
			return head;
		k %= length;
		if(k == 0)
			return head;
		
		ListNode *fast = head, *slow = head;
		while(k--){
			fast = fast->next;
		}
		while(fast->next){
			fast = fast->next;
			slow = slow->next;
		}
		
		ListNode *newHead = slow->next;
		fast->next = head;
		slow->next = nullptr;
		return newHead;
	}
};

int main(){
	return 0;
}