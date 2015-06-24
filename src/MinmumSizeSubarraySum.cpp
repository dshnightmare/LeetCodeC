#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	int minSubArrayLen(int s, vector<int> &nums) {
		if(nums.size() == 0)
			return 0;
		int p = 0, q = 1, sum = nums[0], result = nums.size() + 1;
		while(q < nums.size()){
			if(sum < s){
				sum += nums[q++];
			}
			else{
				result = min(result, q - p);
				sum -= nums[p++];
			}
		}
		if(sum >= s)
			result = min(result, q - p);
		while(p < q && sum - nums[p] >= s){
			sum -= nums[p++];
			result = min(result, q - p);
		}
		return result == nums.size() + 1 ? 0 : result;
	}
};

int main(){
	Solution s;
	vector<int> a = {1, 1};
	cout << s.minSubArrayLen(3, a) << endl;
}