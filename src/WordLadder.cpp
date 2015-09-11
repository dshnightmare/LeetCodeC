#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
		dict.insert(start);
		dict.insert(end);
		unordered_map<string, vector<string>> edge;
		for(auto s : dict){
			for(int i = 0; i < s.length(); i++){
				string _s = s;
				for(auto j = 'a'; j <= 'z'; j++){
					_s[i] = j;
					if(j != s[i] && dict.find(_s) != dict.end())
						edge[s].push_back(_s);
				}
			}
		}
		unordered_map<string, int> check;
		queue<pair<string, int>> q;
		check[start] = 1;
		q.push(make_pair(start, 1));
		pair<string, int> cur;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(cur.first == end){
				return cur.second;
			}
			for(auto s : edge[cur.first]){
				if(check.find(s) == check.end() || cur.second < check[s]){
					q.push(make_pair(s, cur.second + 1));
					check[s] = cur.second + 1;
				}
			}
		}
		return 0;
    }
};