class Solution {
public:
    int lowerBound(vector<int>& nums, int l, int r, int target) {
        int ans = r + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int l, int r, int target) {
        int ans = l - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int low = lower - nums[i];
            int high = upper - nums[i];
            int left = lowerBound(nums, i + 1, n - 1, low);
            int right = upperBound(nums, i + 1, n - 1, high);
            if (left <= right) {
                ans += (right - left + 1);
            }
        }

        return ans;
    }
};
