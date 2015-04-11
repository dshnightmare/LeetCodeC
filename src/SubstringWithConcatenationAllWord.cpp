#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
	vector<int> findSubstring(string S, vector<string> &L){
		unordered_map<string, int> map, check;
		vector<int> result;
		if(L.size() == 0)
			return result;
		int left, right, length = S.size(), count, n = L[0].size();
		for(auto i = L.begin(); i < L.end(); i++){
			if(map.find(*i) != map.end())
				map[*i]++;
			else
				map.insert(pair<string, int>(*i, 1));
		}
		for(int i = 0; i < n; i++){
			check.clear();
			count = 0;
			for(left = right = i; right + n <= length; right += n){
				string cur = S.substr(right, n);
				if(map.find(cur) != map.end()){
					count++;
					if(check.find(cur) == check.end())
						check.insert(pair<string, int>(cur, 1));
					else{
						if(check[cur] < map[cur])
							check[cur]++;
						else{
							while(S.substr(left, n) != cur){
								count--;
								check[S.substr(left, n)]--;
								if(check[S.substr(left, n)] == 0)
									check.erase(S.substr(left, n));
								left += n;
							}
							count--;
							left += n;
						}
					}
					if(count == L.size())
						result.push_back(left);
				}
				else{
					check.clear();
					count = 0;
					left = right + n;
				}
			}
			
		}
		return result;
	}
};

int main(){
	string s[] = {"fooo","barr","wing","ding","wing"};
	vector<string> L(s, s + 5);
	Solution test;
	vector<int> result = test.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", L);
	for(auto i = result.begin(); i < result.end(); i++)
		cout << *i << endl;
	return 0;
}