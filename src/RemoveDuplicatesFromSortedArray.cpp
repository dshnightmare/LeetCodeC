#include <vector>
using namespace std;

class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		int unique = 0, all = 0;
		while(all < nums.size()){
			if(all == 0 || nums[all] != nums[all - 1]){
				nums[unique] = nums[all];
				unique++;
			}
			all++;
		}
		return unique;
	}
};