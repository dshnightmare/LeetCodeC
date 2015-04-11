class Solution{
public:
	int removeDuplicates(int A[], int n){
		if(n == 0)
			return 0;
		int left = 0, count = 1;
		for(int i = 1; i < n; i++){
			if(A[i] == A[left]){
				if(count < 2){
					A[++left] = A[i];
					count++;
				}
			}
			else{
				A[++left] = A[i];
				count = 1;
			}
		}
		return left + 1;
	}
};
