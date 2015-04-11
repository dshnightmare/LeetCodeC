#include <iostream>
using namespace std;

class Solution{
public:
	int trap(int A[], int n){
		if(n == 0)
			return 0;
		int *t = new int[n], maxL = A[0], maxR = A[n - 1], sum = 0;
		t[0] = t[n - 1] = 0;
		for(int i = 1; i < n - 1; i++){
			t[i] = maxL;
			if(A[i] > maxL)
				maxL = A[i];
		}
		for(int i = n - 2; i > 0; i--){
			t[i] = min(t[i], maxR);
			if(A[i] > maxR)
				maxR = A[i];
		}
		for(int i = 0; i < n; i++){
			if(t[i] > A[i])
				sum += (t[i] - A[i]);
		}
		return sum;
	}
};

int main(){
	return 0;
}