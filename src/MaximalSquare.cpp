#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.size() == 0)
			return 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		int result = 0;
		for(int i = 0; i < matrix[0].size(); i++){
			dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
			result = max(result, dp[0][i]);
		}
		for(int i = 1; i < matrix.size(); i++){
			dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
			result = max(result, dp[i][0]);
			for(int j = 1; j < matrix[0].size(); j++){
				if(matrix[i][j] == '1'){
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					result = max(result, dp[i][j]);
				}
			}
		}
		return result;
    }
};