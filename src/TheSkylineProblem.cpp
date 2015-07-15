#include <vector>
using namespace std;

class Solution{
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings){
		vector<pair<int, int>> ret;
		if(buildings.size() == 0)
			return ret;
		vector<vector<int>> result = help(buildings, 0, buildings.size() - 1);
		ret.emplace_back(make_pair(result[0][0], result[0][2]));
		for(int i = 1; i < result.size(); i++){
			if(result[i][0] != result[i - 1][1])
				ret.emplace_back(make_pair(result[i - 1][1], 0));
			ret.emplace_back(make_pair(result[i][0], result[i][2]));
		}
		ret.emplace_back(make_pair(result.back()[1], 0));
		return ret;
	}
	
	vector<vector<int>> help(vector<vector<int>>& buildings, int begin, int end){
		vector<vector<int>> result;
		if(begin == end){
			result.push_back(buildings[begin]);
		}
		else{
			int mid = (begin + end) / 2;
			vector<vector<int>> r1 = help(buildings, begin, mid), r2 = help(buildings, mid + 1, end);
			int i = 0, j = 0;
			while(i < r1.size() && j < r2.size()){
				if(r1[i][1] < r2[j][0]){
					result.emplace_back(r1[i++]);
				}
				else if(r2[j][1] < r1[i][0]){
					result.emplace_back(r2[j++]);
				}
				else if(r1[i][0] <= r2[j][0]){
					merge_intersect_skylines(result, r1[i], i, r2[j], j);
				}
				else{
					merge_intersect_skylines(result, r2[j], j, r1[i], i);
				}
			}
			copy(r1.cbegin() + i, r1.cend(), back_inserter(result));
			copy(r2.cbegin() + j, r2.cend(), back_inserter(result));
		}
		return result;
	}
	
	void merge_intersect_skylines(vector<vector<int>> &result, 
									vector<int> &a, int &i, 
									vector<int> &b, int &j){
		if(a[1] <= b[1]){
			if(a[2] > b[2]){
				if(a[1] != b[1]){
					result.emplace_back(a);
					i++;
					b[0] = a[1];
				}
				else{
					j++;
				}
			}
			else if(a[2] == b[2]){
				b[0] = a[0];
				i++;
			}
			else{
				if(a[0] != b[0]){
					result.emplace_back(vector<int>{a[0], b[0], a[2]});
				}
				i++;
			}
		}
		else{
			if(a[2] >= b[2]){
				j++;
			}
			else{
				if(a[0] != b[0]){
					result.emplace_back(vector<int>{a[0], b[0], a[2]});
				}
				a[0] = b[1];
				result.emplace_back(b);
				j++;
			}
		}
	}
};

int main(){
	Solution s;
	vector<vector<int>> buildings;
	buildings.emplace_back(vector<int>({0, 2, 3}));
	buildings.emplace_back(vector<int>({2, 5, 3}));
	s.getSkyline(buildings);
}