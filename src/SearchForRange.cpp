#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
		result.push_back(lowBound(A, 0, n - 1, target));
		result.push_back(upBound(A, 0, n - 1, target));
		return result;
	}
	
	int lowBound(int A[], int left, int right, int target){
		if(left > right)
			return -1;
		int mid = (left + right) / 2;
		if(A[mid] < target)
			return lowBound(A, mid + 1, right, target);
		else if(A[mid] > target)
			return lowBound(A, left, mid - 1, target);
		else{
			if(mid > left && A[mid - 1] == target)
				return lowBound(A, left, mid - 1, target);
			return mid;
		}
	}
	
	int upBound(int A[], int left, int right, int target){
		if(left > right)
			return -1;
		int mid = (left + right) / 2;
		if(A[mid] < target)
			return upBound(A, mid + 1, right, target);
		else if(A[mid] > target)
			return upBound(A, left, mid - 1, target);
		else{
			if(mid < right && A[mid + 1] == target)
				return upBound(A, mid + 1, right, target);
			return mid;
		}
	}
};

int main(){
	return 0;
}