#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};



class Solution{
public:
	vector<Interval> merge(vector<Interval> &intervals){
		vector<Interval> result;
		if(intervals.size() == 0)
			return result;
		sort(intervals.begin(), intervals.end(), customLess);
		Interval *cur = new Interval(intervals[0].start, intervals[0].end);
		for(int i = 1; i < intervals.size(); i++){
			if(intervals[i].start <= cur->end){
				cur->start = min(cur->start, intervals[i].start);
				cur->end = max(cur->end, intervals[i].end);
			}
			else{
				result.push_back(*cur);
				cur = new Interval(intervals[i].start, intervals[i].end);
			}
		}
		result.push_back(*cur);
		return result;
	}
private:
	struct COMP{
		bool operator()(const Interval &ele1, const Interval &ele2)
		{   
			if(ele1.start == ele2.start)
				return ele1.end < ele2.end;
			return ele1.start < ele2.start;
		}   
	} customLess;
};

int main(){
	return 0;
}