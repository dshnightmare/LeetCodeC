#include <vector>
using namespace std;

class PlusOne {
public:
	vector<int> plusOne(vector<int> &digits) {
		int length = digits.size();
		vector<int> result(length);
		int carry = 1;
		for(int i = length - 1; i >= 0; i--){
			result[i] = digits[i] + carry;
			if(result[i] >= 10){
				result[i] -= 10;
				carry = 1;
			}
			else{
				carry = 0;
				break;
			}
		}
		if(carry == 1)
			result.insert(result.begin(), 1);
		return result;
	}
};

int main(){
	return 0;
}