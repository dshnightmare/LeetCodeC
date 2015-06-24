#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
		return help(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	
	TreeNode *help(vector<int> &postorder, int pb, int pe, vector<int> &inorder, int ib, int ie){
		if(pb > pe)
			return nullptr;
		TreeNode *root = new TreeNode(postorder[pe]);
		int i;
		for(i = ib; i <= ie; i++){
			if(inorder[i] == postorder[pe])
				break;
		}
		i -= ib;
		root->left = help(postorder, pb, pb + i - 1, inorder, ib, ib + i - 1);
		root->right = help(postorder, pb + i, pe - 1, inorder, ib + i + 1, ie);
		return root;
	}
};

