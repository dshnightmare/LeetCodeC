#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
	int candy(vector<int>& ratings){
		vector<int> count(ratings.size(), 1);
		for(int i = 1; i < ratings.size(); i++){
			if(ratings[i] > ratings[i - 1])
				count[i] = count[i - 1] + 1;
		}
		
		for(int i = ratings.size() - 2; i >= 0; i--){
			if(ratings[i] > ratings[i + 1])
				count[i] = max(count[i], count[i + 1] + 1);
		}
		
		return accumulate(count.begin(), count.end(), 0, [](int a, int b){
			return a + b;
		});
	}
};