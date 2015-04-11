#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int maxArea(vector<int> &height){
		int begin = 0, end = height.size() - 1;
		int result = 0;
		while(begin < end){
			int area = min(height[begin], height[end]) * (end - begin);
			result = area > result ? area : result;
			if(height[begin] >= height[end])
				end--;
			else
				begin++;
		}
		return result;
	}
};

int main(){
	
}