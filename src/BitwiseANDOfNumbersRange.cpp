#include <iostream>
using namespace std;

class Solution{
public:
	int rangeBitwiseAnd(int m, int n){
		int count = 30, result = 0;
		while(count >= 0){
			if((m & (1 << count)) == (n &(1 << count)))
				result |= (m & (1 << count));
			else
				break;
			count--;
			cout << result << endl;
		}	
		return result;
	}
};

int main(){
	Solution s;
	cout << s.rangeBitwiseAnd(20000, 2147483647) << endl;
}