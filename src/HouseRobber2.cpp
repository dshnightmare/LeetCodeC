#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		if(nums.size() == 2)
			return max(nums[0], nums[1]);
		//分两种情况，选了第一个和不选第一个
		int item = nums[0];
		nums.erase(nums.begin());
		int result = rob_help(nums);
		nums.erase(nums.begin());
		nums.pop_back();
		result = max(result, item + rob_help(nums));
		return result;
    }
	
	int rob_help(vector<int> &nums){
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