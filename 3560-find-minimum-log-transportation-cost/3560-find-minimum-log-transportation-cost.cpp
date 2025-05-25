class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        int diff1=n-k;
        int diff2=m-k;
        long long c=0;
        if(diff1>0){
            c=c+(long long)(diff1)*k;
        }
        if(diff2>0){
            c=c+(long long)(diff2)*k;
        }
        return c;

    }
};