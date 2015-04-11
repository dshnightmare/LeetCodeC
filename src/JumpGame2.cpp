#include <iostream>
using namespace std;

class Solution{
	int jump(int A[], int n){
		if(n <= 1)
			return 0;
		int begin = 0, num = 0, i = 1;
		while(begin + A[begin] < n - 1){
			int range = begin + A[begin], max = range;
			for(; i <= range; i++){
				if(i + A[i] > max){
					max = i + A[i];
					begin = i;
				}
			}
			if(max == range){
				return -1;
			}
			num++;
		}
		num++;
		return num;
	}
};

int main(){
	return 0;
}