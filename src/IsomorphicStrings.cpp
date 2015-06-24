#include <unordered_map>
using namespace std;

class Solution{
public:
	bool isIsomorphic(string s, string t){
		return convert(s) == convert(t);
	}
	
	string convert(string s){
		unordered_map<char, char> map;
		char cur = 0;
		string ret = s;
		for(int i = 0; i < s.length(); i++){
			if(map.find(s[i]) == map.end())
				map[s[i]] = cur++;
			ret[i] = map[s[i]];
		}
		return ret;
	}
};