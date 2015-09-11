#include <vector>
using namespace std;

class Solution{
public:
	int minCut(string s){
		int length = s.length();
		if(length == 0)
			return 0;
		vector<vector<bool>> pal(length, vector<bool>(length, false));
		vector<int> d(length, 0);
		for(int i = length - 1; i >= 0; i--){
			d[i] = length - i - 1;
			for(int j = i; j < length; j++){
				if(s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])){
					pal[i][j] = true;
					if(j == length - 1)
						d[i] = 0;
					else
						d[i] = min(d[i], d[j + 1] + 1);
				}
			}
		}
		return d[0];
	}
};

int main(){
	Solution s;
	cout << s.minCut("adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece") << endl;
}