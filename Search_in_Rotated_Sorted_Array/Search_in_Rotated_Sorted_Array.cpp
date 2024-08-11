// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = int(nums.size());
        int lo = -1, hi = n, mid = (lo + hi) / 2;

        auto test_pivot = [&](int idx) {
            return nums[idx] > nums.back();
        };

        while (lo < mid && mid < hi) {
            if (test_pivot(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
            mid = (lo + hi) / 2;
        }

        auto it1 = lower_bound(nums.begin(), nums.begin() + mid, target);
        auto it2 = lower_bound(nums.begin() + mid + 1, nums.end(), target);

        int i1 = int(it1 - nums.begin());
        int i2 = int(it2 - nums.begin());

        if (i1 < n && nums[i1] == target) return i1;
        if (i2 < n && nums[i2] == target) return i2;
        return -1;
    }
};
