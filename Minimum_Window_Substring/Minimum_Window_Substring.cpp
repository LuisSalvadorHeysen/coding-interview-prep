// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = int(s.size()), m = int(t.size());
        if (m > n) return "";

        if (n == 1) {
            return s == t ? s : "";
        }

        map<char, int> cn_t, cn;
        for (char c : t) {
            ++cn_t[c];
        }

        int nunique = 0;
        for (auto it = cn_t.begin(); it != cn_t.end(); ++it) {
            if (it->second) ++nunique;
        }

        int done = 0, r = 0, l = 0, len = INT_MAX, best_r = -1, best_l = -1;
        while (r < n) {
            ++cn[s[r]];
            if (cn[s[r]] == cn_t[s[r]]) ++done;

            // cout << "DONE " << done << " " << m << " " << r << " " << cn[s[r]] << " " << cn_t[s[r]] << " " << s[r] << "\n";

            while (done >= nunique && l <= r) {

                // cout << "L " << s[l] << " " << l << " " << r << " " << cn[s[l]] << " " << cn_t[s[l]] << "\n";
                if (cn_t[s[l]] == 0 || cn[s[l]] > cn_t[s[l]]) {
                    cout << "TAKE " << l << "\n";
                    --cn[s[l]];
                    ++l;
                } else {
                    if (r - l + 1 < len) {
                        len = r - l + 1;
                        best_r = r;
                        best_l = l;
                    }

                    break;
                }
            }

            ++r;
        }

        // cout << len << "\n";
        // cout << best_l << " " << best_r << "\n";
        string ans(s.begin() + best_l, s.begin() + best_r + 1);
        return len == INT_MAX ? "" : ans;
    }
};
