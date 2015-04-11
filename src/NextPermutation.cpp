#include <vector>
using namespace std;

class Solution{
public:
	void nextPermutation(vector<int> &num){
		const auto rfirst = num.rbegin();
		const auto rlast = num.rend();
		auto pivot = next(rfirst);
		while(pivot != rlast && *pivot >= *prev(pivot))
			pivot++;
		if(pivot == rlast){
			reverse(rfirst, rlast);
			return;
		}
		
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		swap(*change, *pivot);
		reverse(rfirst, pivot);
	}
};

int main(){
	return 0;
}