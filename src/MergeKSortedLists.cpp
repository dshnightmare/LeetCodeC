#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists){
		ListNode dummy(-1), *cur = &dummy;
		priority_queue<ListNode *, vector<ListNode *>, cmp> q;
		for(auto i = lists.begin(); i < lists.end(); i++)
			if(*i != nullptr)
				q.push(*i);
		while(!q.empty()){
			ListNode *tmp = q.top();
			q.pop();
			cur->next = tmp;
			cur = cur->next;
			if(tmp->next != nullptr)
				q.push(tmp->next);
		}
		return dummy.next;
	}
	
	struct cmp{
		bool operator()(ListNode *p1, ListNode *p2){
			return p1->val > p2->val;
		}
	};
};

int main(){
	return 0;
}