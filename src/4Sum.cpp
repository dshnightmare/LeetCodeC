#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > fourSum(vector<int> &num, int target){
		vector<vector<int> > result;
		if(num.size() < 4)
			return result;
		sort(num.begin(), num.end());
		auto last = num.end();
		for(auto a = num.begin(); a < prev(last, 3); a++){
			if(a != num.begin() && *a == *(a - 1))
				continue;
			for(auto b = next(a); b < prev(last, 2); b++){
				if(b != next(a) && *b == *(b - 1))
					continue;
				auto c = next(b), d = prev(last);
				while(c < d){
					int sum = *a + *b + *c + *d;
					if(sum > target){
						d--;
					}
					else if(sum < target){
						c++;
					}
					else{
						result.push_back({*a, *b, *c, *d});
						c++;
						d--;
						while(*c == *(c - 1) && c < d)
							c++;
					}
				}
			}
		}
		return result;
	}
};