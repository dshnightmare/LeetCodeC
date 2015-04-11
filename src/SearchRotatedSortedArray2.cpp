#include <iostream>
using namespace std;

class Solution{
public:
	bool search(int A[], int n, int target){
		return bsearch(A, 0, n - 1, target);
	}
	
	bool bsearch(int A[], int left, int right, int target){
		if(left > right)
			return false;
		if(left == right)
			return A[left] == target ? true : false;
		int mid = (left + right) / 2;
		if(A[mid] == target)
			return true;
		else if(A[left] == A[right])
			return bsearch(A, left + 1, right, target);
		else if(A[mid] >= A[left]){
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