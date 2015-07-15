class Solution{
public:
	int countDigitOne(int n){
		if(n <= 0)
			return 0;
		long long iFactor = 1;
		long long iLow, iHigh, iCur;
		long long total = 0;
		while(n / iFactor != 0){
			iLow = n - (n / iFactor) * iFactor;
			iCur = (n / iFactor) % 10;
			iHigh = n / (iFactor * 10);
			if(iCur == 0)
				total += iHigh * iFactor;
			else if(iCur == 1)
				total += iHigh * iFactor + iLow + 1;
			else
				total += (iHigh + 1) * iFactor;
			iFactor *= 10;
		}
		return total;
	}
};