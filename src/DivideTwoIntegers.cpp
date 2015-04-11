#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor){
		unsigned int result = 0;
		const bool sign = (dividend > 0 && divisor < 0) ||
			(dividend < 0 && divisor > 0);
		unsigned int a = dividend >= 0 ? dividend : -dividend;
		unsigned int b = divisor >= 0 ? divisor : - divisor;
		
		while(a >= b){
			unsigned int c = b;
			for(int i = 0; a >= c; ++i, c <<= 1){
				a -= c;
				result += 1 << i;
				if(c > INT_MAX)
					break;
			}
		}
		
		if(sign)
			return -result;
		else{
			if(result > INT_MAX)
				return INT_MAX;
			else
				return result;
		}
	}
};

int main(){
	Solution test;
	cout << test.divide(-2147483648, 1) << endl;
	return 0;
}