#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	vector<vector<int> > levelOrder(TreeNode *root){
		vector<vector<int> > result;
		if(root == nullptr)
			return result;
		queue<pair<TreeNode*, int> > s;
		pair<TreeNode*, int> cur;
		s.push(make_pair(root, 0));
		while(!s.empty()){
			cur = s.front();
			s.pop();
			if(result.size() == cur.second)
				result.resize(cur.second + 1);
			result[cur.second].push_back(cur.first->val);
			if(cur.first->left != nullptr)
				s.push(make_pair(cur.first->left, cur.second + 1));
			if(cur.first->right != nullptr)
				s.push(make_pair(cur.first->right, cur.second + 1));
		}
		return result;
	}
};

