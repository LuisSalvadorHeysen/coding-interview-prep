// https://leetcode.com/problems/generate-parentheses/

class Solution {
private:
    void helper(string &s, int val, int n, vector<string> &ans) {
        if (val < 0) return;

        if (int(s.size()) == n) {
            if (val == 0) ans.push_back(s);
            return;
        }

        s.push_back('(');
        helper(s, val + 1, n, ans);
        s.pop_back();
        s.push_back(')');
        helper(s, val - 1, n, ans);
        s.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        helper(s, 0, 2 * n, ans);
        return ans;
    }
};
