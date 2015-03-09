#include <iostream>
using namespace std;


class Solution{
public:
	int reverse(int x){
		long result = 0;
		while(x != 0){
			result *= 10;
			result += x % 10;
			x = x / 10;
			if(result > INT_MAX || result < INT_MIN)
				return 0;
		}
		return (int)result;
	}
};

int main(){
	Solution test;
	cout << test.reverse(-123) << endl;
}