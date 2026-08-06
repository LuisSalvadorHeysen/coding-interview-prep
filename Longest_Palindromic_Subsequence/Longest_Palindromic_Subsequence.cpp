class Solution {
public:
    int go(const string &s, int l, int r, vector<vector<int>> &memo) {
        if (l > r) {
            return 0;
        }

        if (l == r) {
            return 1;
        }

        if (memo[l][r] != -1) {
            return memo[l][r];
        }

        if (s[l] == s[r]) {
            return memo[l][r] = 2 + go(s, l + 1, r - 1, memo);
        } else {
            return memo[l][r] = max(go(s, l + 1, r, memo), go(s, l, r - 1, memo));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = int(s.size());

        vector<vector<int>> memo(n, vector<int>(n, -1));
        return go(s, 0, n - 1, memo);
    }
};
