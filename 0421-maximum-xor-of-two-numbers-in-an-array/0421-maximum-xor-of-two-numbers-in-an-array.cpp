class Solution {
public:
    Solution *c[2];
    
    Solution() {
        for(int i = 0; i < 2; i++) {
            c[i] = nullptr;
        }
    }

    void insert(int num) {
        Solution *r = this;
        for(int i = 31; i >= 0; i--) {
            int idx = (num >> i) & 1;  
            if(r->c[idx] == nullptr) {
                r->c[idx] = new Solution();
            }
            r = r->c[idx];
        }
    }

    int getMax(int num) {
        Solution *r = this;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; 
            if(r->c[1 - bit]) {
                maxNum |= (1 << i);  
                r = r->c[1 - bit];     
            } else {
                r = r->c[bit];
            }
        }
        return maxNum;
    }

    int findMaximumXOR(vector<int>& nums) {
        for(int num : nums) {
            insert(num);
        }
        int maxi = 0;
        for(int num : nums) {
            maxi = max(maxi, getMax(num));
        }
        return maxi;
    }
};
