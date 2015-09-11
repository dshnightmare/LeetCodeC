
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
			while(cur != nullptr){
				if(cur->left != nullptr){
					cur->left->next = cur->right;
				}
				if(cur->right != nullptr && cur->next != nullptr){
					cur->right->next = cur->next->left;
				}
				cur = cur->next;
			}
        	leftwall = leftwall->left;
        }
    }
};