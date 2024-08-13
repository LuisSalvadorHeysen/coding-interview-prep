// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        while (s[0] == ' ') {
            s.erase(s.begin());
        }

        long long sign = 1;
        if (s[0] == '-') {
            sign = -1;
            s.erase(s.begin());
        }

        else if (s[0] == '+') {
            s.erase(s.begin());
        }

        while (s[0] == '0') s.erase(s.begin());

        auto valid = [&](char c) {
            int val = int(c - '0');
            return 0 <= val && val <= 9;
        };

        long long ans = 0, mul = 1;
        string other = "";
        for (char c : s) {
            if (valid(c)) {
                other.push_back(c);
            }

            else break;
        }

        reverse(other.begin(), other.end());
        for (int i = 0; i < int(other.size()); ++i) {
            if (!valid(other[i])) break;
            long long curr = (long long) (other[i] - '0');
            ans += sign * curr * mul;
            mul *= 10LL;

            if (10LL * mul > 1e12) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            if (ans > INT_MAX) {
                ans = INT_MAX;
                break;
            } else if (ans < INT_MIN) {
                ans = INT_MIN;
                break;
            }
        }


        return ans;
    }
};
