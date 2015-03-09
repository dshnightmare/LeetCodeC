#include <string>
using namespace std;

class ExcelSheetColumnNumber {
public:
	int titleToNumber(string s){
		int result = 0, length = s.length();
		if(length <= 0)
			return result;
		for(int i = 0; i < length; i++){
			result = result * 26 + s[i] - 'A' + 1;
		}
		return result;
	}
};

int main(){
	ExcelSheetColumnNumber test;
	cout << test.titleToNumber("AB") << endl;
}