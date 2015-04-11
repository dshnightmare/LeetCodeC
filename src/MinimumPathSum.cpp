#include <vector>
using namespace std;

class Solution{
public:
	int minPathSum(vector<vector<int> > &grid){
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n+1);
		dp[0] = 0;
		for(int i = 1; i <= n; i++){
			dp[i] = grid[0][i - 1] + dp[i - 1];
		}
		dp[0] = INT_MAX;
		for(int i = 1; i < m; i++){
			for(int j = 1; j <= n; j++){
				dp[j] = min(dp[j], dp[j - 1]) + grid[i][j - 1];
			}
		}
		return dp[n];
	}
};

int main(){
	return 0;
}