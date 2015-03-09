#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s){
		string newstr = makeString(s);
		int right = 0, center = 0, length = newstr.length();
		int P[length];
		
		for(int i = 1; i < length - 1; i++){
			if(right > i)
				P[i] = min(right - i, P[2 * center - i]);
			else
				P[i] = 0;
			while(newstr[i + P[i] + 1] == newstr[i - P[i] - 1]){
				P[i]++;
			}
			
			if(i + P[i] > right){
				right = i + P[i];
				center = i;
			}
		}
		
		int maxLen = 0;
		center = 0;
		for(int i = 1; i < length - 1; i++){
			if(P[i] > maxLen){
				maxLen = P[i];
				center = i;
			}
		}
		return s.substr((center - 1 - maxLen) / 2, maxLen);
	}
	
	string makeString(string s){
		int n = s.length();
		if(n == 0)
			return "^$";
		
		string ret = "^";
		for(int i = 0; i < n; i++)
			ret += "#" + s.substr(i, 1);
		ret += "#$";
		return ret;
	}
};

int main(){
	return 0;
} 