// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool helper(string s, vector<string> &words, map<string, bool> &dp) {
        if (dp.find(s) != dp.end()) return dp[s];
        if (s == "") {
            return true;
        }

        for (int i = 0; i < int(words.size()); ++i) {
            string curr = words[i];
            if (int(curr.size()) > int(s.size())) continue;
            string pref(s.begin(), s.begin() + curr.size());
            if (pref != curr) continue;

            string suff(s.begin() + curr.size(), s.end());
            bool res = helper(suff, words, dp);
            if (res) return dp[s] = true;
        }

        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> dp;
        return helper(s, wordDict, dp);
    }
};
