#include <vector>
using namespace std;

class RotateArray {
public:
	void rotate(vector<int>&nums,  int k){
		if(k <= 0)
			return;
		int n = nums.size();
		k = k % n;
		reverse(nums, 0, n - k - 1);
		reverse(nums, n -  k, n - 1);
		reverse(nums, 0, n - 1);
	}
	
	void reverse(vector<int> &nums, int begin, int end){
		while(begin < end){
			nums[begin] ^= nums[end];
			nums[end] ^= nums[begin];
			nums[begin] ^= nums[end];
			begin++;
			end--;
		}
	}
};

int main(){
	return 0;
}