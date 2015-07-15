using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	TreeNode *sortedListToBST(ListNode *head){
		int len = 0;
		ListNode *p = head;
		while(p){
			len++;
			p = p->next;
		}
		return help(head, 0, len - 1);
	}
	
	TreeNode *help(ListNode* &list, int start, int end){
		if(start > end)
			return nullptr;
		int mid = start + (end - start) / 2;
		TreeNode *leftChild = help(list, start, mid - 1);
		TreeNode *parent = new TreeNode(list->val);
		parent->left = leftChild;
		list = list->next;
		parent->right = help(list, mid + 1, end);
		return parent;
	}
};
