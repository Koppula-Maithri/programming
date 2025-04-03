class Solution {
public:
void fun(vector<int>&premax,vector<int>&nums){
    int n=nums.size();
    premax[0]=nums[0];
    int maxi=nums[0];
    for(int i=1;i<n;i++){
        premax[i]=max(premax[i-1],nums[i]);
       
    }
}
void fun1(vector<int>&sufmax,vector<int>&nums){
    int n=nums.size();
    sufmax[n-1]=nums[n-1];
    int maxi=nums[n-1];
    for(int i=n-2;i>=0;i--){
        sufmax[i]=max(sufmax[i+1],nums[i]);
    }
}
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>premax(n);
        vector<int>sufmax(n);
        fun(premax,nums);
        fun1(sufmax,nums);
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans = max(((long long)(premax[i - 1] - nums[i]) * sufmax[i + 1]), ans);
        }
        return ans;
        
    }
};