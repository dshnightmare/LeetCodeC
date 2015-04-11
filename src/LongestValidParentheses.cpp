#include <string>
using namespace std;

class Solution{
public:
	int longestValidParentheses(string s){
		int length = s.size();
		if(length == 0)
			return 0;
		int *num = new int[length], max = 0;
		num[length - 1] = 0;
		for(int i = length - 2; i >= 0; i--){
			if(s[i] == '('){
				int index = i + 1 + num[i + 1];
				if(s[index] == ')')
				{
					num[i] = num[i + 1] + 2;
					if(index + 1 < length)
						num[i] += num[index + 1];
					if(num[i] > max)
						max = num[i];
				}
				else
					num[i] = 0;
			}
			else
				num[i] = 0;
		}
		return max;
	}
};

int main(){
	Solution test;
	cout << test.longestValidParentheses("(()") << endl;
	return 0;
}