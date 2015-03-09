#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int atoi(string str){
		int length = str.length(), sign = 1;
		long result = 0;
		int i = 0;
		while(i < length && str[i] == ' ')
			i++;
		if(str[i] == '-'){
			sign = -1;
			i++;
		}
		else if(str[i] == '+')
			i++;
		while(i < length && str[i] >= '0' && str[i] <= '9'){
			result *= 10;
			result += (sign * (str[i] - '0'));
			i++;
			if(result > INT_MAX){
				result = INT_MAX;
				break;
			}
			if(result < INT_MIN){
				result = INT_MIN;
				break;
			}
		}
		return (int)result;
	}
};

int main(){
	Solution test;
	cout << test.atoi("   101dddd");
}