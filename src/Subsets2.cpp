#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S){
		sort(S.begin(), S.end());
		vector<vector<int> > result;
		vector<int> cur;
		choose(0, S, cur, result);
		return result;
	}
	
	void choose(int i, vector<int> &cand, vector<int> &cur, vector<vector<int> > &result){
		if(i == cand.size()){
			result.push_back(cur);
			return;
		}
		if(cur.empty() || cand[i] != cur[cur.size() - 1])
			choose(i + 1, cand, cur, result);
		cur.push_back(cand[i]);
		choose(i + 1, cand, cur, result);
		cur.pop_back();
	}
};

int main(){
	return 0;
}