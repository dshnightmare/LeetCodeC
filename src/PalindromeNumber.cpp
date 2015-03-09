#include <iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if(x < 0)
			return false;
		int d = 1;
		while(x / d >= 10)
			d *= 10;
		
		while(x > 0){
			int high = x / d, low = x % 10;
			if(high != low)
				return false;
			x = x % d / 10;
			d /= 100;
		}
		return true;
	}
};

int main(){
	return 0;
}