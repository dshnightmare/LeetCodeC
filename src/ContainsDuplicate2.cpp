#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> check;
		for(int i = 0; i < nums.size(); i++){
			if(check.find(nums[i]) != check.end())
				return true;
			check.insert(nums[i]);
			if(check.size() > k)
				check.erase(nums[i - k]);
		}
		return false;
    }
};