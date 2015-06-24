#include<iostream>
using namespace std;

class Solution{
public:
	Solution(){
		precompute();
	}
	
	uint32_t _reverseBits(uint32_t n){
		uint32_t result = 0;
		for(int i = 0; i < 32; i++){
			result <<= 1;
			result |= (n & 1);
			n >>= 1;
		}
		return result;
	}
	
	void precompute(){
		for(uint32_t i = 0; i < 1 << 8; i++)
			m[i] = _reverseBits(i) >> 24;
	}
	
	uint32_t reverseBits(uint32_t n){
		return m[(n >> 24) & 0xff] | m[(n >> 16) & 0xff] << 8 | m[(n >> 8) & 0xff] << 16 | m[n & 0xff] << 24; 
	}
	
	uint32_t m[1 << 8];
};

int main(){
	Solution s;
	cout << s.reverseBits(43261596) << endl;
}