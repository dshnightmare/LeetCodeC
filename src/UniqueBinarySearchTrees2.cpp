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
	vector<TreeNode *> generateTrees(int n){
		return gen(1, n);
	}
	
	vector<TreeNode *>gen(int left, int right){
		vector<TreeNode *> result;
		TreeNode *p;
		if(left > right){
			result.push_back(nullptr);
			return result;
		}
		for(int i = left; i <= right; i++){
			vector<TreeNode *> tl = gen(left, i - 1), tr = gen(i + 1, right);
			for(auto l : tl){
				for(auto r : tr){
					p = new TreeNode(i);
					p->left = l;
					p->right = r;
					result.push_back(p);
				}
			}
		}
		return result;
	}
};