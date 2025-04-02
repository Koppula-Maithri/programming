class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=1;
        int i=0;
        int n=s.length();
        int j=0;
        if(n==0){
            return 0;
        }
        unordered_map<char,int>mpp;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                if(mpp[s[j]]>=i){
                    i=mpp[s[j]]+1;
                }
            }
            maxlen=max(maxlen,j-i+1);
            mpp[s[j]]=j;
            j++;
        }

        return maxlen;

        
    }
};