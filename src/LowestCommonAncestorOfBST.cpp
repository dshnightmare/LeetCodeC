struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		if(root == nullptr)
			return root;
		if(p->val > q->val)
			std::swap(p, q);
		if(p->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else if(q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else
			return root;
	}
};