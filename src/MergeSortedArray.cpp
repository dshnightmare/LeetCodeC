class Solution{
public:
	void merge(int A[], int m, int B[], int n){
		int last = m + n - 1, i = m - 1, j = n - 1;
		while(last >= 0 && i >= 0 && j >= 0){
			if(A[i] < B[j])
				A[last--] = B[j--];
			else
				A[last--] = A[i--];
		}
		while(j >= 0){
			A[last--] = B[j--];
		}
	}
};
