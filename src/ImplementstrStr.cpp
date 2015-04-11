#include <iostream>
using namespace std;

class Solution{
public:
	int strStr(char *haystack, char *needle){
		int num = 0;
		for(; needle[num] != '\0'; num++);
		int *next = new int[num + 1];
		getNext(needle, next);
		int result = match(haystack, needle, next);
		delete[] next;
		return result;
	}
private:
	void getNext(char *needle, int *next){
		next[0] = -1;
		for(int i = 0; needle[i] != '\0'; i++){
			int q = next[i];
			while(q >= 0 && needle[q] != needle[i])
				q = next[q];
			next[i + 1] = q + 1;
		}
	}
	
	int match(char *haystack, char *needle, int *next){
		if(needle[0] == '\0')
			return 0;
		int i = 0, j = 0;
		while(haystack[i] != '\0'){
			if(haystack[i] == needle[j]){
				i++;
				j++;
			}
			else{
				j = next[j];
				if(j == -1){
					j = 0;
					i++;
				}
			}
			if(needle[j] == '\0'){
				return i - j;
			}
		}
		return -1;
	}
};

int main(){
	return 0;
}