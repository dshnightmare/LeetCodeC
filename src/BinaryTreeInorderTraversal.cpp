#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	vector<int> inorderTraversal(TreeNode *root){
		vector<int> result;
		if(root == nullptr)
			return result;
		TreeNode *p = root;
		stack<TreeNode *> s;
		while(!s.empty() || p != nullptr){
			if(p != nullptr){
				s.push(p);
				p = p->left;
			}
			else{
				p = s.top();
				s.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result;
	}
};