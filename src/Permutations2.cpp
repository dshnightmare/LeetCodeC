#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > permuteUnique(vector<int> &num){
		sort(num.begin(), num.end());
		vector<vector<int> > result;
		vector<int> cur;
		bool *flag = new bool[num.size()];
		memset(flag, 0, sizeof(bool) * num.size());
		generate(num, cur, flag, result);
		delete[] flag;
		return result;
	}
	
	void generate(vector<int> &num, vector<int> &cur, bool flag[], vector<vector<int> > &result){
		if(cur.size() == num.size())
			result.push_back(cur);
		
		for(int i = 0; i < num.size(); i++){
			if(i > 0 && num[i] == num[i - 1] && flag[i - 1] == false)
				continue;
			if(flag[i] == false){
				flag[i] = true;
				cur.push_back(num[i]);
				generate(num, cur, flag, result);
				flag[i] = false;
				cur.pop_back();
			}
		}
	}
};

int main(){
	return 0;
}