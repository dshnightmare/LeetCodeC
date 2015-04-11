#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	void recoverTree(TreeNode *root){
		if(root == nullptr)
			return;
		stack<TreeNode *> s;
		TreeNode *p = root, *first = nullptr, *second = nullptr, *prev = nullptr;
		while(!s.empty() || p != nullptr){
			if(p != nullptr){
				s.push(p);
				p = p->left;
			}
			else{
				p = s.top();
				s.pop();
				if(prev != nullptr && p->val < prev->val){
					if(first == nullptr){
						first = prev;
						second = p;
					}
					else
						second = p;
				}
				prev = p;
				p = p->right;
			}
		}
		//cout << first->val << "  " << second->val << endl;
		swap(first->val, second->val);
	}
};

int main(){
	TreeNode root(2);
	root.left = new TreeNode(1);
	root.left->right = new TreeNode(3);
	Solution s;
	s.recoverTree(&root);
	cout << root.val << endl;
}