// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
        reverse(intervals.begin(), intervals.end());

        vector<vector<int>> ans = {intervals.back()};
        intervals.pop_back();

        auto overlap = [&](const vector<int> &a, const vector<int> &b) -> bool {
            return a[1] >= b[0];
        };

        auto merge = [&](const vector<int> &a, const vector<int> &b) -> vector<int> {
            return {a[0], max(a[1], b[1])};
        };
        
        while (!intervals.empty()) {
            vector<int> curr = intervals.back();
            intervals.pop_back();

            if (overlap(ans.back(), curr)) {
                ans.back() = merge(ans.back(), curr);
            } else {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};
