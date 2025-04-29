class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long t=0;
        int n=nums.size();
        int i=0;
        int j=0;
        long long sum=0;
        long long c=0;
        while(j<n){
            sum=sum+nums[j];
            t=sum*(j-i+1);
            while(i<=j && t>=k){
                sum=sum-nums[i];
                 i++;
                t=sum*(j-i+1);
            }
            c+=(j-i+1);
            j++;
        }
    return c;
    }
};