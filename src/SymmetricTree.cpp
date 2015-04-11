using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
	bool isSymmetric(TreeNode *root){
		if(root == nullptr)
			return true;
		else
			return help(root->left, root->right);
	}
	
	bool help(TreeNode *left, TreeNode *right){
		if(left == nullptr && right == nullptr)
			return true;
		if(left == nullptr || right == nullptr)
			return false;
		return left->val == right->val && help(left->left, right->right) && help(left->right, right->left);
	}
};