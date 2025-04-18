class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string s="11";
        int count=1;
        for(int i=3;i<=n;i++){
            s=s+'M';
            string t="";
            for(int j=1;j<s.size();j++){
                if(s[j-1]!=s[j]){
                    t+=to_string(count);
                    t+=s[j-1];
                    count=1;
                }
                else{
                    count++;
                }
            }
            s=t;

        }
        return s;
        
    }
};