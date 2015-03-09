#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		unordered_map<int, int> mapping;
		vector<int> result;
		for(int i = 0; i < numbers.size(); i++)
			mapping[numbers[i]] = i;
		for(int i = 0; i < numbers.size(); i++){
			int gap = target - numbers[i];
			if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;
	}
};

int main(){
	TwoSum test;
	vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	test.twoSum(numbers, 6);
	return 0;
}