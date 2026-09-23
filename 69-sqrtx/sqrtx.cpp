class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=1;
       int r =x/2;
        while(l<=r){
            int mid =l+ (r-l)/2;
            long long sqr = (long long) mid*mid;
            if(sqr==x){
                return mid;
            } else if(sqr<x){
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
    return  r;
    }
};