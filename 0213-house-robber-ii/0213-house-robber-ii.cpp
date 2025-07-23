class Solution {
public:
int fun(vector<int>&arr){
    int n=arr.size();
    int p1=0;
    int p2=arr[0];
    for(int i=1;i<n;i++){
        int take=arr[i];
        if(i>1){
            take+=p1;
        }
        int nottake=p2;
        int curr=max(take,nottake);
        p1=p2;
        p2=curr;
    }
    return p2;
}
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int si=nums.size();
        if(si==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(fun(temp1),fun(temp2));
    }
};