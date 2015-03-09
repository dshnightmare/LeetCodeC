#include <string>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int length = s.length();
		int begin = 0, end = 0, max = 0;
		bool flag[128] = {false};
		while(end < length){
			// has repeat
			if(flag[s[end]]){
				while(s[begin] != s[end]){
					flag[s[begin]] = false;
					begin++;
				}
				begin++;
			}
			else{
				flag[s[end]] = true;
				if(end - begin + 1 > max)
					max = end - begin + 1;
			}
			end++;
		}
		return max;
	}
};

int main(){
	Solution test;
	cout << test.lengthOfLongestSubstring("abcabcbb") << endl;
	return 0;
}