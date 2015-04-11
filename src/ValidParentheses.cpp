#include <string>
#include <stack>
using namespace std;


class Solution{
public:
	bool isValid(string s){
		stack<char> ss;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ')'){
				if(!ss.empty() && ss.top() == '(')
					ss.pop();
				else
					return false;
			}
			else if(s[i] == ']'){
				if(!ss.empty() && ss.top() == '[')
					ss.pop();
				else
					return false;
			}
			else if(s[i] == '}'){
				if(!ss.empty() && ss.top() == '{')
					ss.pop();
				else
					return false;
			}
			else
				ss.push(s[i]);
		}
		if(ss.empty())
			return true;
		else
			return false;
	}
};

int main(){
	return 0;
}