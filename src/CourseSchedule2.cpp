#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
	vector<int> findOrde(int numCourses, vector<pair<int, int> >& prerequisites) {
		vector<int> result;
		int ind[numCourses];
		for(int i = 0; i < numCourses; i++)
				    ind[i] = 0;
		vector<vector<int> > edge(numCourses);
		for(int i = 0; i < prerequisites.size(); i++){
			ind[prerequisites[i].first]++;
			edge[prerequisites[i].second].emplace_back(prerequisites[i].first);
		}
		
		queue<int> q;
		unordered_set<int> check;
		for(int i = 0; i < numCourses; i++){
			if(ind[i] == 0)
				q.emplace(i);
		}
		
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			check.insert(cur);
			result.push_back(cur);
			for(auto i : edge[cur]){
				if(check.find(i) != check.end())
					continue;
				ind[i]--;
				if(ind[i] == 0)
					q.emplace(i);
			}
		}
		
		if(numCourses != result.size())
			result.clear();
		return result;
	}
};