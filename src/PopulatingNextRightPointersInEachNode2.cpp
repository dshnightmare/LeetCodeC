
struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
		TreeLinkNode *leftwall = root;
        while(leftwall != nullptr){
			TreeLinkNode *cur = leftwall;
			TreeLinkNode *first = nullptr;
			TreeLinkNode *pre = nullptr;
			while(cur != nullptr){
				if(cur->left != nullptr){
					if(pre != nullptr)
						pre->next = cur->left;
					else
						first = cur->left;
					pre = cur->left;
				}
				if(cur->right != nullptr){
					if(pre != nullptr)
						pre->next = cur->right;
					else
						first = cur->right;
					pre = cur->right;
				}
				cur = cur->next;
			}
        	leftwall = first;
        }
    }
};