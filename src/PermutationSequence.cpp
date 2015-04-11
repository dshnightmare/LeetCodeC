#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string getPermutation(int n, int k){
		k--;
		string result(n, '1');
		int s[10];
		s[0] = 1;
		for(int i = 1; i < 10; i++)
			s[i] = s[i-1] * i;
		vector<char> cand;
		for(int i = 0; i < n; i++)
			cand.push_back('1' + i);
		for(int i = 0; i < n; i++){
			result[i] = cand[k / s[n - 1 - i]];
			cand.erase(cand.begin() + k / s[n - 1 - i]);
			k = k % s[n - 1 - i];
		}
		return result;
	}
};

int main(){
	Solution s;
	cout << s.getPermutation(3, 6) << endl;
	return 0;
}