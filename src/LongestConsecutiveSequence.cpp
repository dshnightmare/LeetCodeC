#include <unordered_set>
#include <vector>
using namespace std;

class Solution{
public:
	int longestConsecutive(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		unordered_set<int> all;
		int ret = 0;
		for(auto i : nums)
			all.insert(i);
		while(!all.empty()){
			int cur = *all.begin();
			all.erase(cur);
			int length = 1;
			for(int i = cur + 1; all.find(i) != all.end(); i++){
				length++;
				all.erase(i);
			}
			for(int i = cur - 1; all.find(i) != all.end(); i++){
				length++;
				all.erase(i);
			}
			ret = max(ret, length);
		}
		return ret;
	}
};