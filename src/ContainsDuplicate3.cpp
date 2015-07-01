#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> check;
		if(t < 0){
			return false;
		}
		float mod = t;
		for(int i = 0; i < nums.size(); i++){
			int tt = floor(nums[i] / mod);
			if(check.find(tt) != check.end())
				return true;
			if(check.find(tt - 1) != check.end() && labs(check[tt - 1] - nums[i]) <= t)
				return true;
			if(check.find(tt + 1) != check.end() && labs(check[tt + 1] - nums[i]) <= t)
				return true;
			check[tt] = nums[i];
			if(check.size() > k)
				check.erase(nums[i - k] / mod);
		}
		return false;
    }
};