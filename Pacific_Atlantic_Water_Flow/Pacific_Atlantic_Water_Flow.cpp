// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#define ff first
#define ss second

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = int(heights.size()), m = int(heights[0].size());
        vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(m));

        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};

        auto ok = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int x = 0; x < 4; ++x) {
                    int ii = i + dx[x], jj = j + dy[x];
                    if (ok(ii, jj) && heights[ii][jj] >= heights[i][j]) {
                        adj[i][j].push_back({ii, jj});
                    }
                }
            }
        }

        vector<vector<int>> d1(n, vector<int>(m, -1)), d2(n, vector<int>(m, -1));
        queue<pair<int, int>> q1, q2;

        for (int i = 0; i < n; ++i) {
            q1.push({i, 0});
            d1[i][0] = 0;
            q2.push({i, m - 1});
            d2[i][m - 1] = 0;
        }


        for (int j = 0; j < m; ++j) {
            q1.push({0, j});
            d1[0][j] = 0;
            q2.push({n - 1, j});
            d2[n - 1][j] = 0;
        }

        while (!q1.empty()) {
            pair<int, int> node = q1.front();
            q1.pop();

            for (pair<int, int> nbr : adj[node.ff][node.ss]) {
                if (d1[nbr.ff][nbr.ss] == -1) {
                    d1[nbr.ff][nbr.ss] = 1 + d1[node.ff][node.ss];
                    q1.push(nbr);
                }
            }
        }

        while (!q2.empty()) {
            pair<int, int> node = q2.front();
            q2.pop();

            for (pair<int, int> nbr : adj[node.ff][node.ss]) {
                if (d2[nbr.ff][nbr.ss] == -1) {
                    d2[nbr.ff][nbr.ss] = 1 + d2[node.ff][node.ss];
                    q2.push(nbr);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (d1[i][j] != -1 && d2[i][j] != -1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
