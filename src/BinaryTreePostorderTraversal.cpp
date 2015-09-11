#include <vector>
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
	vector<int> postorderTraversal(TreeNode *root){
		vector<int> ret;
		if(root == nullptr)
			return ret;
		stack<TreeNode*> s;
		TreeNode *pre = root, *cur;
		s.push(root);
		while(!s.empty()){
			cur = s.top();
			if((cur->left == nullptr && cur->right == nullptr) ||
				cur->left == pre || cur->right == pre){
				ret.push_back(cur->val);
				s.pop();
				pre = cur;	
			}
			else{
				if(cur->right != nullptr)
					s.push(cur->right);
				if(cur->left != nullptr)
					s.push(cur->left);
			}
		}
		return ret;
	}
};