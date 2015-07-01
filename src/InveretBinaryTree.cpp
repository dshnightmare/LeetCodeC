struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	TreeNode* invertTree(TreeNode *root){
		if(root == nullptr)
			return root;
		invertTree(root->left);
		invertTree(root->right);
		std::swap(root->left, root->right);
		return root;
	}
};