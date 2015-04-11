#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target){
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > result;
		vector<int> cur;
		dfs(candidates, 0, target, cur, result);
		return result;
	}
	
	void dfs(vector<int> &candidates, int start, int left, vector<int> &cur, vector<vector<int> > &result){
		if(left == 0){
			result.push_back(cur);
			return;
		}
		
		for(int i = start; i < candidates.size(); i++){
			if(i - 1 >= start && candidates[i] == candidates[i - 1])
				continue;
			if(left < candidates[i])
				return;
			cur.push_back(candidates[i]);
			dfs(candidates, i + 1, left - candidates[i], cur, result);
			cur.pop_back();
		}
	}
};

int main(){
	return 0;
}