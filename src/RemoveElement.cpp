#include <vector>
using namespace std;

class Solution{
public:
	int removeElement(vector<int>& nums, int val){
		int leave = 0, all = 0;
		while(all < nums.size()){
			if(nums[all] != val)
				nums[leave++] = nums[all];
			all++;
		}
		return leave;
	}
};