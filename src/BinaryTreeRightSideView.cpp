#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	vector<int> rightSideView(TreeNode* root){
		vector<int> result;
		if(root == nullptr)
			return result;
		queue<pair<int, TreeNode*> > que;
		que.push(make_pair(0, root));
		while(!que.empty()){
			pair<int, TreeNode*> cur = que.front();
			que.pop();
			if(cur.first == result.size())
				result.push_back(cur.second->val);
			if(cur.second->right != nullptr)
				que.push(make_pair(cur.first + 1, cur.second->right));
			if(cur.second->left != nullptr)
				que.push(make_pair(cur.first + 1, cur.second->left));
		}
		return result;
	}
};