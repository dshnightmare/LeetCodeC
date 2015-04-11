using namespace std;

class Solution{
public:
	bool isNumber(string s){
		enum InputType {
			INVALID,
			SPACE,
			SIGN,
			DIGIT,
			DOT,
			EXPONENT,
			NUM_INPUTS
		};
		const int transTable[][NUM_INPUTS] = {
			{-1, 0, 3, 1, 2, -1},     //开始状态，前导空格
			{-1, 8, -1, 1, 4, 5},     //整数
			{-1, -1, -1, 4, -1, -1},  //点
			{-1, -1, -1, 1, 2, -1},   //符号
			{-1, 8, -1, 4, -1, 5},    //小数
			{-1, -1, 6, 7, -1, -1},   //指数e
			{-1, -1, -1, 7, -1, -1},  //e后符号
			{-1, 8, -1, 7, -1, -1},   //e后整数
			{-1, 8, -1, -1, -1, -1}   //后导空格
		};
		
		int state = 0;
		for(auto i : s){
			InputType in = INVALID;
			if(isspace(i))
				in = SPACE;
			else if(i == '+' || i == '-')
				in = SIGN;
			else if(isdigit(i))
				in = DIGIT;
			else if(i == '.')
				in = DOT;
			else if(i == 'e' || i == 'E')
				in = EXPONENT;
			
			state = transTable[state][in];
			if(state == -1)
				return false;
		}
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};

int main(){
	return 0;
}