#include <vector>
using namespace std;

class Solution{
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		if(n == 0){
			result.push_back(0);
			return result;
		}
		
		vector<int> last = grayCode(n - 1);
		result = last;
		for(auto i = last.rbegin(); i != last.rend(); i++)
			result.push_back(*i + (1 << (n - 1)));
		return result;
	}
};