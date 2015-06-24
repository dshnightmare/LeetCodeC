#include <vector>
using namespace std;

class Solution{
public:
	int rob(vector<int> &nums){
		if(nums.size() == 0)
			return 0;
		int pre = nums[0], premax = 0, result = nums[0];
		for(int i = 1; i < nums.size(); i++){
			int cur = premax + nums[i];
			result = max(result, cur);
			premax = max(premax, pre);
			pre = cur;
		}
		return result;
	}
};