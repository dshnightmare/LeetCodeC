#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string intToRoman(int num) {
		string result = "";
		char one[4] = {'I', 'X', 'C', 'M'};
		char five[3] = {'V', 'L', 'D'};
		int i = 0;
		while(num != 0){
			int cur = num % 10;
			if(cur == 0){
				
			}
			else if(cur <= 3)
				result = string(cur, one[i]) + result;
			else if(cur == 4)
				result = one[i] + (five[i] + result);
			else if(cur <= 8)
				result = five[i] + string(cur - 5, one[i]) + result;
			else
				result = one[i] + (one[i + 1] + result);
			i++;
			num /= 10;
		}
		return result;
	}
};

int main(){
	Solution test;
	cout << test.intToRoman(1976) << endl;
	return 0;
}