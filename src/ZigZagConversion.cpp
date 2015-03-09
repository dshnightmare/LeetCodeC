#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string convert(string s, int nRows){
		if(nRows <= 1)
			return s;
		int length = s.length();
		string ret = "";
		for(int i = 0; i < nRows; i++){
			for(int j = i; j < length; j += 2 * (nRows - 1)){
				ret += s[j];
				if(i == 0 || i == nRows - 1)
					continue;
				int tmp = j + 2 * (nRows - 1 - i);
				if(tmp < length)
					ret += s[tmp];
			}
		}
		return ret;
	}
};

int main(){
	Solution test;
	cout << test.convert("PAYPALISHIRING", 3) << endl;
}