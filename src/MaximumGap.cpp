#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
	int maximumGap(vector<int> &nums){
		if(nums.size() < 2)
			return 0;
		
		int min_num = accumulate(nums.begin(), nums.end(), INT_MAX, [](const int &a, const int &b){
			return min(a, b);
		});
		int max_num = accumulate(nums.begin(), nums.end(), 0, [](const int &a, const int &b){
			return max(a, b);
		});
		//cout << min_num << " " << max_num << endl;
		int bucket_size = max(1ul, (max_num - min_num) / (nums.size() - 1));
		int bucket_num = (max_num - min_num) / bucket_size + 1;
		vector<int> bucket_min(bucket_num, INT_MAX), bucket_max(bucket_num, 0);
		vector<int> bucket_count(bucket_num, 0);
		for(auto i : nums){
			int index = (i - min_num) / bucket_size;
			bucket_count[index]++;
			bucket_min[index] = min(bucket_min[index], i);
			bucket_max[index] = max(bucket_max[index], i);
		}
		int last_max = min_num, ret = bucket_size;;
		for(int i = 0; i < bucket_num; i++){
			if(bucket_count[i] > 0){
				ret = max(ret, bucket_min[i] - last_max);
				last_max = bucket_max[i];
			}
		}
		return ret;
	}
};


int main(){
	vector<int> nums = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};
	Solution s;
	cout << s.maximumGap(nums) << endl;
}