#include <stack>
using namespace std;

class Queue{
public:
	void push(int x){
		in.push(x);
	}
	
	void pop(){
		if(out.empty()){
			while(!in.empty()){
				out.push(in.top());
				in.pop();
			}
		}
		out.pop();
	}
	
	int peek(){
		if(out.empty()){
			while(!in.empty()){
				out.push(in.top());
				in.pop();
			}
		}
		return out.top();
	}
	
	bool empty(){
		in.empty() && out.empty();
	}
private:
	stack<int> in;
	stack<int> out;
};