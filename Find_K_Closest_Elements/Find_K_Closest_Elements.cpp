// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int d1 = abs(a - x), d2 = abs(b - x);
            if (d1 == d2) {
                return a < b;
            }

            else return d1 < d2;
        });

        vector<int> ans(arr.begin(), arr.begin() + k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
