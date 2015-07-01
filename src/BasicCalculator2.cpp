#include <vector>
using namespace std;

class Reader{
public:
	Reader(string _s) : s(_s), cur(0) {}
	
	int readInt(){
		if(cur >= s.length())
			return -1;
		int result = 0;
		while(cur < s.length() && s[cur] == ' ')
			cur++;
		while(cur < s.length() && s[cur] >= '0' && s[cur] <= '9'){
			result = result * 10 + s[cur] - '0';
			cur++;
		}
		return result;
	}
	
	char readOp(){
		while(cur < s.length() && s[cur] == ' ')
			cur++;
		if(cur >= s.length())
			return 0;
		if(s[cur] == '+' || s[cur] == '-' || s[cur] == '*' || s[cur] == '/'){
			return s[cur++];
		}
		return 0;
	}
private:
	string s;
	int cur;
};

class Solution{
public:
	int calculate(string s){
		Reader read(s);
		vector<int> nums;
		vector<char> ops;
		nums.push_back(read.readInt());
		char op;
		int tmp;
		while((op = read.readOp()) != 0){
			if(op == '*'){
				tmp = nums.back() * read.readInt();
				nums.pop_back();
				nums.push_back(tmp);
			}
			else if(op == '/'){
				tmp = nums.back() / read.readInt();
				nums.pop_back();
				nums.push_back(tmp);
			}
			else{
				ops.push_back(op);
				nums.push_back(read.readInt());
			}
		}
		int result = nums[0];
		for(int i = 0; i < ops.size(); i++){
			if(ops[i] == '+')
				result += nums[i + 1];
			else
				result -= nums[i + 1];
		}
		return result;
	}
};

