#include <string>
using namespace std;

class Solution{
public:
	int calculate(string s){
		int i = 0;
		s += "+";
		return help(s, i);
	}
	
	int help(string &s, int &i){
		int result = 0;
		int operant = 0;
		int op = 1;
		while(i < s.length()){
			char cur = s[i++];
			if(cur == ' ')
				continue;
			else if(cur == ')')
				return result + op * operant;
			else if(cur == '('){
				operant = help(s, i);
				//std::cout << operant << std::endl;
			} 
			else if(cur == '-'){
				result += op * operant;
				op = -1;
				operant = 0;
			}
			else if(cur == '+'){
				result += op * operant;
				op = 1;
				operant = 0;
			}
			else{
				operant = operant * 10 + cur - '0';
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	std::cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << std::endl;
}