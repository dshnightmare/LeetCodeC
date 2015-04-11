#include <iostream>
using namespace std;

class Solution{
public:
	double pow(double x, int n){
		return powl(x, n);
	}
	
	double powl(double x, long n){
		if(n == 0)
			return 1;
		if(n < 0)
			return 1.0 / powl(x, -n);
		double v = powl(x, n / 2);
		if((n & 1) == 0)
			return v * v;
		else
			return v * v * x;
	}
};

int main(){
	return 0;
}