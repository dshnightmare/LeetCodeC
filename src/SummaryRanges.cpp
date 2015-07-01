#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
	vector<string> summaryRanges(vector<int> &nums){
		vector<string> result;
		nums.push_back(INT_MAX);
		int rb = nums[0];
		stringstream ss;
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] - nums[i - 1] != 1){
				string tmp;
				ss.clear();
				ss << rb;
				ss >> tmp;
				if(nums[i - 1] != rb){
					string tt;
					ss.clear();
					ss << nums[i - 1];
					ss >> tt;
					tmp = tmp + "->" + tt;
				}
				result.push_back(tmp);
				rb = nums[i];
			}
		}
		return result;
	}
};