class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        int f2 = 0, f3 = 0, f5 = 0;
        vector<int> f(n);
        f[0]=1;
        for(int i=1;i<n;i++){
            f[i] = min(f[f2]*2, min(f[f3]*3,f[f5]*5));
            if(f[i]==f[f2]*2) f2++;
            if(f[i]==f[f3]*3) f3++;
            if(f[i]==f[f5]*5) f5++;
        }
        return f[n-1];
    }
};