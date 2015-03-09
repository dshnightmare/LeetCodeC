#include <string.h>
using namespace std;

class ExcelSheetColumnTitle{
public:
	string convertToTitle(int n){
		string s;
		while(n > 0){
			n--;
			s.insert(s.begin(), n % 26 + 'A');
			n /= 26;
		}
		return s;
	}
};
int main(){
	ExcelSheetColumnTitle test;
	cout << test.convertToTitle(26) << endl;
	return 0;
}