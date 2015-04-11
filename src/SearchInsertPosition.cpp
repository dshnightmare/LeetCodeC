#include <iostream>
using namespace std;

class Solution{
public:
	int searchInsert(int A[], int n, int target){
		return bsearch(A, 0, n - 1, target);
	}
	
	int bsearch(int A[], int left, int right, int target){
		if(left == right){
			if(A[left] >= target)
				return left;
			else
				return left + 1;
		}
		int mid = (left + right) / 2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] > target)
			return bsearch(A, left, mid, target);
		else
			return bsearch(A, mid + 1, right, target);
	}
};

int main(){
	return 0;
}