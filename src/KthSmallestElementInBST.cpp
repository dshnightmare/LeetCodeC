#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	int kthSmallest(TreeNode *root, int k){
		// inorder
		if(root == nullptr)
			return 0;
		int count = 0, result = 0;
		TreeNode *p = root;
		stack<TreeNode *> s;
		while(!s.empty() || p != nullptr){
			if(p != nullptr){
				s.push(p);
				p = p->left;
			}
			else{
				p = s.top();
				s.pop();
				result = p->val;
				count++;
				p = p->right;
				if(count == k)
					break;
			}
		}
		return result;
	}
};