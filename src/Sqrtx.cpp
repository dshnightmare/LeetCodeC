#include <iostream>
using namespace std;

class Solution{
public:
	int sqrt(int x){
		if(x == 0)
			return 0;
		int ret = (1 + x) / 2;
		while(1){
			int tmp = (ret + x / ret) / 2;
			if(tmp >= ret)
				break;
			else
				ret = tmp;
		}
		return ret;
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
	cout << s.sqrt(5) << endl;
	return 0;
}