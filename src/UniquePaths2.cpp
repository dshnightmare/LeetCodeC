#include <vector>
using namespace std;

class Solution{
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
		int dp[100];
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			if(obstacleGrid[0][i - 1] == 1)
				dp[i] = 0;
			else
				dp[i] = dp[i - 1];
		}
		dp[0] = 0;
		for(int i = 1; i < m; i++){
			for(int j = 1; j <= n; j++){
				if(obstacleGrid[i][j - 1] == 1)
					dp[j] = 0;
				else
					dp[j] += dp[j - 1];
			}
		}
		return dp[n];
	}
};

int main(){
	return 0;
}