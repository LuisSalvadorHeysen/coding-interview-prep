// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = int(s.size());

        for (char c = 'A'; c <= 'Z'; ++c) {
            vector<int> pref(n + 1);
            for (int i = 0; i < n; ++i) {
                pref[i + 1] = pref[i] + (s[i] == c);
            }

            auto cn = [&](int lo, int hi) {
                return pref[hi + 1] - pref[lo];
            };

            for (int l = 0; l < n; ++l) {
                int lo = l - 1, hi = n, mid = (lo + hi) / 2;
                while (lo < mid && mid < hi) { 
                    if (cn(l, mid) + k >= mid - l + 1) {
                        lo = mid;
                    } else {
                        hi = mid;
                    }

                    mid = (lo + hi) / 2;
                }

                ans = max(ans, mid - l + 1);
            }
        }

        return ans;
    }
};
