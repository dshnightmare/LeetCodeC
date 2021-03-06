using namespace std;

class Solution{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
		int a = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0;
		int b = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
		return (C - A) * (D - B) + (G - E) * (H - F) - a * b;
	}
};