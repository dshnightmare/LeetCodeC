#include <vector>
using namespace std;

class Solution{
public:
	int findMin(vector<int> &nums){
		return bsearch(nums, 0, nums.size() - 1);
	}
	
	int bsearch(vector<int> &nums, int left, int right){
		if(left == right)
			return nums[left];
		if(nums[left] < nums[right])
			return nums[left];
		int mid = left + (right  - left) / 2;
		if(nums[mid] > nums[left])
			return bsearch(nums, mid + 1, right);
		else if(nums[mid] < nums[right])
			return bsearch(nums, left, mid);
		else
			return bsearch(nums, left + 1, right);
	}
};