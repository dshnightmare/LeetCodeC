#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode *reverseBetween(ListNode *head, int m, int n){
		if(m == n)
			return head;
		n -= m;
		ListNode dummy(-1), *cur = &dummy, *pre = &dummy;
		dummy.next = head;
		while(m--){
			pre = cur;
			cur = cur->next;
		}
		
		ListNode *last = cur, *first = cur;
		cur = cur->next;
		//cout << n << endl;
		while(n--){
			ListNode *tmp = cur->next;
			cur->next = first;
			first = cur;
			cur = tmp;
		}
		
		pre->next = first;
		last->next = cur;
		return dummy.next;
	}
};

int main(){
	ListNode a(3), b(5);
	a.next = &b;
	Solution s;
	s.reverseBetween(&a, 1, 2);
}