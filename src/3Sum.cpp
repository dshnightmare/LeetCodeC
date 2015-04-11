#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > threeSum(vector<int> &num){
		vector<vector<int> > result;
		int size = num.size(), target = 0;
		if(size < 3)
			return result;
		sort(num.begin(), num.end());
		auto last = num.end(); 
		for(auto a = num.begin(); a < prev(last, 2); a++){
			if(a != num.begin() && *a == *prev(a))
				continue;
			auto b = next(a), c = prev(last);
			int* lastb = nullptr;
			while(b < c){
				if(*a + *b + *c < target)
					b++;
				else if(*a + *b + *c > target)
					c--;
				else{
					if(lastb == nullptr || *b != *lastb){
						result.push_back({*a, *b, *c});
						if(lastb == nullptr)
							lastb = new int(*b);
						else
							*lastb = *b;
					}
					b++;
					c--;
				}
			}
		}
		return result;
	}
};

int main(){
	return 0;
}