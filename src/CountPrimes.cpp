#include <iostream>
using namespace std;

class Solution{
public:
	int countPrimes(int n){
		if(n == 0)
			return 0;
		bool check[n];
		for(int i = 0; i < n; i++)
			check[i] = true;
		for(int i = 2; i * i < n; i++){
			if(check[i]){
				for(int j = i * i; j < n; j += i)
					check[j] = false;
			}
		}
		int count = 0;
		for(int i = 2; i < n; i++)
			if(check[i])
				count++;
		return count;
	}
};