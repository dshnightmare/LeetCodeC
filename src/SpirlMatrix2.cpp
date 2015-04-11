#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > generateMatrix(int n){
		vector<vector<int> > result(n);
		for(int i = 0; i < n; i++)
			result[i].resize(n);
		fill(result, 0, n - 1, 1);
		return result;
	}
	
	void fill(vector<vector<int> > &matrix, int top, int bottom, int begin){
		if(top > bottom)
			return;
		if(top == bottom)
			matrix[top][top] = begin;
		else{
			for(int i = top; i < bottom; i++)
				matrix[top][i] = begin++;
			for(int i = top; i < bottom; i++)
				matrix[i][bottom] = begin++;
			for(int i = bottom; i > top; i--)
				matrix[bottom][i] = begin++;
			for(int i = bottom; i > top; i--)
				matrix[i][top] = begin++;
		}
		fill(matrix, top + 1, bottom - 1, begin);
	}
};

int main(){
	return 0;
}