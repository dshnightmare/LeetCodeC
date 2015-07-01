#include <string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string pre = "";
		for(int i = s.length(); i >= 0; i--){
			if(isPalindrome(pre + s))
				return pre + s;
			pre.push_back(s[i - 1]);
		}
    }
	
	bool isPalindrome(string s){
		int i = 0, j = s.length() - 1;
		while(i < j){
			if(s[i++] != s[j--])
				return false;
		}
		return true;
	}
};