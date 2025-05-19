class Solution {
public:
int fun(vector<int>& nums, int k){
 int n=nums.size();
        map<int,int>mpp;
        int i=0,j=0;
        int count=0;
        while(j<n){
              mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]<=0){
                    mpp.erase(nums[i]);
                }
                i=i+1;
            }
           
                count+=(j-i+1);
            
            j++;
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return fun(nums,k)-fun(nums,k-1);
    }
};