#include <iostream>
using namespace std;

class Solution{
public:
	bool canJump(int A[], int n){
		int cur = 0, distance = A[0];
		while(cur <= distance && distance < n){
			if(A[cur] + cur > distance)
				distance = A[cur] + cur;
			cur++;
		}
		return distance >= (n - 1);
	}
}