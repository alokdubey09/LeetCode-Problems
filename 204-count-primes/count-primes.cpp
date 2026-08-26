class Solution {
public:
    int countPrimes(int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n<=2) return 0;

        vector<char> prime(n/2, true);
        // prime[0]=prime[1]=false;
        // prime[2]=1;
        int res=1;
        for(long long p=3; p*p<n;p+=2){
            if(prime[p/2]){
                for(long long j=p*p;j<n;j+=2*p){
                    prime[j/2]=false;
                }
            }
        }
        for(int p=3;p<n;p+=2){
            if(prime[p/2]){
                res++;
            }
        }
        return res;
    }
};