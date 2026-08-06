// https://leetcode.com/problems/sequential-digits/description/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;
        for (int len = 1; len <= 9; ++len) {
            string x = "";
            for (char d = '1'; d < '1' + len; ++d) {
                x.push_back(d);
            }

            for (int offset = 0; offset <= 9 - len; ++offset) {
                for (char &c : x) c += offset;
                int curr = stoi(x);
                if (low <= curr && curr <= high) nums.push_back(curr);
                for (char &c : x) c -= offset;
            }
        }

        return nums;
    }
};
