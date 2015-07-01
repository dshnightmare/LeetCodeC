#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> majorityElement(vector<int> &nums){
		unordered_map<int, int> cand;
		vector<int> result;
		for(auto i : nums){
			cand[i]++;
			if(cand.size() > 2){
				auto it = cand.begin();
				while(it != cand.end()){
					if(--(it->second) == 0)
						cand.erase(it++);
					else
						it++;
				}
			}
		}
		
		for(auto &i : cand){
			i.second = 0;
		}
		//check;
		for(auto i : nums){
			if(cand.find(i) != cand.end())
				cand[i]++;
		}
		for(auto i : cand){
			if(i.second > (nums.size() / 3)){
				result.push_back(i.first);
			}
				
		}
		return result;
	}
};

int main(){
	vector<int> a = {1, 2, 3, 4};
	Solution s;
	cout << s.majorityElement(a).size() << endl;
}