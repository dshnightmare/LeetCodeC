#include <unordered_set>
using namespace std;

class Solution{
public:
	bool isHappy(int n){
		unordered_set<int> check;
		check.emplace(n);
		while((n = ss(n)) != 1){
			if(check.find(n) != check.end())
				return false;
			else
				check.emplace(n);
		}
		return true;
	}
	
	int ss(int n){
		int result = 0;
		while(n > 0){
			result += (n % 10) * (n % 10);
			n /= 10;
		}
		return result;
	}
};

int main(){
	Solution s;
	cout << s.isHappy(19) << endl;
}