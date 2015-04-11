#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > combine(int n, int k){
		vector<vector<int> > result;
		vector<bool> vis(n + 1, false);
		vector<int> cur;
		choose(1, n, k, cur, vis, result);
		return result;
	}
	
	void choose(int begin, int end, int k, vector<int> &cur, vector<bool> &vis, vector<vector<int> > &result){
		if(k == 0){
			result.push_back(cur);
			return;
		}
		if(end - begin + 1 < k)
			return;
		for(int i = begin; i <= end; i++){
			if(vis[i])
				continue;
			vis[i] = true;
			cur.push_back(i);
			choose(i + 1, end, k - 1, cur, vis, result);
			vis[i] = false;
			cur.pop_back();
		}
	}
};