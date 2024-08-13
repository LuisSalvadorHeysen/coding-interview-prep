// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        unordered_map<int, bool> vis;

        int ans = 0;

        for (int x : nums) st.insert(x);
        for (int x : st) {
            if (vis[x]) continue;
            vis[x] = true;

            int tmp = x - 1, curr = 1;
            while (st.count(tmp)) {
                ++curr;
                vis[tmp] = true;
                --tmp;
            }

            tmp = x + 1;
            while (st.count(tmp)) {
                ++curr;
                vis[tmp] = true;
                ++tmp;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};
