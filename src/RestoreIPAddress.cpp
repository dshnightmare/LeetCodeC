#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution{
public:
	vector<string> restoreIpAddresses(string s){
		stringstream stream;
		return generate(4, s, stream);
	}
	
	vector<string> generate(int n, string s, stringstream &stream){
		vector<string> result;
		if(s.length() < n || s.length() > 3 * n)
			return result;
		int num;
		if(n == 1){
			string s1;
			stream.clear();
			stream << s;
			stream >> num;
			stream.clear();
			stream << num;
			stream >> s1;
			if(num < 256 && s1 == s)
				result.push_back(s);
			return result;
		}
		for(int i = 1; i <= min(3, (int)s.length()); i++){
			string t1, t2;
			t1 = s.substr(0, i);
			stream.clear();
			stream << t1;
			stream >> num;
			stream.clear();
			stream << num;
			stream >> t2;
			//cout << t1 << " " << num << " " << t2 << endl;
			if(num < 256 && t1 == t2){
				vector<string> last = generate(n - 1, s.substr(i), stream);
				for(auto j : last)
					result.push_back(t1 + '.' + j);
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	vector<string> v = s.restoreIpAddresses("1111");
	for(auto i : v)
		cout << i << endl;
	return 0;
}