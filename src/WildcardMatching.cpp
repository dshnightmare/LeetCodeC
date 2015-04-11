#include <iostream>
using namespace std;

class Solution{
public:
	bool isMatch(const char *s, const char *p){
		const char *star = nullptr;
		const char *ss = s;
		while(*s != '\0'){
			if(*p == '?' || (*p == *s)){
				s++;
				p++;
				continue;
			}
			
			if(*p == '*'){
				star = p++;
				ss = s;
				continue;
			}
			
			if(star != nullptr){
				p = star + 1;
				s = ++ss;
				continue;
			}
			
			return false;
		}
		while(*p == '*')
			p++;
		return *p == '\0';
	}
};

int main(){
	return 0;
}