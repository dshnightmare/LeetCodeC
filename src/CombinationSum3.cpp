#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        bool check[10] = {true, true, true, true, true, true, true, true, true, true};
		vector<vector<int>> result;
		vector<int> can;
		dfs(can, 1, 0, k, n, check, result);
		return result;
    }
	
	void dfs(vector<int> &can, int pos, int sum, int k, int n, bool check[], vector<vector<int>> &result){
		if(can.size() == k && sum == n){
			result.push_back(can);
			return;
		}
		
		if(sum > n)
			return;
		
		for(int i = pos; i < 10; i++){
			if(check[i]){
				check[i] = false;
				can.push_back(i);
				dfs(can, i + 1, sum + i, k, n, check, result);
				check[i] = true;
				can.pop_back();
			}
		}
	}
};

int main(){
	Solution s;
	s.combinationSum3(2, 6);
}