#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
		for(auto i : nums){
			if(check.find(i) != check.end())
				return true;
			check.insert(i);
		}
		return false;
    }
};