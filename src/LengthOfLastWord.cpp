using namespace std;

class Solution{
public:
	int lengthOfLastWord(const char *s){
		int count = 0;
		int flag = true;
		for(int i = 0; s[i] != '\0'; i++){
			if(s[i] == ' ')
				flag = true;
			else{
				if(flag){
					count = 1;
					flag = false;
				}
				else
					count++;
			}
		}
		return count;
	}
}