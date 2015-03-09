#include <vector>
using namespace std;

class MajorityElement{
public:
	int majorityElement(vector<int> &num){
		int size = num.size();
		if(size == 0)
			return 0;
		int count = 1, cur = num[0];
		for(int i = 1; i < size; i++){
			if(num[i] == cur)
				count++;
			else{
				count--;
				if(count < 0){
					cur = num[i];
					count = 1;
				}
			}
		}
		return cur;
	}
};
int main(){
	return 0;
}