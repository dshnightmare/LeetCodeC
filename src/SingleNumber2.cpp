class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0, two, three;
        for(int i = 0; i < n; i++){
            two |= (A[i] & one);
            one ^= A[i];
            three = ~(two & one);
            one &= three;
            two &= three;
        }
        return one;
    }
};

int main(){
	return 0;
}