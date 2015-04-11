#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
	int maximalRectangle(vector<vector<char> > &matrix){
		if(matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int n = matrix.size(), m = matrix[0].size(), result = 0;
		vector<int> counts(m + 1, 0);
		stack<int> s;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == '0')
					counts[j] = 0;
				else
					counts[j]++;
			}
			for (int j = 0; j < counts.size(); ){
				if (s.empty() || counts[j] > counts[s.top()])
				s.push(j++);
				else {
					int tmp = s.top();
					s.pop();
					result = max(result,counts[tmp] * (s.empty() ? j : j - s.top() - 1));
				}
			}
			while(!s.empty())
				s.pop();
		}
		return result;
	}
};