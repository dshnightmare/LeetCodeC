using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	bool isValidBST(TreeNode *root){
		pair<int, int> tmp;
		if(root == nullptr)
			return true;
		else
			return help(root, tmp);
	}
	
	//pair<int, int> max, min
	bool help(TreeNode *root, pair<int, int> &up){
		pair<int, int> left(root->val, root->val), right(root->val, root->val);
		if(root->left != nullptr){
			if(!help(root->left, left) || root->val <= left.first)
				return false;
		}
		if(root->right != nullptr){
			if(!help(root->right, right) || root->val >= right.second)
				return false;
		}
		up.first = right.first;
		up.second = left.second;
		return true;
	}
};