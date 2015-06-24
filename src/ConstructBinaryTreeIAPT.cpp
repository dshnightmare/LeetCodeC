#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
		return help(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	
	TreeNode *help(vector<int> &preorder, int pb, int pe, vector<int> &inorder, int ib, int ie){
		if(pb > pe)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[pb]);
		int i;
		for(i = ib; i <= ie; i++){
			if(inorder[i] == preorder[pb])
				break;
		}
		i -= ib;
		root->left = help(preorder, pb + 1, pb + i, inorder, ib, ib + i - 1);
		root->right = help(preorder, pb + i + 1, pe, inorder, ib + i + 1, ie);
		return root;
	}
};

