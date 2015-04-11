#include <iostream>
using namespace std;

class Solution{
public:
	int search(int A[], int n, int target){
		return bsearch(A, 0, n - 1, target);
	}
	
	int bsearch(int A[], int left, int right, int target){
		if(left > right)
			return -1;
		if(left == right)
			return A[left] == target ? left : -1;
		int mid = (left + right) / 2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] > A[left]){
			if(A[mid] > target && target >= A[left])
				return bsearch(A, left, mid - 1, target);
			else
				return bsearch(A, mid + 1, right, target);
		}
		else{
			if(A[right] >= target && target > A[mid])
				return bsearch(A, mid + 1, right, target);
			else
				return bsearch(A, left, mid - 1, target);
		}
	}
};

int main(){
	return 0;
}