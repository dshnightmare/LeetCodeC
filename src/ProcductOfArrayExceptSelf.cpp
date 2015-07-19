#include <vector>
using namespace std;

class Solution{
public:
	vector<int> productExceptSelf(vector<int> &nums){
		vector<int> ret;
		ret.push_back(1);
		for(int i = 0; i < nums.size() - 1; i++)
			ret.push_back(ret.back() * nums[i]);
		int right = 1;
		for(int i = nums.size() - 1; i >= 0; i--){
			ret[i] *= right;
			right *= nums[i];
		}
		return ret;
	}
};