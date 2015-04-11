#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
	string minWindow(string S, string T){
		unordered_map<char, int> check, cur, count;
		for(auto i : T){
			check[i]++;
			cur[i]++;
		}
		int length = S.size(), left = 0, right = 0, minL = length + 1, begin = 0;
		for(; right < length; right++){
			if(check.find(S[right]) != check.end()){
				count[S[right]]++;
				if(cur.find(S[right]) != cur.end()){
					//cout << right << endl;
					cur[S[right]]--;
					if(cur[S[right]] == 0)
						cur.erase(S[right]);
				}
				//cout << S[right] << " " << cur.size() << " " << right - left + 1 << endl;
				if(cur.size() == 0){
					while(check.find(S[left]) == check.end() || count[S[left]] > check[S[left]]){
						count[S[left]]--;
						left++;
					}
					if(right - left + 1 < minL){
						minL = right - left + 1;
						begin = left;
					}
				}
			}
		}
		if(minL == length + 1)
			return "";
		else
			return S.substr(begin, minL);
	}
};

int main(){
	Solution s;
	cout << s.minWindow("caae", "cae") << endl;
	return 0;
}