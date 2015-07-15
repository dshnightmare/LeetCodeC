#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		l1 = p;
		l2 = q;
		vector<TreeNode*> path;
		getPath(root, path);
		if(p1.size() > p2.size())
			swap(p1, p2);
		for(int i = p1.size() - 1; i >= 0; i--)
			if(p1[i] == p2[i])
				return p1[i];
		return root;
	}
	
	void getPath(TreeNode *root, vector<TreeNode*> &path){
		if(root == nullptr)
			return;
		path.push_back(root);
		if(root == l1)
			p1 = path;
		if(root == l2)
			p2 = path;
		getPath(root->left, path);
		getPath(root->right, path);
		path.pop_back();
	}
private:
	TreeNode *l1, *l2;
	vector<TreeNode*> p1, p2;
};
