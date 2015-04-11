#include <string>
using namespace std;

class Solution{
public:
	bool isInterleave(string s1, string s2, string s3){
		const int N1 = s1.size(), N2 = s2.size(), N3 = s3.size();
		if(N1 + N2 != N3)
			return false;
		bool dp[N1 + 1][N2 + 1];
		dp[0][0] = true;
		for(int i = 1; i <= N1; i++)
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		for(int i = 1; i <= N2; i++)
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
		for(int i = 1; i <= N1; i++){
			for(int j = 1; j <= N2; j++){
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
					(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[N1][N2];
	}
};