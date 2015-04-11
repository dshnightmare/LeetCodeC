#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
	string simplifyPath(string path){
		vector<string> s;
		auto i = path.begin();
		while(i != path.end()){
			i++;
			auto j = find(i, path.end(), '/');
			auto cur = string(i, j);
			if(!cur.empty() && cur != "."){
				if(cur == ".."){
					if(!s.empty())
						s.pop_back();
				}
				else{
					s.push_back(cur);
				}
			}
			i = j;
		}
		stringstream out;
		if(s.empty())
			out << '/';
		else{
			for(auto i : s)
				out << '/' << i;
		}
		return out.str();
	}
};

int main(){
	return 0;
}