class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            int n=floor(log10(nums[i]))+1;
            if((n%2)==0){
                c++;
            }
        }
        return c;
    }
};