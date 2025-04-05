class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<(1<<n);i++){
            int xor1=0;
            for(int j=0;j<n;j++){
                if((1<<j)&i){
                xor1=xor1^nums[j];
                }  
            }
            sum+=xor1;
        }
        return sum;
    }
};