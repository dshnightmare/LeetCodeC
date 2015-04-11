struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	int numTrees(int n){
		const int N = n;
		int dp[N + 1];
		dp[0] = 1;
		for(int i = 1; i <= N; i++){
			dp[i] = 0;
			for(int j = 0; j <= i - 1; j++)
				dp[i] += dp[j] * dp[i - 1 - j];
		}
		return dp[N];
	}
};