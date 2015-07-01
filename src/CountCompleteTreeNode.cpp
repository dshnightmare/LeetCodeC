struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	int countNodes(TreeNode *root){
		if(root == nullptr)
			return 0;
		int left = countHeight(root->left), right = countHeight(root->right);
		if(left == right)
			return left + 1 + countNodes(root->right);
		else
			return right + 1 + countNodes(root->left);
	}
	
	int countHeight(TreeNode *root){
		if(root == nullptr)
			return 0;
		else
			return 2 * countHeight(root->left) + 1;
	}
};