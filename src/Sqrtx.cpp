#include <iostream>
using namespace std;

class Solution{
public:
	int sqrt(int x){
		if(x == 0)
			return 0;
		else if(x == 1)
			return 1;
		return bsearch(1, x, x);
	}
	
	int bsearch(int left, int right, int x){
		if(left >= right)
			return left;
		int mid = right - (right - left) / 2;
		//cout << mid << endl;
		if(x / mid == mid)
			return mid;
		else if(x / mid < mid)
			return bsearch(left, mid - 1, x);
		else
			return bsearch(mid, right, x);
	}
};

int main(){
	Solution s;
	cout << s.sqrt(6) << endl;
	return 0;
}