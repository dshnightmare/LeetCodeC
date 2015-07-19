#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	int maxProfit(int k, vector<int> &prices){
		int size = prices.size();
		if(k >= size / 2)
			return fullProfit(prices);
		vector<int> sell(k + 1, 0), buy(k + 1, INT_MIN);
		for(int i = 0; i < size; i++){
			for(int j = k; j > 0; j--){
				sell[j] = max(sell[j], buy[j] + prices[i]);
				buy[j] = max(buy[j], sell[j - 1] - prices[i]);
			}
		}
		return sell[k];
	}
	
	int fullProfit(vector<int> &prices){
		int ret = 0;
		for(int i = 1; i < prices.size(); i++)
			if(prices[i] > prices[i - 1])
				ret += prices[i] - prices[i - 1];
		return ret;
	}
};

int main(){
	vector<int> prices = {3,3,5,0,0,3,1,4};
	Solution s;
	cout << s.fullProfit(prices) << endl;
	cout << s.maxProfit(2, prices) << endl;
	
}