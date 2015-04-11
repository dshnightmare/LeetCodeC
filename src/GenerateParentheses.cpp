#include <vector>
using namespace std;

class Solution{
public:
	vector<string> generateParenthesis(int n){
		vector<string> result;
		gen("", n, 0, 0, result);
		return result;
	}
	
	void gen(string cur, int n, int l, int r, vector<string> &result){
		if(l == n){
			result.push_back(cur.append(l - r, ')'));
		}
		gen(cur + '(', n, l + 1, r, result);
		if(l > r)
			gen(cur + ')', n, l, r + 1, result);
	}
};

int main(){
	return 0;
}