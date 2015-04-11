#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		vector<Interval>::iterator it = intervals.begin();
		while(it != intervals.end()){
			if(newInterval.end < it->start){
				result.push_back(newInterval);
				result.insert(result.end(), it, intervals.end());
				return result;
			}
			else if(newInterval.start > it->end){
				result.push_back(*it);
			}
			else{
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
			}
			it++;
		}
		result.push_back(newInterval);
		return result;
	}
};

int main(){
	return 0;
}