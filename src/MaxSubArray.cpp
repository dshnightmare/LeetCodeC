#include <iostream>
using namespace std;

class Solution{
public:
	int maxSubArray(int A[], int n){
		int last = 0, max = INT_MIN;
		for(int i = 0; i < n; i++){
			if(last >= 0)
				last += A[i];
			else
				last = A[i];
			if(last > max)
				max = last;
		}
		return max;
	}
};

int main(){
	return 0;
}