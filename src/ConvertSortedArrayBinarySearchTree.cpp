#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	TreeNode *sortedArrayToBST(vector<int> &num){
		return help(num, 0, num.size() - 1);
	}
	
	TreeNode *help(vector<int> &num, int begin, int end){
		if(begin > end)
			return nullptr;
		int mid = (begin + end) / 2;
		TreeNode *root =  new TreeNode(num[mid]);
		root->left = help(num, begin, mid - 1);
		root->right = help(num, mid + 1, end);
		return root;
	}
};