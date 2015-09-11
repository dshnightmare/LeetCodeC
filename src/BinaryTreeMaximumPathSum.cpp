#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
		dp(root, ret);
		return ret;
    }
	
	int dp(TreeNode *root, int& result){
		if(root == nullptr)
			return 0;
		int leftmax = max(0, dp(root->left, result));
		int rightmax = max(0, dp(root->right, result));
		result = max(result, leftmax + rightmax + root->val);
		return max(leftmax, rightmax) + root->val;
	}
};