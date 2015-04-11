#include <vector>
using namespace std;

class Solution{
public:
	int threeSumClosest(vector<int> &num, int target){
		int length = num.size(), closest, gap = INT_MAX;
		sort(num.begin(), num.end());
		auto last = num.end();
		for(auto a = num.begin(); a < prev(last, 2); a++){
			auto b = next(a), c = prev(last);
			while(b < c){
				int sum = *a + *b + *c;
				if(sum > target){
					if(sum - target < gap){
						gap = sum - target;
						closest = sum;
					}
					c--;
				}
				else if(sum < target){
					if(target - sum < gap){
						gap = target - sum;
						closest = sum;
					}
					b++;
				}
				else{
					return target;
				}
			}
		}
		return closest;
	}
};

int main(){
	return 0;
}