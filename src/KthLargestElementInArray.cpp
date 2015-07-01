#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		return select(0, nums.size() - 1, k, nums);
    } 
	
	int select(int p, int r, int k, vector<int> &a){
		if(p == r)
			return a[p];
		int q = partition(p, r, a);
		int j = q - p + 1;
		if(k == j)
			return a[q];
		else if(k < j)
			return select(p, q, k, a);
		else
			return select(q + 1, r, k - j, a);
		
	}
	
	int partition(int i, int j, vector<int> &a){
		int x = a[i];
		while(i < j){
			while(i < j && a[j] <= x)
				j--;
			if(i < j)
				a[i++] = a[j];
			while(i < j && a[i] >= x)
				i++;
			if(i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		return i;
	}
};

int main(){
	Solution s;
	vector<int> nums = {1};
	cout << s.findKthLargest(nums, 1) << endl;
}