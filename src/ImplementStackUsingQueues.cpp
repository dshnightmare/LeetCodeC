#include <queue>
using namespace std;

class Stack{
public:
	void push(int x){
		int size = que.size();
		que.push(x);
		while(size--){
			que.push(que.front());
			que.pop();
		}
	}
	
	void pop(){
		que.pop();
	}
	
	int top(){
		return que.front();
	}
	
	bool empty(){
		return que.empty();
	}
private:
	queue<int> que;
};