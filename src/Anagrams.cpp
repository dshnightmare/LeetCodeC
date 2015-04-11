#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
	vector<string> anagrams(vector<string> &strs){
		unordered_map<string, int> map;
		vector<string> result;
		for(int i = 0; i < strs.size(); i++){
			string key = strs[i];
			sort(key.begin(), key.end());
			if(map.find(key) != map.end()){
				if(map[key] >= 0){
					result.push_back(strs[map[key]]);
					map[key] = -1;
				}
				result.push_back(strs[i]);
			}
			else
				map[key] = i;
		}
		return result;
	}
};

int main(){
	return 0;
}