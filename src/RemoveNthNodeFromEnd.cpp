#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n){
		if(head == nullptr)
			return nullptr;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *slow = &dummy, *fast = &dummy;
		for(int i = 0; i < n; i++)
			fast = fast->next;
		while(fast->next != nullptr){
			fast = fast->next;
			slow = slow->next;
		}
		ListNode *tmp = slow->next;
		slow->next = tmp->next;
		delete tmp;
		return dummy.next;
	}
};

int main(){
	return 0;
}