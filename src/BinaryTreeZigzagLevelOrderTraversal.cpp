#include <vector>
#include <stack>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root){
		vector<vector<int> > result;
		if(root == nullptr)
			return result;
		stack<TreeNode*> s;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			vector<int> cur;
			while(!q.empty()){
				TreeNode *tmp = q.front();
				q.pop();
				cur.push_back(tmp->val);
				if(result.size() % 2 == 0){
					if(tmp->left != nullptr)
						s.push(tmp->left);
					if(tmp->right != nullptr)
						s.push(tmp->right);
				}
				else{
					if(tmp->right != nullptr)
						s.push(tmp->right);
					if(tmp->left != nullptr)
						s.push(tmp->left);
				}
			}
			result.push_back(cur);
			while(!s.empty()){
				q.push(s.top());
				s.pop();
			}
		}
		return result;
	}
};